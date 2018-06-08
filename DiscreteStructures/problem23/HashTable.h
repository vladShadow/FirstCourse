#ifndef PROBLEM23_HASHTABLE_H
#define PROBLEM23_HASHTABLE_H
#include <iostream>
#include <cmath>
#include <vector>
#include "RBTree.h"

using namespace std;

class HashTable {
    vector<RBTree> ht;
    int hashFn(int);
public:
    HashTable(): ht(10) {}
    HashTable(int num): ht(num) {}


    void add(int);
    void remove(int);
    void erase();
    Node* find(int);
    int size() {return ht.size();}
};


#endif //PROBLEM23_HASHTABLE_H
