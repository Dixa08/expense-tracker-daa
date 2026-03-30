#include <iostream>
#include <vector>
#include <algorithm>
#include "../models/expense.h"

void dpBudgetOptimization(std::vector<Expense>& expenses, float budget) {
    int n = expenses.size(), W = (int)budget;
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            int amt = (int)expenses[i - 1].amount;
            if (amt <= w) dp[i][w] = std::max(1 + dp[i - 1][w - amt], dp[i - 1][w]);
            else dp[i][w] = dp[i - 1][w];
        }
    }
    std::cout << "\n--- DP Optimal Selection ---\n";
    int res = dp[n][W], w = W;
    for (int i = n; i > 0 && res > 0; i--) {
        if (res != dp[i - 1][w]) {
            std::cout << "[OPTIMAL] " << expenses[i - 1].description << " (Rs." << expenses[i - 1].amount << ")\n";
            w -= (int)expenses[i - 1].amount; res--;
        }
    }
}