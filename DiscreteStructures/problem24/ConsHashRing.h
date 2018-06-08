#ifndef PROBLEM24_CONSHASHRING_H
#define PROBLEM24_CONSHASHRING_H
#include <iostream>
#include <map>
#include <vector>
using namespace std;


class ConsHashRing {
    static double hashFn(int);
    static constexpr double size = 10;

    struct Node {
        int key;
        int value;
        double hash;
        Node(int key, int value): key(key), value(value), hash(hashFn(key)) {}
    };

    struct Server {
        double hash;
        vector<Node> nodes;
        Server(double hash): hash(hash<=size?hash:hash-size*(int)(hash/size)) {}
    };

    vector<Server> servers;
public:
    ConsHashRing() {servers.push_back(Server(5));}
    ConsHashRing(double hash) {servers.push_back(Server(hash));}
    void addServer(double);
    void removeServer(double);
    void add(int, int);
    void remove(int);
    Node* find(int);
    string printServerNodes(double);
    string printServers();
};




#endif //PROBLEM24_CONSHASHRING_H
