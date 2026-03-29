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

string getMonth(const string& date) { return date.substr(0, 7); }

// DP Table: month -> cumulative total
// dp[month] = dp[month] + current expense  (recurrence relation)
map<string, float> buildDPTable(vector<Expense>& expenses) {
    map<string, float> dp;
    for (auto& e : expenses)
        dp[getMonth(e.date)] += e.amount;
    return dp;
}

// Prefix sum DP: running total after each expense
// dp[i] = dp[i-1] + expenses[i].amount
vector<float> prefixSum(vector<Expense>& expenses) {
    int n = expenses.size();
    vector<float> dp(n);
    dp[0] = expenses[0].amount;
    for (int i = 1; i < n; i++)
        dp[i] = dp[i-1] + expenses[i].amount;
    return dp;
}

int main() {
    vector<Expense> expenses = {
        {1, "Pizza",       150.0f, "Food",          "2024-03-10", "UPI"},
        {2, "Auto",         45.0f, "Transport",     "2024-03-11", "Cash"},
        {3, "Rent",       5000.0f, "Utilities",     "2024-03-01", "NetBanking"},
        {4, "Movie",       240.0f, "Entertainment", "2024-04-05", "UPI"},
        {5, "Electricity", 850.0f, "Utilities",     "2024-04-14", "NetBanking"},
        {6, "Coffee",       60.0f, "Food",          "2024-04-16", "UPI"},
    };

    cout << "=== DP: Monthly Totals ===" << endl;
    auto dpTable = buildDPTable(expenses);
    for (auto& [month, total] : dpTable)
        cout << "  " << month << " : Rs." << total << endl;

    cout << "\n=== DP: Running Total (Prefix Sum) ===" << endl;
    auto ps = prefixSum(expenses);
    for (int i = 0; i < (int)expenses.size(); i++)
        cout << "  After expense " << i+1
             << " (" << expenses[i].description << ")"
             << ": total = Rs." << ps[i] << endl;

    return 0;
}
