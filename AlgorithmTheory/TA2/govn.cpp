
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int hashFn(vector<int>, int);
void add(vector<int>&, int);
int find(vector<int>, int);
/*
int main() {
    const int NUM = 100;
    vector<int> ht(NUM), rnd;
    for (int i = 0; i < NUM; i++) {
        rnd.push_back(rand()%NUM);
    }
    for (int i = 0; i < NUM; i++) {
        add(ht, rnd[i]);
    }

    for (int i = 0; i < NUM; i++) {
        cout << find(ht, rnd[i]) << " ";

    }
    return 0;
}

int hashFn(vector<int> ht, int key) {
    double* i;
    int hash = ht.size() * modf(0.618034 * key, i);
    return hash;
}
void add(vector<int> &ht, int key) {
    int index = hashFn(ht, key);
    int n = 1;
    while (ht[index]) {
        index += n*n++;
        index = index/ht.size();
    }
    ht[index] = key;
}
int find(vector<int> ht, int key) {
    int index = hashFn(ht, key);    cout << index << " ";
    int n = 1;
    while (key != ht[index]) {
        index += n*n++;
        index = index%ht.size();
    }
    cout << index << "k ";
    return index;
}
*/