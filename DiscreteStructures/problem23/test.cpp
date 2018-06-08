#include "HashTable.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

TEST_CASE("Add/Find") {
    HashTable ht(100); vector<int> rnd(100);
    for (int i = 0; i < rnd.size(); i++) {
        rnd[i] = rand()%10;
    }
    for (int i = 0; i < rnd.size(); i++) {
        ht.add(rnd[i]);
    }
    for (int i = 0; i < rnd.size(); i++) {
        REQUIRE(ht.find(rnd[i])->data == rnd[i]);
    }
}
TEST_CASE("Remove/Find") {
    HashTable ht(10);
    ht.add(1);ht.add(34);ht.add(-1);ht.add(47);ht.add(-89);
    REQUIRE(ht.find(34)->data == 34);
    ht.remove(34);
    REQUIRE_THROWS(ht.find(34));
}
TEST_CASE("Erase") {
    HashTable ht(10);
    ht.add(1);ht.add(34);ht.add(-1);ht.add(47);ht.add(-89);
    ht.erase();
    REQUIRE_THROWS(ht.find(1), ht.find(-89));
}
