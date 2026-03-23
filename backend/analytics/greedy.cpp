// ============================================================
// Member 3 — Greedy Algorithm: budget alert & cut suggestions
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

void greedyBudgetCut(vector<Expense> expenses, float budget) {
    float total = 0;
    for (auto& e : expenses) total += e.amount;

    cout << "Total spending : Rs." << total << endl;
    cout << "Your budget    : Rs." << budget << endl;

    if (total <= budget) {
        cout << "You are within budget! Great job." << endl;
        return;
    }

    cout << "Over by Rs." << (total - budget) << ". Suggested cuts:" << endl << endl;

    // Essential categories — never cut these
    set<string> essential = {"Utilities", "Transport", "Education", "Health"};

    // Separate non-essential expenses
    vector<Expense> nonEssential;
    for (auto& e : expenses)
        if (!essential.count(e.category))
            nonEssential.push_back(e);

    // Greedy: sort non-essential by amount DESC — cut biggest first
    sort(nonEssential.begin(), nonEssential.end(),
         [](const Expense& a, const Expense& b) { return a.amount > b.amount; });

    float saved = 0;
    float target = total - budget;
    for (auto& e : nonEssential) {
        if (saved >= target) break;
        cout << "  CUT -> " << e.description
             << " (Rs." << e.amount << " | " << e.category << ")" << endl;
        saved += e.amount;
    }

    cout << "\nIf you follow this: new total = Rs." << (total - saved) << endl;
}

int main() {
    vector<Expense> expenses = {
        {1, "Pizza",       150.0f, "Food",          "2024-03-10", "UPI"},
        {2, "Auto",         45.0f, "Transport",     "2024-03-11", "Cash"},
        {3, "Netflix",     199.0f, "Entertainment", "2024-03-12", "Card"},
        {4, "Rent",       5000.0f, "Utilities",     "2024-03-01", "NetBanking"},
        {5, "Movie",       240.0f, "Entertainment", "2024-03-13", "UPI"},
        {6, "Electricity", 850.0f, "Utilities",     "2024-03-14", "NetBanking"},
        {7, "Coffee",       60.0f, "Food",          "2024-03-16", "UPI"},
    };

    float budget = 6000.0f;
    cout << "=== GREEDY BUDGET ALERT ===" << endl << endl;
    greedyBudgetCut(expenses, budget);

    return 0;
}
