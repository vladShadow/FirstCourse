#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int>&, int, int, long, long&);
int divide(vector<int>&, int, int);
void swap(vector<int>&, int, int);
void print(vector<int>);
void fillRandom(vector<int>&, int);

int main(int argc, char* argv[]) {
    vector<int> vec;
    fillRandom(vec, 10000);

    long a = 0;
    long b = 0;

    print(vec);
    quickSort(vec, 0, 9999, a, b);
    print(vec);

    cout<<b;
    return 0;
}


void quickSort(vector<int> &vec, int first, int last, long a, long &b) {
    a++;
    if (a>b) b = a;
    if (first < last) {
        int elPos = divide(vec, first, last);
        quickSort(vec, first, elPos-1, a, b);
        quickSort(vec, elPos+1, last, a, b);
    }
}

int divide(vector<int> &vec, int first, int last) {
    int i = first;
    for (int j = first; j < last; j++) {
        if (vec[j] < vec[last]) {
            swap(vec, i, j);
            i++;
        }
    }
    swap(vec, i, last);
    return i;
}

void swap(vector<int> &vec, int firstPos, int secondPos){
    int temp = vec[firstPos];
    vec[firstPos] = vec[secondPos];
    vec[secondPos] = temp;
}

void print(vector<int> vec) {
    for (int num : vec) cout << num << " ";
    cout << endl;
}

void fillRandom(vector<int> &vec, int number) {
    int j = number;
    for (int i = 0; i<number; i++) {
        //vec.push_back(rand()%200-100);
        vec.push_back(i);
    }
}