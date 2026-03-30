// ============================================================
// Member 1 — MergeSort: sort expenses by DATE
// DAA Concept  : Divide and Conquer
// Time          : O(n log n) — always (best, avg, worst)
// Space         : O(n) temporary arrays
// Compile       : g++ -std=c++17 mergesort.cpp -o mergesort
// Run           : ./mergesort
// ============================================================
#include <vector>
#include "../models/expense.h"

void merge(std::vector<Expense>& arr, int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    std::vector<Expense> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].amount <= R[j].amount) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(std::vector<Expense>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}