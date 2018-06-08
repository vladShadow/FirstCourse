#include "Graph.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


Graph::~Graph() {
    nodeList.clear();
}

void Graph::addNode(int data) {
    vector<int> vec;
    vec.push_back(data);
    nodeList.push_back(vec);
}
void Graph::addNode(int data, int verge) {
    if (verge < 0 || verge >= nodeList.size())
        throw invalid_argument("Verge number is negative or there`s no such node in the graph");
    vector<int> vec;
    vec.push_back(data);
    vec.push_back(verge);
    nodeList.push_back(vec);
    nodeList[verge].push_back(nodeList.size()-1);
}
void Graph::addNode(int data, vector<int> verges) {
    vector<int> vec(verges.size()+1);
    vec[0] = data;
    copy(verges.begin(), verges.end(), ++vec.begin());
    nodeList.push_back(vec);
    for (int i = 0; i < verges.size(); i++){
        if (verges[i] < 0 || verges[i] >= nodeList.size())
            throw invalid_argument("Verge number is negative or there`s no such node in the graph");
        nodeList[verges[i]].push_back(nodeList.size()-1);
    }
}


void Graph::addVerge(int node, int verge) {
    if (node < 0 || node >= nodeList.size())
        throw invalid_argument("Node number is negative or there`s no such node in the graph");
    if (verge < 0 || verge >= nodeList.size())
        throw invalid_argument("Verge number is negative or there`s no such node in the graph");
    nodeList[node].push_back(verge);
    nodeList[verge].push_back(node);
}
void Graph::addVerges(int node, vector<int> verges) {
    if (node < 0 || node >= nodeList.size())
        throw invalid_argument("Node number is negative or there`s no such node in the graph");
    for (int i = 0; i < verges.size(); i++)
        if (verges[i] < 0 || verges[i] >= nodeList.size())
            throw invalid_argument("Verge number is negative or there`s no such node in the graph");
    for (int i = 0; i < verges.size(); i++)
        Graph::addVerge(node, verges[i]);
}


void Graph::removeNode(int node) {
    if (node < 0 || node >= nodeList.size())
        throw invalid_argument("Node number is negative or there`s no such node in the graph");
    for (int i = 1; i < nodeList[node].size(); i++) {
        int verge = nodeList[node][i];
            for (int j = 1; j < nodeList[verge].size(); j++) {
                if (nodeList[verge][j] == node) nodeList[verge].erase(nodeList[verge].begin() + j);
                break;
            }
    }
    nodeList.erase(nodeList.begin() + node);
    for (int i = 0; i < nodeList.size(); i++)
        for (int j = 1; j < nodeList[i].size(); j++) {
            if (nodeList[i][j] > node) nodeList[i][j]--;
        }
}
void Graph::removeNodes(vector<int> nodes) {
    for (int i = 0; i < nodes.size(); i++)
        Graph::removeNode(nodes[i]-i);
}


void Graph::removeVerge(int node, int verge) {
    if (node < 0 || node >= nodeList.size())
        throw invalid_argument("Node number is negative or there`s no such node in the graph");
    if (verge < 0 || verge >= nodeList.size())
        throw invalid_argument("Verge number is negative or there`s no such node in the graph");
    nodeList[node].erase(find(++nodeList[node].begin(), nodeList[node].end(), verge));
    nodeList[verge].erase(find(++nodeList[verge].begin(), nodeList[verge].end(), node));
}
void Graph::removeVerges(int node, vector<int> verges) {
    for (int i = 0; i < verges.size(); i++)
        Graph::removeVerge(node, verges[i]);
}


string Graph::toString() {
    string res = "";
    for (int i = 0; i < nodeList.size(); i++) {
        res += to_string(i) + "      " + to_string(nodeList[i][0]) + "      ";
        for (int j = 1; j < nodeList[i].size(); j++)
            res += to_string(nodeList[i][j]) + " ";
        res += "\n";
    }
    return res;
}


vector<int> Graph::NNumbering() {
    if (nodeList.empty()) throw "Graph is empty";
    vector<int> vec(nodeList.size());
    int num = nodeList.size();

    NNumbering(vec, num, 0);
    for (int i = 0; i < vec.size(); i++)
        if (vec[i] == 0) NNumbering(vec, num, i);
            return vec;
}
void Graph::NNumbering(vector<int> &vec, int &num, int curr) {
    vec[curr] = num--;
    for (int i = 1; i < nodeList[curr].size(); i++)
        if (vec[nodeList[curr][i]] == 0) NNumbering(vec, num, nodeList[curr][i]);
}