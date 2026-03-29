// ============================================================
//  Dynamic Programming: monthly spending totals
// DAA Concept  : Dynamic Programming (bottom-up tabulation)
// Time          : O(n) build  |  O(1) query
// Space         : O(m) where m = unique months
// Compile       : g++ -std=c++17 dp.cpp -o dp
// Run           : ./dp
// ============================================================
#include <iostream>
#include <vector>
#include <map>
#include "../models/expense.h"
using namespace std;

string getMonth(const string& date) {
    return date.substr(0, 7);
}

// ---------------- DP TABLE (Monthly totals) ----------------
map<string, float> buildDPTable(vector<Expense>& expenses) {
    map<string, float> dp;

    for (auto& e : expenses) {
        dp[getMonth(e.date)] += e.amount;
    }

    return dp;
}

// ---------------- PREFIX SUM DP ----------------
vector<float> prefixSum(vector<Expense>& expenses) {
    int n = expenses.size();
    vector<float> dp(n);

    if (n == 0) return dp;

    dp[0] = expenses[0].amount;

    for (int i = 1; i < n; i++) {
        dp[i] = dp[i-1] + expenses[i].amount;
    }

    return dp;
}

// ---------------- MAIN CALL FUNCTION ----------------
void dpOptimization(vector<Expense>& expenses) {
    if (expenses.empty()) {
        cout << "No data available for DP analysis.\n";
        return;
    }

    cout << "\n=== DP: Monthly Totals ===\n";

    auto dpTable = buildDPTable(expenses);
    for (auto& it : dpTable) {
        cout << it.first << " : Rs." << it.second << endl;
    }

    cout << "\n=== DP: Running Total (Prefix Sum) ===\n";

    auto ps = prefixSum(expenses);
    for (int i = 0; i < (int)expenses.size(); i++) {
        cout << "After expense " << i+1
             << " (" << expenses[i].description << ")"
             << ": Rs." << ps[i] << endl;
    }
}