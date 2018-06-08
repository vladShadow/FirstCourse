#ifndef LAB3_GRAPH_H
#define LAB3_GRAPH_H
#include <iostream>
#include <vector>
using namespace std;

class Graph {
    vector<vector<int>> nodeList;
public:
    Graph(): nodeList() {}
    ~Graph();

    void addNode(int);
    void addNode(int, int);
    void addNode(int, vector<int>);

    void addVerge(int, int);
    void addVerges(int, vector<int>);


    void removeNode(int);
    void removeNodes(vector<int>);

    void removeVerge(int, int);
    void removeVerges(int, vector<int>);

    void show() {cout << "Node   Data   Verges\n" << toString() << endl;}
    string toString();

    vector<int> NNumbering();
    void NNumbering(vector<int>&, int&, int);
};

#endif //LAB3_GRAPH_H
