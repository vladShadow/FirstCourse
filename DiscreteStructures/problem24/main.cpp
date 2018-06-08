#define CATCH_CONFIG_MAIN
#include "ConsHashRing.h"
#include "catch.hpp"
#include <iostream>
#include <map>
#include <vector>
#include <cmath>
using namespace std;




TEST_CASE("Add, find, remove") {
    ConsHashRing ring(5);
    ring.add(1,1);ring.add(2,2);ring.add(8,8);ring.add(4,4);
    ring.add(18,18);ring.add(127,127);ring.add(0,0);ring.add(12,12);

    REQUIRE((ring.find(1))->key == 1);
    REQUIRE((ring.find(0))->key == 0);
    REQUIRE((ring.find(8))->key == 8);
    REQUIRE((ring.find(127))->key == 127);
    REQUIRE_THROWS(ring.find(3));
    REQUIRE_THROWS(ring.find(100));

    ring.remove(2);ring.remove(4);ring.remove(12);
    REQUIRE_THROWS(ring.remove(100));
    REQUIRE_THROWS(ring.remove(5));

    REQUIRE_THROWS(ring.find(2));
    REQUIRE_THROWS(ring.find(4));
    REQUIRE_THROWS(ring.find(12));
}

TEST_CASE("Add/remove server, nodes redistributing") {
   ConsHashRing ring(5);
   ring.addServer(3);ring.addServer(7);ring.addServer(9);
   ring.add(1,1);ring.add(2,2);ring.add(8,8);ring.add(4,4);
   ring.add(18,18);ring.add(127,127);ring.add(0,0);ring.add(12,12);

    REQUIRE(ring.printServers() == "3.000000 5.000000 7.000000 9.000000 ");
    REQUIRE(ring.printServerNodes(3) == "2 8 18 0 ");
    REQUIRE(ring.printServerNodes(5) == "4 127 12 ");
    REQUIRE_THROWS(ring.printServerNodes(8));
    REQUIRE_THROWS(ring.printServerNodes(1));

    ring.addServer(6);ring.addServer(4.5);ring.addServer(2.1);
    REQUIRE(ring.printServers() == "2.100000 3.000000 4.500000 5.000000 6.000000 7.000000 9.000000 ");
    REQUIRE(ring.printServerNodes(3) == "2 8 ");
    REQUIRE(ring.printServerNodes(5) == "4 127 ");

    ring.removeServer(6);ring.removeServer(7);ring.removeServer(2.1);
    REQUIRE(ring.printServers() == "3.000000 4.500000 5.000000 9.000000 ");
    REQUIRE(ring.printServerNodes(3) == "2 8 18 0 ");
    REQUIRE(ring.printServerNodes(5) == "4 127 ");

    REQUIRE_THROWS(ring.removeServer(4));
    REQUIRE_THROWS(ring.removeServer(2.5));
}
