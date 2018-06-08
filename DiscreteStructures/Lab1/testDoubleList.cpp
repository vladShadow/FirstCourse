#include <iostream>
#include "DoubleList.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
using namespace std;



TEST_CASE("Push") {
    DoubleList list;
    REQUIRE(list.toString() == "");
    list.push(7);list.push(-13);list.push(0);list.push(94);
    REQUIRE(list.toString() == "7 -13 0 94 ");
    list.push(5910);
    REQUIRE(list.toString() == "7 -13 0 94 5910 ");
}

TEST_CASE("Іnsert") {
    DoubleList list;
    list.push(8);list.push(-2);list.push(15);list.push(72);
    REQUIRE(list.toString() == "8 -2 15 72 ");
    list.insert(10, 0);
    REQUIRE(list.toString() == "10 8 -2 15 72 ");
    list.insert(10, 4);list.insert(-52, 3);list.insert(0, 0);
    REQUIRE(list.toString() == "0 10 8 -2 -52 15 10 72 ");

    REQUIRE_THROWS(list.insert(1, -10));
    REQUIRE_THROWS(list.insert(1, 9));
    REQUIRE_NOTHROW(list.insert(1, 8));
}

TEST_CASE("Remove") {
    DoubleList list;
    list.push(7);list.push(-1);list.push(41);list.push(-14);
    list.push(3);list.push(58);list.push(-21);list.push(0);
    REQUIRE(list.toString() == "7 -1 41 -14 3 58 -21 0 ");
    list.remove(0);
    REQUIRE(list.toString() == "-1 41 -14 3 58 -21 0 ");
    list.remove(6);list.remove(4);list.remove(1);
    REQUIRE(list.toString() == "-1 -14 3 -21 ");

    REQUIRE_THROWS(list.remove(-10));
    REQUIRE_THROWS(list.remove(4));
    REQUIRE_NOTHROW(list.remove(3));
}

TEST_CASE("Size") {
    DoubleList list;
    REQUIRE(list.size() == 0);
    list.push(7);list.push(-36);list.push(-26);list.push(-7);
    REQUIRE(list.size() == 4);
    list.remove(2);list.remove(0);
    REQUIRE(list.size() == 2);
}

TEST_CASE("Iterator") {
    DoubleList list;
    list.push(4);list.push(5);list.push(-2);list.push(0);
    string listString;
    for (DoubleList::Iterator it = list.begin();it != nullptr;++it)
        listString += to_string(it->data) + " ";
    REQUIRE(listString == "4 5 -2 0 ");
    listString = "";
    for (DoubleList::Iterator it = list.end();it != nullptr;--it)
        listString += to_string(it->data) + " ";
    REQUIRE(listString == "0 -2 5 4 ");

    DoubleList::Iterator it = ++list.end();
    REQUIRE_THROWS(++it);
    it = --list.begin();
    REQUIRE_THROWS(--it);
}

TEST_CASE("Sort") {
    DoubleList list;
    list.push(90);list.push(-1);list.push(11);list.push(0);
    list.push(5);list.push(3);list.push(-22);list.push(-7);
    REQUIRE(list.toString() == "90 -1 11 0 5 3 -22 -7 ");
    list.sort();
    REQUIRE(list.toString() == "90 11 5 3 0 -1 -7 -22 ");
    DoubleList SecondList;
    SecondList.push(0);SecondList.push(0);SecondList.push(71);
    SecondList.push(0);SecondList.push(5);SecondList.push(-3);
    SecondList.push(-22);SecondList.push(-3);
    REQUIRE(SecondList.toString() == "0 0 71 0 5 -3 -22 -3 ");
    SecondList.sort();
    REQUIRE(SecondList.toString() == "71 5 0 0 0 -3 -3 -22 ");
}
