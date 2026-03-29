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

void merge(std::vector<Expense>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<Expense> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].amount <= R[j].amount) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(std::vector<Expense>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}