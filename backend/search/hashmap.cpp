#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "../models/expense.h"

void analyzeCategoriesWithHash(const std::vector<Expense>& expenses) {
    if (expenses.empty()) {
        std::cout << "\n[!] No data to analyze. Please load CSV first.\n";
        return;
    }

    std::unordered_map<std::string, float> totals;

    for (size_t i = 0; i < expenses.size(); ++i) {
        totals[expenses[i].category] += expenses[i].amount;
    }

    std::cout << "\n--- CATEGORY SPENDING ANALYSIS (HASH MAP) ---\n";
    // This loop works on ALL C++ versions (C++11, 14, 17, 20)
    for (auto const& pair : totals) {
        std::cout << " > " << pair.first << ": Rs." << pair.second << "\n";
    }
    std::cout << "----------------------------------------------\n";
}