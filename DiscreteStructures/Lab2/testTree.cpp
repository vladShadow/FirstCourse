#include <iostream>
#include "BSTree.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
using namespace std;


TEST_CASE("Add") {
    BSTree tree;
    tree.add('C');tree.add('C');tree.add('h');tree.add('Q');
    REQUIRE(tree.toString() == "C C Q h ");
    tree.add('W');tree.add('O');
    REQUIRE(tree.toString() == "C C O Q W h ");
}

TEST_CASE("Remove") {
    BSTree tree;
    tree.add('T');tree.add('A');tree.add('n');tree.add('O');
    tree.add('U');tree.add('a');tree.add('a');tree.add('Z');
    REQUIRE(tree.toString() == "A O T U Z a a n ");
    tree.remove('n');tree.remove('Z');tree.remove('A');tree.remove('a');
    REQUIRE(tree.toString() == "O T U a ");
    REQUIRE_THROWS(tree.remove('P'));
    REQUIRE(tree.toString() == "O T U a ");
}

TEST_CASE("Min and Max") {
    BSTree tree;
    REQUIRE_THROWS(tree.min());
    REQUIRE_THROWS(tree.max());
    tree.add('a');tree.add('o');tree.add('V');tree.add('R');
    tree.add('z');tree.add('R');tree.add('g');tree.add('D');
    REQUIRE(tree.min() == 'D');
    REQUIRE(tree.max() == 'z');
}


TEST_CASE("Insert E or Calculate Sum") {
    BSTree tree;
    tree.add('T');tree.add('L');tree.add('z');tree.add('H');
    REQUIRE(tree.toString() == "H L T z ");
    tree.insertEorCalculateSum();
    REQUIRE(tree.toString() == "E H L T z ");
    REQUIRE(tree.insertEorCalculateSum() == 423);
    REQUIRE(tree.toString() == "E H L T z ");
}

