#include "SalesmanProblem.h"
#include <iostream>
#include <vector>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    SalesmanProblem sman;
    sman.fillGraph();
    sman.spawnAnts();
    sman.runAnts(10);
    sman.printRes();
    return 0;
}