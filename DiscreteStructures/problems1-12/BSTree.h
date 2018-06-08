#ifndef PROBLEMS_BSTREE_H
#define PROBLEMS_BSTREE_H
#include <iostream>
#include <vector>
using namespace std;

class BSTree{
private:
    struct Node{
        int data;
        Node *left, *right, *parent;
    };
    Node* root;
public:
    BSTree(): root() {}
    ~BSTree() {deleteTree(root);}
    void deleteTree(Node*);
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

    void add(int data) {add(data, root, nullptr);}
    void add(int, Node*&, Node*);

    Node* remove(int data) {return remove(data, root);}
    Node* remove(int, Node*&);
    Node* findSubstitute(Node*);

    string toString() {return toString(root);}
    string toString(Node*);
    void show() {cout << toString() << endl;}
// PROBLEMS 1-12
    void fill();
// problem 1
    void insertAliquotN(int);
    void removeAliquotN(int);
// problem 2
    void insertOdd();
    void removeOdd();
// problem 3
    void insertBetterThenN(int);
    void removeBetterThenN(int);
// problem 4
    void insertLessThenN(int);
    void removeLessThenN(int);
// problem 5
    void insertChosen(vector<int>);
    void removeChosen(vector<int>);
// problem 6
    void insertPrime();
    void removePrime();
// problem 7
    void insertComposite();
    void removeComposite();
// problem 8
    void insertFromXToY(int, int);
    void removeFromXToY(int, int);
// problem 9
    void insertDigitSumBetterThenN(int);
    void removeDigitSumBetterThenN(int);
// problem 10
    void insertDigitSumLessThenN(int);
    void removeDigitSumLessThenN(int);
// problem 11
    void insertDigitSumFromXToY(int, int);
    void removeDigitSumFromXToY(int, int);
// problem 12
    void insertIntegerSqrT();
    void removeIntegerSqrT();
};

#endif //PROBLEMS_H
