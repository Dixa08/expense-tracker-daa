// ============================================================
// Member 1 — QuickSort: sort expenses by AMOUNT
// DAA Concept  : Divide and Conquer
// Time          : O(n log n) average  |  O(n²) worst case
// Space         : O(log n) call stack
// Compile       : g++ -std=c++17 quicksort.cpp -o quicksort
// Run           : ./quicksort
// ============================================================

#include <iostream>
#include <vector>
#include "../models/expense.h"
using namespace std;

int partition(vector<Expense>& arr, int low, int high) {
    float pivot = arr[high].amount;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].amount <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<Expense>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<Expense> expenses = {
        {1, "Pizza",       150.0f, "Food",          "2024-03-10", "UPI"},
        {2, "Auto",         45.0f, "Transport",     "2024-03-11", "Cash"},
        {3, "Groceries",   320.0f, "Food",          "2024-03-12", "Card"},
        {4, "Movie",       240.0f, "Entertainment", "2024-03-13", "UPI"},
        {5, "Electricity", 850.0f, "Utilities",     "2024-03-14", "NetBanking"},
        {6, "Coffee",       60.0f, "Food",          "2024-03-15", "UPI"}
    };

    cout << "=== QUICKSORT by Amount ===" << endl;
    cout << "Before:" << endl;
    for (auto& e : expenses)
        cout << "  " << e.description << " -> Rs." << e.amount << endl;

    quickSort(expenses, 0, (int)expenses.size() - 1);

    cout << "\nAfter (low to high):" << endl;
    for (auto& e : expenses)
        cout << "  " << e.description << " -> Rs." << e.amount << endl;

    return 0;
}
