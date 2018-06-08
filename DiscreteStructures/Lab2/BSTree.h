#ifndef LAB2_TREE_H
#define LAB2_TREE_H
#include <iostream>
using namespace std;


class BSTree{
private:
    struct Node{
        char data;
        Node *left, *right, *parent;
    };
    Node* root;
public:
    BSTree(): root() {}
    ~BSTree() {deleteTree(root);}
    void deleteTree(Node*);

    void add(char data) {add(data, root, nullptr);}
    void add(char, Node*&, Node*);

    void remove(char data) {remove(data, root);}
    void remove(char, Node*&);
    Node* findSubstitute(Node*);

    string toString() {return toString(root);}
    string toString(Node*);
    void show() {cout << toString() << endl;}

    char min();
    char max();

    int insertEorCalculateSum();
    bool checkByData(char, Node*);
    int calculateSum(Node*);
};

#endif //LAB2_TREE_H
