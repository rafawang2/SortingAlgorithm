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
using std::pair;

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

vector<int> SelectionSort(vector<int> vec) {
    int n = vec.size();
    // 從unsort part選最小，並與unsort part第一個交換
    for (int i=0; i<n; ++i) {
        int min_idx = i;
        for (int j=i; j<n; ++j) {
            if (vec[min_idx] > vec[j])
                min_idx = j;
        }
        if (min_idx != i)
            swap(vec[i], vec[min_idx]);
        PrintVec(vec);
    }
    return vec;
}

vector<int> ShellSort(vector<int> vec) {
    int n = vec.size();
    int span = n/2;
    while (span >= 1) { // 持續直到間隔收斂到0
        bool flag;
        do {
            flag = false;
            for (int i=0; i+span < n; ++i) {
                if (vec[i] > vec[i+span]) {
                    swap(vec[i], vec[i+span]);
                    flag = true;
                    PrintVec(vec);
                }
            }
        } while (flag);
        span /= 2;
    }
    return vec;
}

void merge(vector<int>& vec, int l, int m, int r) {
    int n1 = m-l+1; // v1的長度 l~m
    int n2 = r-m;   // v2的長度 m+1~r
    // copy two vec
    vector<int> v1(n1), v2(n2);
    for (int i=0; i<n1; ++i) {
        v1[i] = vec[l+i];
    }
    for (int i=0; i<n2; ++i) {
        v2[i] = vec[m+1+i];
    }

    // merge two vec
    int p=0, q=0;
    int k = l;
    while (p<n1 && q <n2) {
        if (v1[p] < v2[q]) {
            vec[k] = v1[p];
            ++k;
            ++p;
        }
        else {
            vec[k] = v2[q];
            ++k;
            ++q;
        }
    }

    // 若p, q大小不同，會有多的也要處理
    while (p<n1) {
        vec[k] = v1[p];
        ++p;
        ++k;
    }
    while (q<n2) {
        vec[k] = v2[q];
        ++q;
        ++k;
    }
}

vector<int> mergeSort(vector<int> vec, int l, int r) {
    if(l>=r)
        return vec;
    int m = (l+r)/2;
    vec = mergeSort(vec, l, m);
    vec = mergeSort(vec, m+1, r);
    PrintVec(vec);
    merge(vec, l, m, r);
    return vec;
}

int partition(vector<int>& vec, int l, int r) {
    // 最後一筆當pivot
    int x = vec[r];
    int i = l-1;
    for (int j=l; j<r; ++j) {
        // 若找到比pivot小的i才往前，並往前跟大的交換
        if (vec[j] <= x) {
            ++i;
            swap(vec[i], vec[j]);
        }
    }
    int p = i+1;
    swap(vec[p], vec[r]);
    return p;
}

vector<int> QuickSort(vector<int> vec, int l, int r) {
    if (l < r) {
        int p = partition(vec, l, r);
        PrintVec(vec);
        vec = QuickSort(vec, l, p-1);
        vec = QuickSort(vec, p, r);
    }
    return vec;
}

void heapify(vector<int>& vec, int parent, int heap_size) {
    int Lchild = 2*parent+1;
    int Rchild = 2*parent+2;
    int max = parent;
    if (Lchild < heap_size && vec[Lchild] > vec[max]) {
        max = Lchild;
    }
    if (Rchild < heap_size && vec[Rchild] > vec[max]) {
        max = Rchild;
    }

    // max有變過->繼續往下調整
    if (max != parent) {
        swap(vec[max], vec[parent]);
        heapify(vec, max, heap_size);
    }
}

void BuildHeap(vector<int>& vec, int heap_size) {
    // 對所有non-leaf做heapify
    for (int parent=(heap_size-1)/2; parent>=0; parent--) {
        heapify(vec, parent, heap_size);
    }
}

int ExtractMax(vector<int>& vec, int heap_size) {
    int max = vec[0];
    vec[0] = vec[heap_size-1];
    heapify(vec, 0, heap_size-1);   // heap size減1!
    return max;
}

vector<int> HeapSort(vector<int> vec) {
    int n = vec.size();
    BuildHeap(vec, n);
    for (int i=n-1; i>=1; --i) {
        // 最大的丟到vec最後面
        vec[i] = ExtractMax(vec, i+1);
        PrintVec(vec);
    }
    return vec;
}

pair<int, int> find_min_max(const vector<int>& vec) {
    int n = vec.size();
    int minVal, maxVal;
    int i = 0;

    // 初始化
    if (n % 2 == 0) {
        if (vec[0] < vec[1]) {
            minVal = vec[0];
            maxVal = vec[1];
        } else {
            minVal = vec[1];
            maxVal = vec[0];
        }
        i = 2;
    } else {
        minVal = maxVal = vec[0];
        i = 1;
    }

    for (; i + 1 < n; i += 2) {
        int local_min, local_max;
        if (vec[i] < vec[i + 1]) {
            local_min = vec[i];
            local_max = vec[i + 1];
        } else {
            local_min = vec[i + 1];
            local_max = vec[i];
        }
        minVal = std::min(minVal, local_min);
        maxVal = std::max(maxVal, local_max);
    }

    return {minVal, maxVal};
}
vector<int> CountingSort(vector<int> vec) {
    // find range for vec
    pair<int, int> min_max = find_min_max(vec);
    int min = min_max.first;
    int max = min_max.second;
    int n = vec.size();
    int k = max-min+1;  // size of occur list

    // step 1: 計算各數的出現次數
    vector<int> occur(k, 0);    // min~max
    for (int i : vec) {
        occur[i-min] += 1;
    }

    // step 2: 計算各數的正確位置
    for (int i=1; i<k; ++i) {
        occur[i] += occur[i-1];
    }

    // step 3: shift right 1
    for (int i=k-1; i>=1; --i) {
        occur[i] = occur[i-1];
    }
    occur[0] = 0;

    vector<int> result(n);
    for (int i=0; i<n; i++) {
        result[ occur[vec[i]-min] ] = vec[i];
        PrintVec(result);
        ++occur[vec[i]-min];
    }
    return result;
}