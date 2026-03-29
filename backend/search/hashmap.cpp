// ============================================================
/ HashMap: filter expenses by category
// DAA Concept  : Hashing
// Time          : O(n) build  |  O(1) average lookup
// Space         : O(n)
// Compile       : g++ -std=c++17 hashmap.cpp -o hashmap
// Run           : ./hashmap
// ============================================================

#include <iostream>
#include <vector>
#include <unordered_map>
#include "../models/expense.h"
using namespace std;

unordered_map<string, vector<Expense>> buildCategoryMap(vector<Expense>& expenses) {
    unordered_map<string, vector<Expense>> catMap;
    for (auto& e : expenses)
        catMap[e.category].push_back(e);
    return catMap;
}

int main() {
    vector<Expense> expenses = {
        {1, "Pizza",       150.0f, "Food",          "2024-03-10", "UPI"},
        {2, "Auto",         45.0f, "Transport",     "2024-03-11", "Cash"},
        {3, "Groceries",   320.0f, "Food",          "2024-03-12", "Card"},
        {4, "Movie",       240.0f, "Entertainment", "2024-03-13", "UPI"},
        {5, "Electricity", 850.0f, "Utilities",     "2024-03-14", "NetBanking"},
        {6, "Bus",          30.0f, "Transport",     "2024-03-15", "Cash"},
        {7, "Coffee",       60.0f, "Food",          "2024-03-16", "UPI"},
    };

    auto catMap = buildCategoryMap(expenses);

    // Filter one category — O(1) lookup
    string filter = "Food";
    cout << "=== FILTER: " << filter << " ===" << endl;
    for (auto& e : catMap[filter])
        cout << "  " << e.description << " -> Rs." << e.amount << endl;

    // All category totals
    cout << "\n=== ALL CATEGORY TOTALS ===" << endl;
    for (auto& [cat, list] : catMap) {
        float total = 0;
        for (auto& e : list) total += e.amount;
        cout << "  " << cat << ": Rs." << total
             << " (" << list.size() << " items)" << endl;
    }

    return 0;
}
