# SortingAlgorithm

使用 **C++ 實作常見排序演算法（Sorting Algorithms）** 的學習專案。

---

## 功能

- 實作常見排序演算法：
  - Bubble Sort
  - Insertion Sort
  - Selection Sort
  - Shell Sort
  - Merge Sort
  - Quick Sort
  - Heap Sort
- 每一輪排序都會**輸出目前陣列狀態**，方便觀察演算法運作細節
- 提供 **隨機測資產生器**（GenerateRandomVector）

---

## 專案結構

```text
SortingAlgorithm/
├── Sort.h        # 所有排序演算法實作
├── main.cpp      # 測試主程式
└── README.md
```

---

## 已實作排序演算法
### 1. Bubble Sort（氣泡排序）

逐一比較相鄰元素並交換，並包含提前中斷(若一輪沒有交換則提前結束)
```cpp
vector<int> BubbleSort(vector<int> vec);
```
### 2. Insertion Sort（插入排序）

將未排序元素插入已排序部分的正確位置
```cpp
vector<int> InsertSort(vector<int> vec);
```

### 3. Selection Sort（選擇排序）

每次從未排序部分找最小值，與未排序最前端交換
```cpp
vector<int> SelectionSort(vector<int> vec);
```

### 4. Shell Sort（希爾排序）

使用spa間隔做分組插入排序，span逐步減半直到1
```cpp
vector<int> ShellSort(vector<int> vec);
```
### 5. Merge Sort（合併排序）

使用 Divide and Conquer，將陣列不斷對半分，再合併排序
```cpp
vector<int> mergeSort(vector<int> vec, int l, int r);
```

### 6. Quick Sort（快速排序）

使用最後一個元素作為 pivot，partition 後遞迴排序左右子區間
```cpp
vector<int> QuickSort(vector<int> vec, int l, int r);
```

### 7. Heap Sort（堆積排序）

建立 Max Heap，反覆 ExtractMax 放到尾端
```cpp
vector<int> HeapSort(vector<int> vec);
```

---

## 編譯與執行方式
### Windows(MinGW / g++)
```cmd
g++ main.cpp -o main
main
```
### Linux
```cmd
g++ main.cpp -o main
./main
```

---

## 測試資料

可以在main.cpp中選擇：

固定測資
```cpp
vector<int> v = {50, 10, 80, 90, 70, 60, 65, 62};
```

隨機測資
```cpp
vector<int> v = GenerateRandomVector(10, 0, 100);
```

---

## 各排序演算法比較

| 演算法         |平均時間複雜度| 最差       | Stable | In-Place |
| -------------- | ---------- | ---------- |:-:|:-:|
| Bubble Sort    | O(n²)      | O(n²)      | O | O |
| Insertion Sort | O(n²)      | O(n²)      | O | O |
| Selection Sort | O(n²)      | O(n²)      | X | O |
| Shell Sort     | ~O(n^1.3)  | O(n²)      | X | O |
| Merge Sort     | O(n log n) | O(n log n) | O | X |
| Quick Sort     | O(n log n) | O(n²)      | X | O |
| Heap Sort      | O(n log n) | O(n log n) | X | O |
