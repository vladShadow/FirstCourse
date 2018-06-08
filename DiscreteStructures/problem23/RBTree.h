#ifndef PROBLEM23_REDBLACKTREE_H
#define PROBLEM23_REDBLACKTREE_H

enum Color {RED, BLACK, DOUBLE_BLACK};

struct Node {
    int data;
    int color;
    Node *left, *right, *parent;
    Node(int data): data(data), color(RED),
    left(nullptr), right(nullptr), parent(nullptr) {};
};

class RBTree {
    Node *root;

protected:
    int getColor(Node *&);
    void setColor(Node *&, int);

    Node* getMin(Node *);
    Node* getMax(Node *);

    void rotateLeft(Node *&);
    void rotateRight(Node *&);

    void fixInsert(Node *&);
    void fixDelete(Node *&);

    Node* insertBST(Node *&, Node *&);
    Node* deleteBST(Node *&, int);
public:
    RBTree(): root(nullptr) {};
    void addNode(int);
    void removeNode(int);
    void erase();
    Node* find(int);
};


#endif //PROBLEM23_REDBLACKTREE_H
