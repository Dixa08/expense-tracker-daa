// ============================================================
/ HashMap: filter expenses by category
// DAA Concept  : Hashing
// Time          : O(n) build  |  O(1) average lookup
// Space         : O(n)
// Compile       : g++ -std=c++17 hashmap.cpp -o hashmap
// Run           : ./hashmap
// ============================================================
#include <unordered_map>
#include <vector>
#include <string>
#include "../models/expense.h"

class ExpenseMap {
    std::unordered_map<std::string, Expense> table;
public:
    void buildMap(const std::vector<Expense>& arr) {
        for (const auto& e : arr) {
            table[e.description] = e;
        }
    }

    Expense* findByDescription(std::string desc) {
        if (table.find(desc) != table.end()) {
            return &table[desc];
        }
        return nullptr;
    }
};