#include <iostream>
#include "SingleList.h"
using namespace std;



SingleList::~SingleList() {
    while (first != nullptr)
    {
        Node *curr = first;
        first = first->next;
        delete curr;
    }
}

SingleList::Iterator::Iterator(Node* node): curr(node) {}
SingleList::Node& SingleList::Iterator::operator *() {return *curr;}
SingleList::Node* SingleList::Iterator::operator ->() {return curr;}
SingleList::Node* SingleList::Iterator::operator ++() {
    if (!curr) throw range_error("Iterator have reached the end of the list");
    curr = curr->next;
    return curr;
}
bool SingleList::Iterator::operator ==(const Iterator& other) const { return curr == other.curr; }
bool SingleList::Iterator::operator !=(const Iterator& other) const { return curr != other.curr; }

SingleList::Iterator SingleList::begin() {
    SingleList::Iterator firstIt(first);
    return firstIt;
}


void SingleList::push(int data) {
    Node *node = new Node;
    node->data = data;
    node->next = nullptr;
    if (first != nullptr){
        Node *curr = first;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = node;
    }
    else first = node;
}

void SingleList::insert(int data ,int position) {
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
        curr->next = node;
        return;
    }
    node->next = first;
    first = node;
}

void SingleList::remove(int position){
    if (position < 0) throw invalid_argument("Position argument value is negative");
    if (position == 0) {
        delete first;
        first = first->next;
        return;
    }
    Node *node = first;
    for (int i = 0; i < position-1; i++) {
        node = node->next;
        if (node->next == nullptr) throw invalid_argument("Position argument value is better than list length");
    }
    Node* temp = node->next->next;
    delete node->next;
    node->next = temp;
}

int SingleList::size() {
    int size = 0;
    Node *curr = first;
    while (curr != nullptr){
        size++;
        curr = curr->next;
    }
    return size;
}

string SingleList::toString() {
    if (!first) return "";
    string result;
    Node* curr = first;
    while (curr != nullptr) {
        result += to_string(curr->data) + " ";
        curr = curr->next;
    }
    return result;
}

void SingleList::sort() {
    Node *curr;
    Node *prev;
    bool done = false;
    while (!done) {
        curr = first;
        prev = nullptr;
        done = true;
        while (curr->next != nullptr)
            if (curr->data < curr->next->data) {
                done = false;
                if (curr != first) {
                    prev->next = curr->next;
                    curr->next = curr->next->next;
                    prev->next->next = curr;

                    prev = prev->next;
                    curr = prev->next;
                }
                else {
                    first = curr->next;
                    curr->next = curr->next->next;
                    first->next = curr;

                    prev = first;
                    curr = first->next;
                }
            }
            else {
                if (curr != first) {
                    prev = prev->next;
                    curr = prev->next;
                }
                else {
                    prev = first;
                    curr = first->next;
                }
            }
    }
}





