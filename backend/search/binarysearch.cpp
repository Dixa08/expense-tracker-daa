// ============================================================
//Binary Search: find expense by description
// DAA Concept  : Decrease and Conquer
// Time          : O(log n)  — needs sorted input first
// Space         : O(1)
// Compile       : g++ -std=c++17 binarysearch.cpp -o bsearch
// Run           : ./bsearch
// ============================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include "../models/expense.h"
using namespace std;

void sortByDesc(vector<Expense>& arr) {
    sort(arr.begin(), arr.end(), [](const Expense& a, const Expense& b) {
        return a.description < b.description;
    });
}

// Returns index or -1
int binarySearch(vector<Expense>& arr, const string& target) {
    int low = 0, high = (int)arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid].description == target)       return mid;
        else if (arr[mid].description < target)   low  = mid + 1;
        else                                       high = mid - 1;
    }
    return -1;
}

int main() {
    vector<Expense> expenses = {
        {1, "Pizza",       150.0f, "Food",          "2024-03-10", "UPI"},
        {2, "Auto",         45.0f, "Transport",     "2024-03-11", "Cash"},
        {3, "Groceries",   320.0f, "Food",          "2024-03-12", "Card"},
        {4, "Movie",       240.0f, "Entertainment", "2024-03-13", "UPI"},
        {5, "Electricity", 850.0f, "Utilities",     "2024-03-14", "NetBanking"},
    };

    sortByDesc(expenses);

    cout << "=== BINARY SEARCH ===" << endl;
    cout << "Sorted list: ";
    for (auto& e : expenses) cout << e.description << " ";
    cout << endl << endl;

    // Test found
    string q = "Movie";
    int idx = binarySearch(expenses, q);
    if (idx != -1)
        cout << "Found '" << q << "': Rs." << expenses[idx].amount
             << " | " << expenses[idx].category << endl;
    else
        cout << "'" << q << "' NOT found." << endl;

    // Test not found
    q = "Coffee";
    idx = binarySearch(expenses, q);
    cout << "Search '" << q << "': " << (idx != -1 ? "Found" : "NOT found") << endl;

    return 0;
}
