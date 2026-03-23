// ============================================================
// Member 1 — MergeSort: sort expenses by DATE
// DAA Concept  : Divide and Conquer
// Time          : O(n log n) — always (best, avg, worst)
// Space         : O(n) temporary arrays
// Compile       : g++ -std=c++17 mergesort.cpp -o mergesort
// Run           : ./mergesort
// ============================================================

#include <iostream>
#include <vector>
#include "../models/expense.h"
using namespace std;

void merge(vector<Expense>& arr, int left, int mid, int right) {
    vector<Expense> L(arr.begin() + left,  arr.begin() + mid + 1);
    vector<Expense> R(arr.begin() + mid + 1, arr.begin() + right + 1);
    int i = 0, j = 0, k = left;
    while (i < (int)L.size() && j < (int)R.size())
        arr[k++] = (L[i].date <= R[j].date) ? L[i++] : R[j++];
    while (i < (int)L.size()) arr[k++] = L[i++];
    while (j < (int)R.size()) arr[k++] = R[j++];
}

void mergeSort(vector<Expense>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    vector<Expense> expenses = {
        {3, "Groceries",   320.0f, "Food",      "2024-03-15", "Card"},
        {1, "Pizza",       150.0f, "Food",      "2024-03-10", "UPI"},
        {5, "Electricity", 850.0f, "Utilities", "2024-03-08", "NetBanking"},
        {2, "Auto",         45.0f, "Transport", "2024-03-12", "Cash"},
        {4, "Movie",       240.0f, "Fun",        "2024-03-05", "UPI"},
    };

    cout << "=== MERGESORT by Date ===" << endl;
    cout << "Before:" << endl;
    for (auto& e : expenses)
        cout << "  " << e.date << " | " << e.description << endl;

    mergeSort(expenses, 0, (int)expenses.size() - 1);

    cout << "\nAfter (oldest to newest):" << endl;
    for (auto& e : expenses)
        cout << "  " << e.date << " | " << e.description << endl;

    return 0;
}
