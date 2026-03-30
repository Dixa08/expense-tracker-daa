// ============================================================
//Binary Search: find expense by description
// DAA Concept  : Decrease and Conquer
// Time          : O(log n)  — needs sorted input first
// Space         : O(1)
// Compile       : g++ -std=c++17 binarysearch.cpp -o bsearch
// Run           : ./bsearch
// ============================================================
#include <vector>
#include "../models/expense.h"

int binarySearchAmount(std::vector<Expense>& arr, float target) {
    int low = 0, high = (int)arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid].amount == target) return mid;
        if (arr[mid].amount < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}