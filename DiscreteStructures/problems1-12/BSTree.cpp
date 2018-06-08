#include "BSTree.h"
#include <iostream>
#include <vector>
#include "math.h"
#include <sstream>
using namespace std;


void BSTree::deleteTree(Node* node) {
    if (node != nullptr) {
        deleteTree(node->left);
        deleteTree(node->right);
        node = nullptr;
        delete node;
    } else return;
}

BSTree::Iterator::Iterator(Node* node): curr(node) {}
BSTree::Node& BSTree::Iterator::operator *() {return *curr;}
BSTree::Node* BSTree::Iterator::operator ->() {return curr;}
BSTree::Node* BSTree::Iterator::operator ++() {
    if (!curr) throw range_error("Iterator have reached the end of the tree");
    if (curr->right) {
        curr = curr->right;
        while (curr->left) curr = curr->left;
        return curr;
    }
    if (curr->parent->left == curr) {
        curr = curr->parent;
        return curr;
    }
    while (curr->parent && (curr->parent->left != curr)) curr = curr->parent;
    curr = curr->parent;
    return curr;
}
BSTree::Node* BSTree::Iterator::operator --() {
    if (!curr) throw range_error("Iterator have reached the begin of the tree");
    if (curr->left) {
        curr = curr->left;
        while (curr->right) curr = curr->right;
        return curr;
    }
    if (curr->parent->right == curr) {
        curr = curr->parent;
        return curr;
    }
    while (curr->parent && (curr->parent->right != curr)) curr = curr->parent;
    curr = curr->parent;
    return curr;
}
bool BSTree::Iterator::operator ==(const Iterator& other) const { return curr == other.curr; }
bool BSTree::Iterator::operator !=(const Iterator& other) const { return curr != other.curr; }

BSTree::Iterator BSTree::begin() {
    Node* first = root;
    while (first->left != nullptr) first = first->left;
    BSTree::Iterator firstIt(first);
    return firstIt;
}
BSTree::Iterator BSTree::end() {
    Node* last = root;
    while (last->right != nullptr) last = last->right;
    BSTree::Iterator lastIt(last);
    return lastIt;
}


void BSTree::add(int data, Node*& node, Node* prev) {
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


BSTree::Node* BSTree::remove(int data, Node*& node) {
    if (!node) throw invalid_argument("There's no such element in the tree");
    if (data < node->data) {
        remove(data, node->left);
        return root;
    }
    if (data > node->data) {
        remove(data, node->right);
        return root;
    }
    Node* sub = findSubstitute(node);
    if (sub) {
        node->data = sub->data;
        remove (sub->data, sub);
    }
    else {
        if (node == node->parent->left) node->parent->left = nullptr;
        else node->parent->right = nullptr;
        node = nullptr;
    }
    return root;
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
        result += to_string(node->data);
        result += " " + toString(node->right);
        return result;
    }
    return "";
}

// PROBLEMS 1-12
void BSTree::fill() {
    /*
    cout << "You can fill the tree by yourself. Otherwise it will be filled randomly." << endl;
    string input;
    getline(cin, input);
    if (input.empty())
     */
        for (int i = 0; i < 15; i++)
            add(rand()%200-100);
    /*
    else {
        stringstream ss;
        ss.str(input);
        int value;
        while (ss >> value) {
            if (!(value>-100 || value<100)) throw invalid_argument("Values must be in diapason [-99, 99]");
            add(value);
        }
    }
     */
}
// problem 1
void BSTree::insertAliquotN(int n) {
    for (int i = 0; i < 10; i++){
        int num = rand()%200-100;
        if (num%n == 0) add(num);
    }
}
void BSTree::removeAliquotN(int n) {
    for (Iterator it = begin(); it != end(); ) {
        if (it->data % n == 0) {
            int data = it->data;
            if (!it->left && !it->right) --it;
            remove(data, root);
        }
        else ++it;
    }
}
// problem 2
void BSTree::insertOdd() {
    for (int i = 0; i < 10; i++){
        int num = rand()%200-100;
        if (num%2 != 0) add(num);
    }
}
void BSTree::removeOdd() {
    for (Iterator it = begin(); it != end();) {
        if (it->data % 2 != 0) {
            int data = it->data;
            if (!it->left && !it->right) --it;
            remove(data, root);
        }
        else ++it;
    }
}
// problem 3
void BSTree::insertBetterThenN(int n) {
    for (int i = 0; i < 10; i++){
        int num = rand()%200-100;
        if (num > n) add(num);
    }
}
void BSTree::removeBetterThenN(int n) {
    for (Iterator it = begin(); it != end();) {
        if (it->data > n) {
            int data = it->data;
            if (!it->left && !it->right) --it;
            remove(data, root);
        }
        else ++it;
    }
}
// problem 4
void BSTree::insertLessThenN(int n) {
    for (int i = 0; i < 10; i++){
        int num = rand()%200-100;
        if (num < n) add(num);
    }
}
void BSTree::removeLessThenN(int n) {
    for (Iterator it = begin(); it != end();) {
        if (it->data < n) {
            int data = it->data;
            if (!it->left && !it->right) ++it;
            remove(data, root);
        }
        else ++it;
    }
}
// problem 5
void BSTree::insertChosen(vector<int> vec) {
    for (int i = 0; i < 10; i++){
        int num = rand()%200-100;
        for (int j = 0; j < vec.size(); j++) {
            if (num == vec[j]) add(num);
        }
    }
}
void BSTree::removeChosen(vector<int> vec) {
    for (Iterator it = begin(); it != end();) {
        bool is = false;
        for (int j = 0; j < vec.size(); j++) {
            if (it->data == vec[j]) is = true;
        }
        if (is) {
            int data = it->data;
            if (!it->left && !it->right) --it;
            remove(data, root);
        }
        else ++it;
    }
}
// problem 6
void BSTree::insertPrime() {
    for (int i = 0; i < 10; i++){
        int num = rand()%200-100;
        bool is = true;
        for (int j = 2; j <= num/2; j++) {
            if (num%j == 0) is = false;
        }
        if (is) add(num);
    }
}
void BSTree::removePrime() {
    for (Iterator it = begin(); it != end();) {
        if (it == nullptr) it = begin();
        bool is = true;
        for (int j = 2; j <= it->data/2; j++) {
            if (it->data%j == 0) is = false;
        }
        if (is) {
            int data = it->data;
            if (!it->left && !it->right) --it;
            remove(data, root);
        }
        else ++it;
    }
}
// problem 7
void BSTree::insertComposite() {
    for (int i = 0; i < 10; i++){
        int num = rand()%200-100;
        bool is = false;
        for (int j = 2; j <= num/2; j++) {
            if (num%j == 0) is = true;
        }
        if (is) add(num);
    }
}
void BSTree::removeComposite() {
    for (Iterator it = begin(); it != end();) {
        if (it == nullptr) it = begin();
        bool is = false;
        for (int j = 2; j <= it->data/2; j++) {
            if (it->data%j == 0) is = true;
        }
        if (is) {
            int data = it->data;
            if (!it->left && !it->right) --it;
            remove(data, root);
        }
        else ++it;
    }
}
// problem 8
void BSTree::insertFromXToY(int x, int y) {
    if (x > y) throw invalid_argument("First argument is better than second!");
    for (int i = 0; i < 10; i++){
        int num = rand()%200-100;
        if (num > x && num < y) add(num);
    }
}
void BSTree::removeFromXToY(int x, int y) {
    if (x > y) throw invalid_argument("First argument is better than second!");
    for (Iterator it = begin(); it != end();) {
        if (it == nullptr) it = begin();
        if (it->data > x && it->data < y) {
            int data = it->data;
            if (!it->left && !it->right) --it;
            remove(data, root);
        }
        else ++it;
    }
}
// problem 9
void BSTree::insertDigitSumBetterThenN(int n) {
    for (int i = 0; i < 10; i++){
        int num = rand()%200-100;
        if (abs(num%10 + num/10) > n) add(num);
    }
}
void BSTree::removeDigitSumBetterThenN(int n) {
    for (Iterator it = begin(); it != end();) {
        if (it == nullptr) it = begin();
        if (abs(it->data%10 + it->data/10) > n) {
            int data = it->data;
            if (!it->left && !it->right) --it;
            remove(data, root);
        }
        else ++it;
    }
}
// problem 10
void BSTree::insertDigitSumLessThenN(int n) {
    for (int i = 0; i < 10; i++){
        int num = rand()%200-100;
        if (abs(num%10 + num/10) < n) add(num);
    }
}
void BSTree::removeDigitSumLessThenN(int n) {
    for (Iterator it = begin(); it != end();) {
        if (it == nullptr) it = begin();
        if (abs(it->data%10 + it->data/10) < n) {
            int data = it->data;
            if (!it->left && !it->right) --it;
            remove(data, root);
        }
        else ++it;
    }
}
// problem 11
void BSTree::insertDigitSumFromXToY(int x, int y) {
    for (int i = 0; i < 10; i++){
        int num = rand()%200-100;
        if (abs(num%10 + num/10) > x && abs(num%10 + num/10) < y) add(num);
    }
}
void BSTree::removeDigitSumFromXToY(int x, int y) {
    for (Iterator it = begin(); it != end();) {
        if (it == nullptr) it = begin();
        if (abs(it->data%10 + it->data/10) > x && abs(it->data%10 + it->data/10) < y) {
            int data = it->data;
            if (!it->left && !it->right) --it;
            remove(data, root);
        }
        else ++it;
    }
}
// problem 12
void BSTree::insertIntegerSqrT() {
    for (int i = 0; i < 10; i++){
        int num = rand()%200-100;
        float temp =  sqrt(abs(num));
        if (temp-(int)temp == 0) add(num);
    }
}
void BSTree::removeIntegerSqrT() {
    for (Iterator it = begin(); it != end();) {
        if (it == nullptr) it = begin();
        float temp =  sqrt(abs(it->data));
        if (temp-(int)temp == 0) {
            int data = it->data;
            if (!it->left && !it->right) --it;
            remove(data, root);
        }
        else ++it;
    }
}