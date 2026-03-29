// ============================================================
// Member 4 — File Persistence: save/load expenses as CSV
// DAA Concept  : Sequential scan + String parsing
// Time          : O(n) save and load
// Space         : O(n)
// Compile       : g++ -std=c++17 persist.cpp -o persist
// Run           : ./persist
// ============================================================
#include <fstream>
#include <vector>
#include "../models/expense.h"

void saveExpenses(const std::vector<Expense>& arr) {
    std::ofstream out("data.txt");
    for (const auto& e : arr) {
        out << e.id << "|" << e.description << "|" << e.amount << "\n";
    }
    out.close();
}