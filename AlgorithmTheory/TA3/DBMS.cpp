#include "DBMS.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


void DBMS::add(int key, int value) {
    //size
    fin.open(index, ios::binary);
    fin.seekg(0, ios::end);
    int size = fin.tellg()/10;
    fin.seekg(0, ios::beg);

    //binary search
    vector<int> d = delta(size);
    char str[5];
    int pos = (d[0]-1)*10;
    int n = 0;
    while (d[n] != 0) {
        if (pos < 0) pos = 0;
        fin.seekg(pos);
        fin.read(str, 5);
        if (key < atoi(str)) {
            pos -= 10 * d[++n];
        } else {
            pos += 10 * d[++n];
        }
    }
    if (key < atoi(str)) pos -= 10;
    if (pos < 0) pos = 0;
    fin.seekg(pos+5, ios::beg);
    str[4] = ' ';
    fin.read(str, 4);
    fin.close();
    int blockPos = atoi(str)*blockSize*10;

    //reading a block
    fin.open(base, ios::binary);
    fin.seekg(blockPos);
    char block[10*blockSize];
    fin.read(block, 10*blockSize);
    fin.close();

    //changing block
    char note[10];
    sprintf(note, "%d    ", key);
    for (int i = 0; i < 4; i++) {
        note[5+i] = to_string(value)[i];
    }
    if (!isblank(block[(blockSize-1)*10])) {
        reBase();
        add(key, value);
        return;
    }
    vector<char[10]> vec(blockSize-1);
    for (int i = 0; i < blockSize-1; i++) {
        for (int j = 0; j < 9; j++) {
            vec[i][j] = block[i*10 + j];
        }
    }
    vector<char[10]> res(blockSize);
    for (int i = 0; i < blockSize-1; i++) {
        for (int j = 0; j < 5; j++) {
            str[j] = vec[i][j];
        }
        if (key < atoi(str) || isblank(str[0])) {
            for (int k = 0; k < i; k++) {
                for (int t = 0; t < 10; t++)
                    res[k][t] = vec[k][t];
            }
            for (int t = 0; t < 10; t++)
                res[i][t] = note[t];
            for (int k = i; k < blockSize-1; k++) {
                for (int t = 0; t < 10; t++)
                    res[k+1][t] = vec[k][t];
            }
            if (i == 0) reIndex();
            break;
        }
        if (key == atoi(str)) throw invalid_argument("There already is such key in data base");
    }

    for (int i = 0; i < blockSize; i++) {
        for (int j = 0; j < 9; j++) {
            block[i*10 + j] = res[i][j];
        }
        block[i*10 + 9] = '\n';
    }
    // writing a block
    fout.open(base, ios::in | ios::binary);
    fout.seekp(blockPos, ios::beg);
    fout.write(block, 10*blockSize);
    fout.close();

}



void DBMS::remove(int key) {
    //size
    fin.open(index, ios::binary);
    fin.seekg(0, ios::end);
    int size = fin.tellg()/10;
    fin.seekg(0, ios::beg);

    //binary search
    vector<int> d = delta(size);
    char str[5];
    int pos = (d[0]-1)*10;
    int n = 0;
    while (d[n] != 0) {
        if (pos < 0) pos = 0;
        fin.seekg(pos);
        fin.read((char *) str, 5);
        if (key < atoi(str)) {
            pos -= 10 * d[++n];
        } else {
            pos += 10 * d[++n];
        }
    }
    if (key < atoi(str)) pos -= 10;
    if (pos < 0) pos = 0;
    fin.seekg(pos+5);
    str[4] = ' ';
    fin.read((char*)str, 4);
    fin.close();
    int blockPos = atoi(str)*blockSize*10;



    //reading a block
    fin.open(base, ios::binary);
    fin.seekg(blockPos);
    char block[10*blockSize];
    fin.read((char*)block, 10*blockSize);
    fin.close();

    //changing block

    vector<char[10]> vec(blockSize);
    for (int i = 0; i < blockSize; i++) {
        for (int j = 0; j < 9; j++) {
            vec[i][j] = block[i*10 + j];
        }
    }
    bool ok = false;
    vector<char[10]> res(blockSize);
    for (int i = 0; i < blockSize-1; i++) {
        for (int j = 0; j < 5; j++) {
            str[j] = vec[i][j];
        }
        if (key == atoi(str)) {
            for (int k = 0; k < i; k++) {
                for (int t = 0; t < 9; t++)
                    res[k][t] = vec[k][t];
            }
            for (int k = i; k < blockSize-1; k++) {
                for (int t = 0; t < 9; t++)
                    res[k][t] = vec[k+1][t];
            }
            for (int t = 0; t < 9; t++) res[blockSize-1][t] = ' ';
            for (int i = 0; i < blockSize; i++) {
                for (int j = 0; j < 9; j++) block[i*10 + j] = res[i][j];
                block[i*10 + 9] = '\n';
            }
            if (i == 0) reIndex();
            ok = true;
            break;
        }
    }
    if (!ok) throw invalid_argument("There's no such note in data base");
    // writing a block
    fout.open(base, ios::in | ios::binary);
    fout.seekp(blockPos, ios::beg);
    fout.write(block, 10*blockSize);
    fout.close();

    if (isblank(block[0])) reBase();
}



void DBMS::change(int key, int value) {
    //size
    fin.open(index, ios::binary);
    fin.seekg(0, ios::end);
    int size = fin.tellg()/10;
    fin.seekg(0, ios::beg);

    //binary search
    vector<int> d = delta(size);
    char str[5];
    int pos = (d[0]-1)*10;
    int n = 0;
    while (d[n] != 0) {
        if (pos < 0) pos = 0;
        fin.seekg(pos);
        fin.read((char *) str, 5);
        if (key < atoi(str)) {
            pos -= 10 * d[++n];
        } else {
            pos += 10 * d[++n];
        }
    }
    if (key < atoi(str)) pos -= 10;
    if (pos < 0) pos = 0;
    fin.seekg(pos+5);
    str[4] = ' ';
    fin.read((char*)str, 4);
    fin.close();
    int blockPos = atoi(str)*blockSize*10;

    //reading a block
    fin.open(base, ios::binary);
    fin.seekg(blockPos);
    char block[10*blockSize];
    fin.read((char*)block, 10*blockSize);
    fin.close();

    //changing block
    vector<char[10]> vec(blockSize);
    for (int i = 0; i < blockSize; i++) {
        for (int j = 0; j < 9; j++) {
            vec[i][j] = block[i*10 + j];
        }
    }
    bool ok = false;
    for (int i = 0; i < blockSize-1; i++) {
        for (int j = 0; j < 5; j++) {
            str[j] = vec[i][j];
        }
        if (key == atoi(str)) {
            for (int j = 5; j < 9; j++) {
                vec[i][j] = to_string(value)[j-5];
            }
            for (int i = 0; i < blockSize; i++) {
                for (int j = 0; j < 9; j++) block[i*10 + j] = vec[i][j];
                block[i*10 + 9] = '\n';
            }
            ok = true;
            break;
        }
    }
    if (!ok) throw invalid_argument("There's no such key in data base");
    // writing a block
    fout.open(base, ios::in | ios::binary);
    fout.seekp(blockPos, ios::beg);
    fout.write(block, 10*blockSize);
    fout.close();
}


int DBMS::find(int key) {
    //size
    fin.open(index, ios::binary);
    fin.seekg(0, ios::end);
    int size = fin.tellg()/10;
    fin.seekg(0, ios::beg);

    //binary search
    vector<int> d = delta(size);
    char str[5];
    int pos = (d[0]-1)*10;
    int n = 0;
    while (d[n] != 0) {
        if (pos < 0) pos = 0;
        fin.seekg(pos);
        fin.read((char *) str, 5);
        if (key < atoi(str)) {
            pos -= 10 * d[++n];
        } else {
            pos += 10 * d[++n];
        }
    }
    if (key < atoi(str)) pos -= 10;
    if (pos < 0) pos = 0;
    fin.seekg(pos+5);
    str[4] = ' ';
    fin.read((char*)str, 4);
    fin.close();
    int blockPos = atoi(str)*blockSize*10;

    //reading a block
    fin.open(base, ios::binary);
    fin.seekg(blockPos);
    char block[10*blockSize];
    fin.read((char*)block, 10*blockSize);
    fin.close();

    //searching in block
    vector<char[10]> vec(blockSize);
    for (int i = 0; i < blockSize; i++) {
        for (int j = 0; j < 9; j++) {
            vec[i][j] = block[i*10 + j];
        }
    }

    for (int i = 0; i < blockSize-1; i++) {
        for (int j = 0; j < 5; j++) {
            str[j] = vec[i][j];
        }
        if (key == atoi(str)) {
            char val[4];
            for (int j = 0; j < 4; j++) {
                val[j] = vec[i][j+5];
            }
            return atoi(val);
        }
    }
    throw invalid_argument("There's no such key in data base");
}


void DBMS::fill() {
    fout.open(base, ios::binary);
    char str[5];
    for (int i = 1; i <= 10000; i++) {
        sprintf(str, "%d   ", i*3);
        if (!str[4]) str[4] = ' ';
        fout.write(str, 5);
        sprintf(str, "%d", rand()%9000+1000);
        fout.write(str, 4);
        fout.write("\n", 1);
        // white space
        if (i%(int)(blockSize*fillPerc) == 0) {
            for (int j = 0; j < blockSize-blockSize*fillPerc; j++) {
                fout.write((char*)"         \n", 10);
            }
        }
    }
    fout.close();
    reIndex();
}


void DBMS::reIndex() {
    fin.open(base, ios::binary);
    fout.open(index, ios::binary);
    //size
    fin.seekg(0, ios::end);
    int size = fin.tellg()/10;
    fin.seekg(0, ios::beg);
    //writing index
    char str[5];
    for (int i = 0; i < size/blockSize; i++) {
        fin.seekg(i*10*blockSize);
        fin.read(str, 5);
        fout.write(str, 5);
        sprintf(str, "%d   ", i);
        fout.write(str, 4);
        fout.write("\n", 1);
    }
    fin.close();
    fout.close();
}


void DBMS::reBase() {
    // size
    fin.open(base, ios::binary);
    fin.seekg(0, ios::end);
    int size = fin.tellg()/10;
    fin.seekg(0, ios::beg);

    // reading data base
    char note[10];
    vector<char[10]> vec(size);
    int noteNum = 0;
    for (int i = 0; i < size; i++) {
        fin.seekg(i * 10);
        fin.read(note, 10);
        if (!isblank(note[0])) {
            for (int k = 0; k < 9; k++) vec[noteNum][k] = note[k];
            noteNum++;
        }
    }
    fin.close();
    //changing blockSize
    blockSize = noteNum/(1000*fillPerc);
    // filling base
    fout.open(base, ios::binary);
    for (int i = 1; i <= noteNum; i++) {
        fout.write(vec[i-1], 9);
        fout.write("\n", 1);
        // white space
        if (i%(int)(blockSize*fillPerc) == 0 && i != 1) {
            for (int j = 0; j < blockSize-blockSize*fillPerc; j++) {
                fout.write("         \n", 10);
            }
        }
    }
    int num = noteNum%(int)(blockSize*fillPerc);
    int spaces = (num == 0) ? 0 : blockSize - num;
    for (int i = 0; i < spaces; i++) {
        fout.write("         \n", 10);
    }
}

vector<int> DBMS::delta(int num) {
    vector<int> delta(num);
    int power = 1;
    int i = 0;
    do {
        int half = power;
        power <<= 1;
        delta[i] = (num + half) / power;
    } while (delta[i++] != 0);
    return delta;
}

int DBMS::menuItem()
{
    int variant;
    cout << "Chose variant\n" << endl;
    cout << "1. add note\n"
         << "2. remove note\n"
         << "3. change note\n"
         << "4. find note\n"
         << "5. exit\n" << endl;
    cin >> variant;
    return variant;
}