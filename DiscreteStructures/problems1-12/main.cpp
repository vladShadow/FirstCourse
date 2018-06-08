#define CATCH_CONFIG_MAIN
#include <iostream>
#include "BSTree.h"
#include "catch.hpp"
using namespace std;


TEST_CASE("problem1") {
    BSTree tree;
    tree.fill();
    BSTree temp = tree;
    tree.insertAliquotN(5);
    bool ok = true;
    BSTree::Iterator tmp = temp.begin();
    for (BSTree::Iterator it = tree.begin(); it != tree.end(); ++it) {
        if (it->data != tmp->data && it->data%5 != 0) {
            ok = false;
        }
        else ++tmp;
    }
    REQUIRE(ok);
    ok = true;
    tree.removeAliquotN(5);
    for (BSTree::Iterator it = tree.begin(); it != tree.end(); ++it) {
        if (it->data % 5 == 0) ok = false;
    }
    REQUIRE(ok);
}
TEST_CASE("problem2") {
    BSTree tree;
    tree.fill();
    BSTree temp = tree;
    tree.insertOdd();
    bool ok = true;
    BSTree::Iterator tmp = temp.begin();
    for (BSTree::Iterator it = tree.begin(); it != tree.end(); ++it) {
        if (it->data != tmp->data && it->data%2 == 0) {
            ok = false;
        }
        else ++tmp;
    }
    REQUIRE(ok);
    ok = true;
    tree.removeOdd();
    for (BSTree::Iterator it = tree.begin(); it != tree.end(); ++it) {
        if (it->data%2 != 0) ok = false;
    }
    REQUIRE(ok);
}
TEST_CASE("problem3") {
    BSTree tree;
    tree.fill();
    BSTree temp = tree;
    tree.insertBetterThenN(15);
    bool ok = true;
    BSTree::Iterator tmp = temp.begin();
    for (BSTree::Iterator it = tree.begin(); it != tree.end(); ++it) {
        if (it->data != tmp->data && it->data < 15) {
            ok = false;
        }
        else ++tmp;
    }
    REQUIRE(ok);
    ok = true;
    tree.removeBetterThenN(15);
    for (BSTree::Iterator it = tree.begin(); it != tree.end(); ++it) {
        if (it->data > 15) ok = false;
    }
    REQUIRE(ok);
}
TEST_CASE("problem4") {
    BSTree tree;
    tree.fill();
    BSTree temp = tree;
    tree.insertLessThenN(15);
    bool ok = true;
    BSTree::Iterator tmp = temp.begin();
    for (BSTree::Iterator it = tree.begin(); it != tree.end(); ++it) {
        if (it->data != tmp->data && it->data > 15) {
            ok = false;
        }
        else ++tmp;
    }
    REQUIRE(ok);
    ok = true;
    tree.removeLessThenN(15);
    for (BSTree::Iterator it = tree.begin(); it != tree.end(); ++it) {
        if (it->data < 15) ok = false;
    }
    REQUIRE(ok);
}
TEST_CASE("problem5") {
    BSTree tree;
    tree.fill();
    vector<int> vec = {1, -24, 4, 15, 35, -8};
    BSTree temp = tree;
    tree.insertChosen(vec);
    bool ok = true;
    BSTree::Iterator tmp = temp.begin();
    for (BSTree::Iterator it = tree.begin(); it != tree.end(); ++it) {
        if (it->data != tmp->data) {
            ok = false;
            for (int j = 0; j < vec.size(); j++) {
                if (it->data == vec[j]) ok = true;
            }
        }
        else ++tmp;
    }
    REQUIRE(ok);
    ok = true;
    tree.removeChosen(vec);
    for (BSTree::Iterator it = tree.begin(); it != tree.end(); ++it) {
        ok = true;
        for (int j = 0; j < vec.size(); j++) {
            if (it->data == vec[j]) ok = false;
        }
    }
    REQUIRE(ok);
}
TEST_CASE("problem6") {
    BSTree tree;
    tree.fill();
    BSTree temp = tree;
    tree.insertPrime();
    bool ok = true;
    BSTree::Iterator tmp = temp.begin();
    for (BSTree::Iterator it = tree.begin(); it != tree.end(); ++it) {
        if (it->data != tmp->data) {
            ok = true;
            for (int j = 2; j <= it->data/2; j++) {
                if (it->data%j == 0) ok = false;
            }
        }
        else ++tmp;
    }
    REQUIRE(ok);
    ok = true;
    tree.removePrime();
    for (BSTree::Iterator it = tree.begin(); it != tree.end(); ++it) {
        ok = false;
        for (int j = 2; j <= it->data/2; j++) {
            if (it->data%j == 0) ok = true;
        }
    }
    REQUIRE(ok);
}
TEST_CASE("problem7") {
    BSTree tree;
    tree.fill();
    BSTree temp = tree;
    tree.insertComposite();
    bool ok = true;
    BSTree::Iterator tmp = temp.begin();
    for (BSTree::Iterator it = tree.begin(); it != tree.end(); ++it) {
        if (it->data != tmp->data) {
            ok = false;
            for (int j = 2; j <= it->data/2; j++) {
                if (it->data%j == 0) ok = true;
            }
        }
        else ++tmp;
    }
    REQUIRE(ok);
    ok = true;
    tree.removeComposite();
    for (BSTree::Iterator it = tree.begin(); it != tree.end(); ++it) {
        ok = true;
        for (int j = 2; j <= it->data/2; j++) {
            if (it->data%j == 0) ok = false;
        }
    }
    REQUIRE(ok);
}
TEST_CASE("problem8") {
    BSTree tree;
    tree.fill();
    BSTree temp = tree;
    tree.insertFromXToY(-5, 28);
    bool ok = true;
    BSTree::Iterator tmp = temp.begin();
    for (BSTree::Iterator it = tree.begin(); it != tree.end(); ++it) {
        if (it->data != tmp->data && (it->data < -5 || it->data > 28)) {
            ok = false;
        }
        else ++tmp;
    }
    REQUIRE(ok);
    ok = true;
    tree.removeFromXToY(-5, 28);
    for (BSTree::Iterator it = tree.begin(); it != tree.end(); ++it) {
        if (it->data > -5 && it->data < 28) ok = false;
    }
    REQUIRE(ok);
    REQUIRE_THROWS(tree.insertFromXToY(46, 28));
    REQUIRE_THROWS(tree.insertFromXToY(23, -1));
}
TEST_CASE("problem9") {
    BSTree tree;
    tree.fill();
    BSTree temp = tree;
    tree.insertDigitSumBetterThenN(17);
    bool ok = true;
    BSTree::Iterator tmp = temp.begin();
    for (BSTree::Iterator it = tree.begin(); it != tree.end(); ++it) {
        if (it->data != tmp->data && abs(it->data%10 + it->data/10) < 17) {
            ok = false;
        }
        else ++tmp;
    }
    REQUIRE(ok);
    ok = true;
    tree.removeDigitSumBetterThenN(17);
    for (BSTree::Iterator it = tree.begin(); it != tree.end(); ++it) {
        if (abs(it->data%10 + it->data/10) > 17) ok = false;
    }
    REQUIRE(ok);
}
TEST_CASE("problem10") {
    BSTree tree;
    tree.fill();
    BSTree temp = tree;
    tree.insertDigitSumLessThenN(56);
    bool ok = true;
    BSTree::Iterator tmp = temp.begin();
    for (BSTree::Iterator it = tree.begin(); it != tree.end(); ++it) {
        if (it->data != tmp->data && abs(it->data%10 + it->data/10) > 56) {
            ok = false;
        }
        else ++tmp;
    }
    REQUIRE(ok);
    ok = true;
    tree.removeDigitSumLessThenN(56);
    for (BSTree::Iterator it = tree.begin(); it != tree.end(); ++it) {
        if (abs(it->data%10 + it->data/10) < 56) ok = false;
    }
    REQUIRE(ok);
}
TEST_CASE("problem11") {
    BSTree tree;
    tree.fill();
    BSTree temp = tree;
    tree.insertDigitSumFromXToY(5, 89);
    bool ok = true;
    BSTree::Iterator tmp = temp.begin();
    for (BSTree::Iterator it = tree.begin(); it != tree.end(); ++it) {
        if (it->data != tmp->data && (abs(it->data%10 + it->data/10) < 5 || abs(it->data%10 + it->data/10) > 89)) {
            ok = false;
        }
        else ++tmp;
    }
    REQUIRE(ok);
    ok = true;
    tree.removeDigitSumFromXToY(5, 89);
    for (BSTree::Iterator it = tree.begin(); it != tree.end(); ++it) {
        if (abs(it->data%10 + it->data/10) > 5 && abs(it->data%10 + it->data/10) < 89) ok = false;
    }
    REQUIRE(ok);
}
TEST_CASE("problem12") {
    BSTree tree;
    tree.fill();
    BSTree temp = tree;
    tree.insertIntegerSqrT();
    bool ok = true;
    BSTree::Iterator tmp = temp.begin();
    for (BSTree::Iterator it = tree.begin(); it != tree.end(); ++it) {
        float temp =  sqrt(abs(it->data));
        if (it->data != tmp->data && temp-(int)temp != 0) {
            ok = false;
        }
        else ++tmp;
    }
    REQUIRE(ok);
    ok = true;
    tree.removeIntegerSqrT();
    for (BSTree::Iterator it = tree.begin(); it != tree.end(); ++it) {
        float temp =  sqrt(abs(it->data));
        if (abs(it->data%10 + it->data/10) > 5 && temp-(int)temp == 0) ok = false;
    }
    REQUIRE(ok);
}





