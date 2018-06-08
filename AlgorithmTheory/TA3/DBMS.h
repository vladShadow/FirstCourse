#ifndef TA3_DBMS_H
#define TA3_DBMS_H
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


class DBMS {
    ifstream fin;
    ofstream fout;
    string base;
    string index;
    int blockSize = 20;
    float fillPerc = 0.5;
public:
    DBMS(string base, string index):
            base(base), index(index) {};
    void add(int, int);
    void remove(int);
    void change(int, int);
    int find(int);
    void fill();
    void reIndex();
    void reBase();
    vector<int> delta(int);
    int menuItem();
};


#endif //TA3_DBMS_H
