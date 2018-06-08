#ifndef LAB1_DOUBLE_H
#define LAB1_DOUBLE_H
#include <iostream>
using namespace std;

class DoubleList {
private:
    struct Node{
        int data;
        Node* next;
        Node* prev;
    };
    Node* first;
    Node* last;
public:
    DoubleList(): first(), last() {}
    ~DoubleList();
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
    Iterator end();
    void push(int);
    void insert(int ,int);
    int remove(int);
    int size();
    string toString();
    void show() {cout << toString() << endl;}
    void sort();
};


#endif //LAB1_DOUBLE_H
