#include "BSTree.h"
using namespace std;


void BSTree::deleteTree(Node* node) {
    if (node != nullptr) {
        deleteTree(node->left);
        deleteTree(node->right);
        node = nullptr;
        delete node;
    } else return;
}

void BSTree::add(char data, Node*& node, Node* prev) {
    if (node == nullptr) {
        node = new Node;
        node->data = data;
        node->left = node->right = nullptr;
        node->parent = prev;
        return;
    }
    if (data <= node->data) add(data, node->left, node);
    else add(data, node->right, node);
}

void BSTree::remove(char data, Node*& node) {
    if (!node) throw invalid_argument("There's no such element in the tree");
    if (data < node->data) {
        remove(data, node->left);
        return;
    }
    if (data > node->data) {
        remove(data, node->right);
        return;
    }
    Node* sub = findSubstitute(node);

    if (sub) {
        if (sub->data <= node->data) {
            sub->parent->right = sub->left;
            if (sub->left) sub->left->parent = sub->parent;
        }
        else {
            sub->parent->left = sub->right;
            if (sub->right) sub->right->parent = sub->parent;
        }
        sub->left = (node->left != sub) ? node->left : nullptr;
        sub->right = (node->right != sub) ? node->right : nullptr;
        sub->parent = node->parent;
    }

    if (node->left) node->left->parent = sub;
    if (node->right) node->right->parent = sub;

    if (node == node->parent->left) node->parent->left = sub;
    else node->parent->right = sub;
}

BSTree::Node* BSTree::findSubstitute(Node* node) {
    if(node->left) {
        node = node->left;
        while (node->right != nullptr) node = node->right;
        return node;
    }
    if (node->right) {
        node = node->right;
        while (node->left) node = node->left;
        return node;
    }
}

string BSTree::toString(Node* node) {
    if (node != nullptr) {
        string result = toString(node->left);
        result.push_back(node->data);
        result += " " + toString(node->right);
        return result;
    }
    return "";
}

char BSTree::min() {
    if (root == nullptr) throw "The tree is empty";
    Node* node = root;
    while (node->left != nullptr) node = node->left;
    return node->data;
}
char BSTree::max(){
    if (root == nullptr) throw "The tree is empty";
    Node* node = root;
    while (node->right != nullptr) node = node->right;
    return node->data;
}


int BSTree::insertEorCalculateSum() {
    if (!checkByData('E', root)) {
        add('E');
        cout << "'E' inserted" << endl;
    }
    else {
        int sum = calculateSum(root);
        cout << "Tree elements' sum: " << sum << endl;
        return sum;
    }
}
bool BSTree::checkByData(char data, Node* node) {
    if (node == nullptr) return false;
    if (node->data == data || checkByData(data, node->left) ||
        checkByData(data, node->right)) return true;
}
int BSTree::calculateSum(Node* node) {
    if (node != nullptr) return node->data +
                calculateSum(node->left) + calculateSum(node->right);
    else return 0;
}


