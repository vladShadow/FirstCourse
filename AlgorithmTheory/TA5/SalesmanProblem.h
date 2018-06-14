#ifndef TA5_SALESMANPROBLEM_H
#define TA5_SALESMANPROBLEM_H
#include <iostream>
#include <vector>
using namespace std;

class SalesmanProblem {
private:
    int alpha = 2;
    int beta = 4;
    static constexpr double ro = 0.4;
    int antNum = 30;
    int nodeNum = 200;
    int minL = 500;
    int bestLength = 5000;
    vector<int> bestPath;
    double startFer = 0.1;
    struct Verge {
        double feromon;
        double deltaFer;
        double length;
        pair<int, int> nodes;
        Verge(double f, double l, int n1, int n2): feromon(f), deltaFer(0), length(l), nodes(n1, n2) {};
        void updateFer() {
            feromon = (1-ro)*feromon + deltaFer;
            deltaFer = 0;
        }
    };
    vector<vector<Verge*>> graph;
    struct Ant {
        int curr;
        vector<int> visited;
        vector<double> chances;
        vector<int> prevPath;
        int prevLength;
        Ant(int c): curr(c), visited(), chances(), prevPath(), prevLength(5000) {visited.push_back(c);}
    };
    vector<Ant> ants;
public:
    SalesmanProblem(): bestPath(), graph(), ants() {}
    void fillGraph();
    void spawnAnts();
    void runAnts(int);
    void printRes();
};


#endif //TA5_SALESMANPROBLEM_H
