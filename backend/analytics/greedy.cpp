// ============================================================
// Greedy Algorithm: budget alert & cut suggestions
// DAA Concept  : Greedy (locally optimal choice at each step)
// Time          : O(n log n) due to sorting
// Space         : O(n)
// Compile       : g++ -std=c++17 greedy.cpp -o greedy
// Run           : ./greedy
// ============================================================
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include "../models/expense.h"
using namespace std;

void greedySelection(vector<Expense>& expenses, float budget) {

    if (expenses.empty()) {
        cout << "No data available\n";
        return;
    }

    float total = 0;
    for (auto& e : expenses) total += e.amount;

    cout << "\n=== GREEDY BUDGET ANALYSIS ===\n";
    cout << "Total spending : Rs." << total << endl;
    cout << "Your budget    : Rs." << budget << endl;

    if (total <= budget) {
        cout << "You are within budget!\n";
        return;
    }

    cout << "Over budget by Rs." << (total - budget) << endl;
    cout << "Suggested cuts:\n";

    set<string> essential = {"Utilities", "Transport", "Education", "Health"};

    vector<Expense> nonEssential;

    for (auto& e : expenses) {
        if (!essential.count(e.category)) {
            nonEssential.push_back(e);
        }
    }

    sort(nonEssential.begin(), nonEssential.end(),
        [](Expense a, Expense b) {
            return a.amount > b.amount;
        });

    float saved = 0;
    float target = total - budget;

    for (auto& e : nonEssential) {
        if (saved >= target) break;

        cout << "CUT -> " << e.description
             << " Rs." << e.amount << endl;

        saved += e.amount;
    }

    cout << "New total after cuts: Rs." << (total - saved) << endl;
}