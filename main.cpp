#include "Sort.h"

// g++ main.cpp -o main & main

int main() {
    vector<int> v = {50, 10, 80, 90, 70, 60, 65, 62};
    // vector<int> v = GenerateRandomVector(10, 0, 10);
    PrintVec(v);
    BubbleSort(v);
}