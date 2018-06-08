#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;


template<class T> void shellSort(vector<T>&);
template<class T> void quickSort(vector<T>&);
template<class T> void quickSort(vector<T>&, int, int);
template<class T> int findPillar(vector<T>&, int, int);
template<class T> string toString(vector<T>);
// PROBLEMS 13-22
vector<int> problem13(vector<int>, void (*)(vector<int>&));
void problem14(vector<int>&, int, void (*)(vector<int>&));
void problem15(vector<int>&);
void problem16(vector<int>&, void (*)(vector<int>&));
vector<int> problem17(vector<int>);
void problem18(vector<string>&, void (*)(vector<int>&));
vector<pair<int, string>> problem19(vector<pair<int, string>>&, void (*)(vector<int>&));
void problem20(vector<string>&, void (*)(vector<int>&));
void problem21(vector<int>&, void (*)(vector<int>&));
void problem22(vector<double>&, void (*)(vector<double>&));



// TESTS

TEST_CASE("Problem 13") {
    vector<int> vec = {1, -14, 82, 0, -51, 10, 5};
    vector<int> res = problem13(vec, shellSort);
    REQUIRE(toString(res) == "82 10 5 1 0 -14 -51 ");
    vector<int> res2 = problem13(vec, quickSort);
    REQUIRE(toString(res2) == "82 10 5 1 0 -14 -51 ");
}
TEST_CASE("Problem 14") {
    vector<int> vec = {-67, -10, -2, 38, 90, 91};
    problem14(vec, 25, shellSort);
    REQUIRE(toString(vec) == "-67 -10 -2 25 38 90 91 ");
    problem14(vec, -47, quickSort);
    REQUIRE(toString(vec) == "-67 -47 -10 -2 25 38 90 91 ");
}
TEST_CASE("Problem 15") {
    vector<int> vec = {-67, -10, -2, 38, 90, 91};
    problem15(vec);
    REQUIRE(toString(vec) == "91 90 38 -2 -10 -67 ");
}
TEST_CASE("Problem 16") {
    vector<int> vec = {1, -14, 82, 0, -51, 10, 5};
    vector<int> vec2 = vec;
    problem16(vec, shellSort);
    REQUIRE(toString(vec) == "0 1 5 10 82 ");
    problem16(vec2, quickSort);
    REQUIRE(toString(vec2) == "0 1 5 10 82 ");
}
TEST_CASE("Problem 17") {
    vector<int> vec = {1, -14, 82, 0, -51, 10, 5};
    vector<int> res = problem17(vec);
    REQUIRE(toString(res) == "-51 -14 0 1 5 10 82 ");
}
TEST_CASE("Problem 18") {
    vector<string> vec = {"Patricia Aakhus",
                          "Ben Aaronovitch",
                          "Hans Aanrud",
                          "David Aaron",
                          "Alexander Aaronsohn"};
    vector<string> vec2 = vec;
    problem18(vec, shellSort);
    REQUIRE(toString(vec) == "Alexander Aaronsohn "
            "Ben Aaronovitch "
            "David Aaron "
            "Hans Aanrud "
            "Patricia Aakhus ");
    problem18(vec2, quickSort);
    REQUIRE(toString(vec2) == "Alexander Aaronsohn "
            "Ben Aaronovitch "
            "David Aaron "
            "Hans Aanrud "
            "Patricia Aakhus ");
}
TEST_CASE("Problem 19") {
    vector<pair<int, string>> vec = {{0121452105, "Patricia"},
                                     {5620321512, "Ben"},
                                     {2590672360, "David"},
                                     {7131590116, "Hans"}};
    vector<pair<int, string>> res = problem19(vec, shellSort);
    for (int i = 1; i < res.size(); i++) {
        REQUIRE(res[i-1].first < res[i].first);
    }
    vector<pair<int, string>> res2 = problem19(vec, quickSort);
    for (int i = 1; i < res2.size(); i++) {
        REQUIRE(res2[i-1].first < res2[i].first);
    }
}
TEST_CASE("Problem 20") {
    vector<string> vec = {"Alexander", "Ben", "David",
                          "Hans", "Patricia"};
    vector<string> vec2 = vec;
    problem20(vec, shellSort);
    REQUIRE(toString(vec) == "Ben Hans David "
            "Patricia Alexander ");
    problem20(vec2, quickSort);
    REQUIRE(toString(vec2) == "Ben Hans David "
            "Patricia Alexander ");
}
TEST_CASE("Problem 21") {
    vector<int> vec = {1, -14, 82, 0, -51, 10, 5};
    vector<int> vec2 = vec;
    problem21(vec, shellSort);
    REQUIRE(toString(vec) == "0 1 5 10 -14 -51 82 ");
    problem21(vec2, quickSort);
    REQUIRE(toString(vec2) == "0 1 5 10 -14 -51 82 ");
}
TEST_CASE("Problem 22") {
    vector<double> vec = {-55, -7, -2.5, 12, 67.5};
    vector<double> vec2 = vec;
    problem22(vec, shellSort);
    REQUIRE(toString(vec) == "-55 -31 -7 -4.75 -2.5 4.75 12 39.75 67.5 ");
    problem22(vec2, shellSort);
    REQUIRE(toString(vec2) == "-55 -31 -7 -4.75 -2.5 4.75 12 39.75 67.5 ");
}

// DEFINITIONS

template <class T> void shellSort(vector<T> &vec)
{
    for (int d = vec.size()/2; d >= 1; d /= 2)
        for (int i = d; i < vec.size(); i++)
            for (int j = i; j >= d && vec[j-d] > vec[j]; j -= d)
                swap(vec[j], vec[j-d]);
}

template <class T> void quickSort(vector<T> &vec) {
    quickSort(vec, 0, vec.size()-1);
}
template <class T> void quickSort(vector<T> &vec, int first, int last) {
    if (first < last) {
        int pillar = findPillar(vec, first, last);
        quickSort(vec, first, pillar-1);
        quickSort(vec, pillar+1, last);
    }
}
template <class T> int findPillar(vector<T> &vec, int first, int last) {
    int i = first;
    for (int j = first; j < last; j++) {
        if (vec[j] < vec[last]) {
            swap(vec[i], vec[j]);
            i++;
        }
    }
    swap(vec[i], vec[last]);
    return i;
}

template<class T> string toString(vector<T> vec) {
    stringstream ss;
    for(int i = 0; i < vec.size(); i++)
        ss << vec[i] << " ";
    return ss.str();
}


// PROBLEMS 13-22
vector<int> problem13(vector<int> vec, void (*sort)(vector<int>&)) {
    vector<int> res = vec;
    sort(res);
    for (int i = 0; i < res.size() / 2; i++)
        swap(res[i], res[res.size() - i - 1]);
    return res;
}

void problem14(vector<int> &vec, int num, void (*sort)(vector<int>&)) {
    vec.push_back(num);
    sort(vec);
}

void problem15(vector<int> &vec) {
    for (int i = 0; i < vec.size() / 2; i++)
        swap(vec[i], vec[vec.size() - i - 1]);
}

void problem16(vector<int> &vec, void (*sort)(vector<int>&)) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] < 0) vec.erase(vec.begin() + i);
    }
    sort(vec);
}

vector<int> problem17(vector<int> vec) {
    vector<int> res;
    int size = vec.size();
    int index = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 1; j < vec.size(); j++)
            if (vec[j] < vec[index]) index = j;
        res.push_back(vec[index]);
        vec.erase(vec.begin() + index);
        index = 0;
    }
    return res;
}

void problem18(vector<string> &vec, void (*sort)(vector<int>&)) {
    for (int i =  0; i < vec.size(); i++) {
        for (int j = 1; j < vec.size(); j++) {
            int k = 0;
            while (k < min(vec[j-1].length(), vec[j].length())) {
                if (vec[j-1][k] != vec[j][k]) break;
                k++;
            }
            if (vec[j-1][k] > vec[j][k]) swap(vec[j-1], vec[j]);
        }
    }
}

vector<pair<int, string>> problem19(vector<pair<int, string>> &vec, void (*sort)(vector<int>&)) {
    vector<int> nums;
    for (int i = 0; i < vec.size(); i++) {
        nums.push_back(vec[i].first);
    }
    sort(nums);
    vector<pair<int, string>> res;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < vec.size(); j++) {
            if (nums[i] == vec[j].first) res.push_back(vec[j]);
            break;
        }
    }
    return res;
}

void problem20(vector<string> &vec, void (*sort)(vector<int>&)) {
    vector<int> lng;
    for (int i = 0; i < vec.size(); i++) {
        lng.push_back(vec[i].length());
    }
    vector<int> srt = lng;
    sort(srt);
    vector<string> tmp;
    for (int i = 0; i < srt.size(); i++) {
        for (int j = 0; j < lng.size(); j++) {
            if (srt[i] == lng[j]) {
                tmp.push_back(vec[j]);
                vec.erase(vec.begin() + j);
                lng.erase(lng.begin() + j);
                break;
            }
        }
    }
    vec = tmp;
}

void problem21(vector<int> &vec, void (*sort)(vector<int>&)) {
    vector<int> lng;
    for (int i = 0; i < vec.size(); i++) {
        lng.push_back(abs(vec[i]));
    }
    vector<int> srt = lng;
    sort(srt);
    vector<int> tmp;
    for (int i = 0; i < srt.size(); i++) {
        for (int j = 0; j < lng.size(); j++) {
            if (srt[i] == lng[j]) {
                tmp.push_back(vec[j]);
                vec.erase(vec.begin() + j);
                lng.erase(lng.begin() + j);
                break;
            }
        }
    }
    vec = tmp;
}

void problem22(vector<double> &vec, void (*sort)(vector<double>&)) {
    int size = vec.size();
    for (int i = 1; i < size; i++) {
        vec.push_back((vec[i-1]+vec[i])/2);
    }
    sort(vec);
}