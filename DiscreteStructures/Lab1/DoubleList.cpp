#include <iostream>
#include "DoubleList.h"
using namespace std;


DoubleList::~DoubleList() {
    while (first != nullptr)
    {
        Node *curr = first;
        first = first->next;
        delete curr;
    }
}


DoubleList::Iterator::Iterator(Node* node): curr(node) {}
DoubleList::Node& DoubleList::Iterator::operator *() {return *curr;}
DoubleList::Node* DoubleList::Iterator::operator ->() {return curr;}
DoubleList::Node* DoubleList::Iterator::operator ++() {
    if (!curr) throw range_error("Iterator have reached the end of the list");
    curr = curr->next;
    return curr;
}
DoubleList::Node* DoubleList::Iterator::operator --() {
    if (!curr) throw range_error("Iterator have reached the begin of the list");
    curr = curr->prev;
    return curr;
}
bool DoubleList::Iterator::operator ==(const Iterator& other) const { return curr == other.curr; }
bool DoubleList::Iterator::operator !=(const Iterator& other) const { return curr != other.curr; }

DoubleList::Iterator DoubleList::begin() {
    DoubleList::Iterator firstIt(first);
    return firstIt;
}
DoubleList::Iterator DoubleList::end() {
    DoubleList::Iterator lastIt(last);
    return lastIt;
}


void DoubleList::push(int data) {
    Node *node = new Node;
    node->next = nullptr;
    node->data = data;
    if (first != nullptr){
        node->prev = last;
        last->next = node;
        last = node;
    }
    else{
        node->prev = nullptr;
        first = last = node;
    }
}

void DoubleList::insert(int data ,int position) {
    if (position < 0) throw invalid_argument("Position argument value is negative");
    Node *node = new Node;
    node->data = data;
    if (position != 0) {
        int currPos = 1;
        Node *curr = first->next;
        while (currPos != position - 1) {
            curr = curr->next;
            currPos++;
            if (curr == nullptr) throw invalid_argument("Position argument value is better than list length");
        }
        node->next = curr->next;
        node->prev = curr;
        if (curr->next != nullptr) {
            curr->next->prev = node;
        }
        curr->next = node;
        return;
    }
    node->next = first;
    node->prev = nullptr;
    first->next->prev = node;
    first = node;
}

int DoubleList::remove(int position) {
    if (position < 0) throw invalid_argument("Position argument value is negative");
    Node *node = first;
    for (int i = 0; i < position; i++) {
        node = node->next;
        if (node == nullptr) throw invalid_argument("Position argument value is better than list length");
    }
    if (node->next != nullptr) {
        node->next->prev = node->prev;
    }
    else {
        last = node->prev;
    }
    if (node->prev != nullptr) {
        node->prev->next = node->next;
    }
    else {
        first = node->next;
    }
    //int data = node->data;
    delete node;
    return node->data;
}

int DoubleList::size() {
    int size = 0;
    Node *curr = first;
    while (curr != nullptr){
        size++;
        curr = curr->next;
    }
    return size;
}

string DoubleList::toString(){
    if (!first) return "";
    string result;
    Node* curr = first;
    while (curr != nullptr) {
        result += to_string(curr->data) + " ";
        curr = curr->next;
    }
    return result;
}

void DoubleList::sort() {
    Node *curr;
    bool done = false;
    while (!done) {
        curr = first;
        done = true;
        while (curr->next != nullptr) {
            if (curr->data < curr->next->data) {
                done = false;
                if (curr == first) first = curr->next;
                else curr->prev->next = curr->next;
                if (curr->next == last) last = curr;
                else curr->next->next->prev = curr;

                curr->next->prev = curr->prev;
                curr->prev = curr->next;
                curr->next = curr->next->next;
                curr->prev->next = curr;
            }
            else curr = curr->next;
        }
    }
}

