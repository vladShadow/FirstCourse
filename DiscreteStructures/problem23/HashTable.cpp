#include "HashTable.h"
#include "RBTree.h"
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;



int HashTable::hashFn(int key) {
    double a;
    int hash = ht.size() * modf(0.618034 * key, &a);
    return hash;
}
void HashTable::add(int key) {
    int index = hashFn(key);
    ht[index].addNode(key);
}
Node* HashTable::find(int key) {
    int index = hashFn(key);
    return ht[index].find(key);
}
void HashTable::erase() {
    for (int i = 0; i < ht.size(); i++) {
        ht[i].erase();
    }
}
void HashTable::remove(int key) {
    int index = hashFn(key);
    ht[index].removeNode(key);
}
