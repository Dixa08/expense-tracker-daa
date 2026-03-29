// ============================================================
// Member 1 — QuickSort: sort expenses by AMOUNT
// DAA Concept  : Divide and Conquer
// Time          : O(n log n) average  |  O(n²) worst case
// Space         : O(log n) call stack
// Compile       : g++ -std=c++17 quicksort.cpp -o quicksort
// Run           : ./quicksort
// ============================================================
#include <vector>
#include <algorithm>
#include "../models/expense.h"

int partition(std::vector<Expense>& arr, int low, int high) {
    float pivot = arr[high].amount;
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j].amount < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(std::vector<Expense>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}