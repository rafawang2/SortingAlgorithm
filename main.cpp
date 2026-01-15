#include "Sort.h"

// g++ main.cpp -o main & main

int main() {
    vector<int> v = {50, 10, 80, 90, 70, 60, 65, 62};
    // vector<int> v = GenerateRandomVector(10, 0, 10);
    PrintVec(v);
    cout << "Bubble Sort:\n";
    BubbleSort(v);
    cout << "Insertion Sort:\n";
    InsertSort(v);
    cout << "Selectoin Sort:\n";
    SelectionSort(v);
    cout << "Shell Sort:\n";
    ShellSort(v);
    cout << "Merge Sort:\n";
    mergeSort(v, 0, v.size()-1);
    cout << "Quick Sort:\n";
    QuickSort(v, 0, v.size()-1);
    cout << "Heap Sort\n";
    HeapSort(v);
}