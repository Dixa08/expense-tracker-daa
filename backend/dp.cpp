#include <bits/stdc++.h>
using namespace std;

// -----------------------------
// 🔵 EXPENSE STRUCTURE
// -----------------------------
struct Expense {
    int amount;   // cost (weight)
    int value;    // importance (value)
};

// -----------------------------
// 🔵 KNAPSACK (DP)
// Time Complexity: O(n * W)
// -----------------------------
int knapsack(vector<Expense>& items, int n, int budget) {

    // DP table
    vector<vector<int>> dp(n + 1, vector<int>(budget + 1, 0));

    // Build table
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= budget; w++) {

            if (items[i - 1].amount <= w) {
                // choose max of include or exclude
                dp[i][w] = max(
                    items[i - 1].value + dp[i - 1][w - items[i - 1].amount],
                    dp[i - 1][w]
                );
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][budget];
}

// -----------------------------
// MAIN (Testing)
// -----------------------------
int main() {

    vector<Expense> items = {
        {500, 5},   // Food
        {2000, 8},  // Travel
        {1000, 6},  // Bills
        {300, 3}    // Snacks
    };

    int budget = 2500;

    int n = items.size();

    int maxValue = knapsack(items, n, budget);

    cout << "Maximum Value within Budget: " << maxValue << endl;

    return 0;
}