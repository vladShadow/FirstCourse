#include "SalesmanProblem.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;



void SalesmanProblem::fillGraph() {
    for (int i = 0; i < nodeNum; i++) {
        vector<Verge*> vec;
        graph.push_back(vec);
    }
    for (int i = 0; i < nodeNum; i++) {
        for (int j = i+1; j < nodeNum; j++) {
            Verge* verge = new Verge(startFer, rand()%45+5, i, j);
            graph[i].push_back(verge);
            graph[j].push_back(verge);
        }
    }
}

void SalesmanProblem::spawnAnts() {
    for (int i = 0; i < antNum; i++) {
        Ant ant(i*2);
        ants.push_back(ant);
    }
}

void SalesmanProblem::runAnts(int num) {
    for (int it = 0; it < num; it++) {
        for (int ant = 0; ant < antNum; ant++) {
            int start = ants[ant].curr;
            for (int node = 0; node < nodeNum; node++) {
                double sum = 0;
                for (int way = 0; way < nodeNum-1; way++) {
                    int next = graph[ants[ant].curr][way]->nodes.first != ants[ant].curr ?
                               graph[ants[ant].curr][way]->nodes.first : graph[ants[ant].curr][way]->nodes.second;
                    bool vis = false;
                    for (int check = 0; check < ants[ant].visited.size(); check++) {
                        if (ants[ant].visited[check] == next) {
                            vis = true;
                            ants[ant].chances.push_back(0);
                            break;
                        }
                    }
                    if (!vis) {
                        ants[ant].chances.push_back(pow(graph[ants[ant].curr][way]->feromon, alpha) /
                                pow(graph[ants[ant].curr][way]->length, beta));
                        sum += ants[ant].chances[way];
                    }
                }
                int next;
                int bigNum;
                if (sum == 0) {
                    next = start;
                    for (int i = 0; i < nodeNum - 1; i++) {
                        if (graph[start][i]->nodes.first == ants[ant].curr) {
                            bigNum = i;
                            break;
                        }
                    }
                }
                else {
                    double biggest = 0;
                    bigNum = 0;
                    for (int way = 0; way < nodeNum - 1; way++) {
                        ants[ant].chances[way] = ants[ant].chances[way] / sum;
                        if (ants[ant].chances[way] > biggest) {
                            biggest = ants[ant].chances[way];
                            bigNum = way;
                        }
                    }
                    next = graph[ants[ant].curr][bigNum]->nodes.first != ants[ant].curr ?
                               graph[ants[ant].curr][bigNum]->nodes.first :
                               graph[ants[ant].curr][bigNum]->nodes.second;
                }
                for (int check = 1; check < ants[ant].prevPath.size(); check++) {
                    if(ants[ant].prevPath[check-1] == next) {
                        graph[ants[ant].curr][bigNum]->deltaFer += minL / ants[ant].prevLength;
                        break;
                    }
                }

                ants[ant].visited.push_back(next);
                ants[ant].chances.clear();
                ants[ant].curr = next;
            }
            ants[ant].prevPath = ants[ant].visited;
            ants[ant].visited = {ants[ant].curr};
            ants[ant].prevLength = 0;
            for (int i = 0; i < nodeNum; i++) {
                for (int j = 0; j < nodeNum; j++) {
                    if (graph[ants[ant].prevPath[i]][j]->nodes.first == ants[ant].prevPath[i+1] ||
                            graph[ants[ant].prevPath[i]][j]->nodes.second == ants[ant].prevPath[i+1]) {
                        ants[ant].prevLength += graph[ants[ant].prevPath[i]][j]->length;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < nodeNum; i++) {
            for (int j = i; j < nodeNum-1; j++) {
                graph[i][j]->updateFer();
            }
        }
        for (int ant = 0; ant < antNum; ant++) {
            if (ants[ant].prevLength < bestLength) {
                bestLength = ants[ant].prevLength;
                bestPath = ants[ant].prevPath;
            }
        }
    }
}

void SalesmanProblem::printRes() {
    cout << "The best path is:";
    for (int i = 0; i < bestPath.size(); i++) {
        cout << " " << to_string(bestPath[i]);
        if (i != bestPath.size()-1) {
            cout << " ->";
        }
    }
    cout << endl;
    cout << "The length of path is: " << to_string(bestLength) << endl;
}