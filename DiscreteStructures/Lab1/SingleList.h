#ifndef LAB1_SINGLE_H
#define LAB1_SINGLE_H
#include <iostream>
using namespace std;

class SingleList {
private:
    struct Node{
        int data;
        Node* next;
    };
    Node* first;
public:
    SingleList(): first() {}
    ~SingleList();
    struct Iterator {
        Node* curr;
        Iterator(Node*);
        Node& operator *();
        Node* operator ->();
        Node* operator ++();
        Node* operator --();
        bool operator ==(const Iterator& other) const;
        bool operator !=(const Iterator& other) const;
    };
    Iterator begin();
    void push(int);
    void insert(int ,int);
    void remove(int);
    int size();
    string toString();
    void show() {cout << toString() << endl;}
    void sort();
};

#endif //LAB1_SINGLE_H
