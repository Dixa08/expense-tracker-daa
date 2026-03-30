#include <iostream>
#include <vector>
#include <algorithm>
#include "../models/expense.h"

void greedyBudgetSelection(std::vector<Expense>& expenses, float budget) {
    std::sort(expenses.begin(), expenses.end(), [](const Expense& a, const Expense& b) {
        return a.amount < b.amount;
    });
    float sum = 0;
    std::cout << "\n--- Greedy Selection (Cheapest First) ---\n";
    for (const auto& e : expenses) {
        if (sum + e.amount <= budget) {
            sum += e.amount;
            std::cout << "[KEEP] " << e.description << " (Rs." << e.amount << ")\n";
        }
    }
}