#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"
#include <vector>
#include "Graph.h"
using namespace std;


TEST_CASE("AddNode") {
    Graph graph;
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    REQUIRE(graph.toString() == "0      1      \n"
                                "1      2      \n"
                                "2      3      \n");
    graph.addNode(4, 2);
    graph.addNode(5, {0,3});
    graph.addNode(6, {0,2,4});
    REQUIRE(graph.toString() == "0      1      4 5 \n"
                                "1      2      \n"
                                "2      3      3 5 \n"
                                "3      4      2 4 \n"
                                "4      5      0 3 5 \n"
                                "5      6      0 2 4 \n");
    REQUIRE_THROWS(graph.addNode(1, 10));
    REQUIRE_THROWS(graph.addNode(1, vector<int> {1, -2}));
}

TEST_CASE("AddVerge") {
    Graph graph;
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addNode(4);
    graph.addNode(5);
    graph.addNode(6);
    graph.addVerge(0, 1);
    graph.addVerge(0, 2);
    REQUIRE(graph.toString() == "0      1      1 2 \n"
                                "1      2      0 \n"
                                "2      3      0 \n"
                                "3      4      \n"
                                "4      5      \n"
                                "5      6      \n");
    graph.addVerges(3, vector<int> {0,1});
    graph.addVerges(4, vector<int> {2,3,5});
    REQUIRE(graph.toString() == "0      1      1 2 3 \n"
                                "1      2      0 3 \n"
                                "2      3      0 4 \n"
                                "3      4      0 1 4 \n"
                                "4      5      2 3 5 \n"
                                "5      6      4 \n");
    REQUIRE_THROWS(graph.addVerge(0, -2));
    REQUIRE_THROWS(graph.addVerge(-5, 3));
    REQUIRE_THROWS(graph.addVerges(0, vector<int> {20, 3}));
    REQUIRE_THROWS(graph.addVerges(10, vector<int> {0, 3}));
}

TEST_CASE("RemoveNode") {
    Graph graph;
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addNode(4, 0);
    graph.addNode(5);
    graph.addNode(6, 4);
    graph.show();
    graph.removeNode(3);
    graph.removeNode(0);
    REQUIRE(graph.toString() == "0      2      \n"
                                "1      3      \n"
                                "2      5      3 \n"
                                "3      6      2 \n");
    graph.removeNodes(vector<int> {0,1});
    REQUIRE(graph.toString() == "0      5      1 \n"
                                "1      6      0 \n");
    REQUIRE_THROWS(graph.removeNode(10));
    REQUIRE_THROWS(graph.removeNode(-10));
    REQUIRE_THROWS(graph.removeNodes(vector<int> {-10, 0}));
    REQUIRE_THROWS(graph.removeNodes(vector<int> {10, 0}));
}

TEST_CASE("RemoveVerge") {
    Graph graph;
    graph.addNode(1);
    graph.addNode(2, 0);
    graph.addNode(3);
    graph.addNode(4);
    graph.addNode(5, {0,2,3});
    graph.addNode(6, {1,2,4});
    graph.removeVerge(5, 1);
    graph.removeVerge(4, 5);
    REQUIRE(graph.toString() == "0      1      1 4 \n"
                                "1      2      0 \n"
                                "2      3      4 5 \n"
                                "3      4      4 \n"
                                "4      5      0 2 3 \n"
                                "5      6      2 \n");
    graph.removeVerges(4, vector<int> {0, 3});
    REQUIRE(graph.toString() == "0      1      1 \n"
                                "1      2      0 \n"
                                "2      3      4 5 \n"
                                "3      4      \n"
                                "4      5      2 \n"
                                "5      6      2 \n");
    REQUIRE_THROWS(graph.removeVerge(-1, 0));
    REQUIRE_THROWS(graph.removeVerge(10, 0));
    REQUIRE_THROWS(graph.removeVerge(1, -2));
    REQUIRE_THROWS(graph.removeVerge(1, 10));
    REQUIRE_THROWS(graph.removeVerges(-1, vector<int> {1, 1}));
    REQUIRE_THROWS(graph.removeVerges(10, vector<int> {1, 1}));
    REQUIRE_THROWS(graph.removeVerges(1, vector<int> {10, 1}));
    REQUIRE_THROWS(graph.removeVerges(1, vector<int> {-2, 1}));

}

TEST_CASE("NNumeration") {
    Graph graph;
    REQUIRE_THROWS(graph.NNumbering());
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addNode(4, 1);
    graph.addNode(5, {1,2,3});
    graph.addNode(6, {0,3,4});
    REQUIRE(graph.NNumbering() == vector<int> {6, 3, 1, 4, 2, 5});
    graph.removeVerge(3,5);
    graph.removeVerge(2,4);
    REQUIRE(graph.NNumbering() == vector<int> {6, 3, 1, 2, 4, 5});
}