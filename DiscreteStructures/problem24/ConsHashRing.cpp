#include "ConsHashRing.h"
#include <iostream>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

double ConsHashRing::hashFn(int key) {
    double a;
    double hash = size * modf(0.618034 * key, &a);
    return hash;
};

void ConsHashRing::addServer(double hash) {
    Server serv(hash);
    for (auto it = servers.begin(); it != servers.end(); it++) {
        if ((*it).hash > serv.hash) {
            for (auto itNode = (*it).nodes.begin(); itNode != (*it).nodes.end(); itNode++) {
                if ((*itNode).hash <= serv.hash) {
                    serv.nodes.push_back((*itNode));
                    (*it).nodes.erase(itNode);
                    itNode = (*it).nodes.begin();
                }
            }
            servers.emplace(it, serv);
            return;
        }
    }
    for (auto itNode = servers[0].nodes.begin(); itNode != servers[0].nodes.end(); itNode++) {
        if ((*itNode).hash <= serv.hash) {
            serv.nodes.push_back((*itNode));
            servers[0].nodes.erase(itNode);
        }
    }
    servers.push_back(serv);
}


void ConsHashRing::removeServer(double hash) {
    if (servers.size() == 1) throw "The last server cannot be removed";
    for (auto it = servers.begin(); it != servers.end(); it++) {
        if ((*it).hash == hash) {
            it++;
            Server* next = &*it;
            it--;
            for (auto itNode = (*it).nodes.begin(); itNode != (*it).nodes.end(); itNode++) {
                next->nodes.push_back(*itNode);
            }
            servers.erase(it);
            return;
        }
    }
    throw "There's no such server on the ring";
}

void ConsHashRing::add(int key, int value) {
    Node node(key, value);
    for (auto it = servers.begin(); it != servers.end(); it++) {
        if (node.hash <= (*it).hash) {
            (*it).nodes.push_back(node);
            return;
        }
    }
    servers[0].nodes.push_back(node);
}

void ConsHashRing::remove(int key) {
    double hash = hashFn(key);
    for (auto it = servers.begin(); it != servers.end(); it++) {
        if (hash <= (*it).hash) {
            for (auto itNode = (*it).nodes.begin(); itNode != (*it).nodes.end(); itNode++) {
                if (key == (*itNode).key) {
                    (*it).nodes.erase(itNode);
                    return;
                }
            }
            throw "No such node on server";
        }
    }
    for (auto itNode = servers[0].nodes.begin(); itNode != servers[0].nodes.end(); itNode++) {
        if (key == (*itNode).key) {
            servers[0].nodes.erase(itNode);
            return;
        }
    }
    throw "No such node on server";
}

ConsHashRing::Node* ConsHashRing::find(int key) {
    double hash = hashFn(key);
    for (auto it = servers.begin(); it != servers.end(); it++) {
        if (hash < (*it).hash) {
            for (auto itNode = (*it).nodes.begin(); itNode != (*it).nodes.end(); itNode++) {
                if (key == (*itNode).key) return (&*itNode);
            }
            throw "No such node on server";
        }
    }
    for (auto itNode = servers[0].nodes.begin(); itNode != servers[0].nodes.end(); itNode++) {
        if (key == (*itNode).key) return (&*itNode);
    }
    throw "No such node on server";
}

string ConsHashRing::printServerNodes(double hash) {
    string res = "";
    for (auto it = servers.begin(); it != servers.end(); it++) {
        if ((*it).hash == hash) {
            for (auto itNode = (*it).nodes.begin(); itNode != (*it).nodes.end(); itNode++) {
                res += to_string((*itNode).key) + " ";
            }
            return res;
        }
    }
    throw "There's no such server on the ring";
}

string ConsHashRing::printServers() {
    string res = "";
    for (auto it = servers.begin(); it != servers.end(); it++) {
        res += to_string((*it).hash) + " ";
    }
    return res;
}
