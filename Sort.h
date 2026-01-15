# pragma once
# include <iostream>
# include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::swap;

void PrintVec(const vector<int>& vec) {
    for (int i : vec) {
        cout << i << " ";
    }
    cout << endl;
}

vector<int> GenerateRandomVector(int n, int min, int max) {
    vector<int> vec;
    srand(time(0)); // Seed the random number generator
    for (int i=0; i<n; i++) {
        int x = rand() % (max - min + 1) + min;
        vec.push_back(x);
    }
    return vec;
}

vector<int> BubbleSort(vector<int> vec) {
    int n = vec.size();
    bool swap_flag;
    for (int i=n-1; i>=1; --i) {
        swap_flag = false;
        for (int j=0; j<i; ++j) {
            if (vec[j] > vec[j+1]) {
                swap_flag = true;
                swap(vec[j], vec[j+1]);
            }
        }
        PrintVec(vec);
        if (!swap_flag)
            break;
    }
    return vec;
}

vector<int> InsertSort(vector<int> vec) {
    int n = vec.size();
    // 從未sort的部分插入到sorted部分的適當位置
    for (int i=1; i<n; ++i) {   // idx 0~(i-1): sorted
        int k = vec[i];
        int j = i-1;    // final idx for sorted part
        while (j>=0 && k<vec[j]) {
            vec[j+1] = vec[j];
            --j;
        }
        vec[j+1] = k;
        PrintVec(vec);
    }
    return vec;
}