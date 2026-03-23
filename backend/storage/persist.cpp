// ============================================================
// Member 4 — File Persistence: save/load expenses as CSV
// DAA Concept  : Sequential scan + String parsing
// Time          : O(n) save and load
// Space         : O(n)
// Compile       : g++ -std=c++17 persist.cpp -o persist
// Run           : ./persist
// ============================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "../models/expense.h"
using namespace std;

void saveExpenses(const vector<Expense>& expenses, const string& filename) {
    ofstream file(filename);
    file << "id,description,amount,category,date,mode\n";
    for (auto& e : expenses)
        file << e.id << "," << e.description << ","
             << e.amount << "," << e.category << ","
             << e.date   << "," << e.mode << "\n";
    file.close();
    cout << "Saved " << expenses.size() << " expenses to " << filename << endl;
}

vector<Expense> loadExpenses(const string& filename) {
    vector<Expense> expenses;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "ERROR: Cannot open " << filename << endl;
        return expenses;
    }
    string line;
    getline(file, line);             // skip CSV header
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        Expense e;
        string tmp;
        getline(ss, tmp, ',');        e.id          = stoi(tmp);
        getline(ss, e.description, ',');
        getline(ss, tmp, ',');        e.amount      = stof(tmp);
        getline(ss, e.category, ',');
        getline(ss, e.date,     ',');
        getline(ss, e.mode,     ',');
        expenses.push_back(e);
    }
    file.close();
    return expenses;
}

int main() {
    vector<Expense> expenses = {
        {1, "Pizza",       150.0f, "Food",          "2024-03-10", "UPI"},
        {2, "Auto",         45.0f, "Transport",     "2024-03-11", "Cash"},
        {3, "Groceries",   320.0f, "Food",          "2024-03-12", "Card"},
        {4, "Electricity", 850.0f, "Utilities",     "2024-03-14", "NetBanking"},
    };

    cout << "=== FILE PERSISTENCE ===" << endl;
    saveExpenses(expenses, "../../data/expenses.csv");

    cout << "\nLoading back..." << endl;
    auto loaded = loadExpenses("../../data/expenses.csv");
    cout << "Loaded " << loaded.size() << " expenses:" << endl;
    for (auto& e : loaded)
        cout << "  [" << e.id << "] " << e.description
             << " Rs." << e.amount << " | " << e.category << endl;

    return 0;
}
