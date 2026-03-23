# Analytics Module — DAA Analysis (Member 3)

## Dynamic Programming — Monthly totals & prefix sum

**Algorithm:** Dynamic Programming (bottom-up tabulation)
**Recurrence relation:** `dp[i] = dp[i-1] + expenses[i].amount`
**How it works:** Build a DP table where each month's total accumulates previous entries. Classic prefix sum pattern — optimal substructure applies.

| Operation      | Time  | Reason                      |
|----------------|-------|-----------------------------|
| Build DP table | O(n)  | One pass through all expenses |
| Query any month | O(1) | Direct map lookup           |

**Space:** O(m) where m = number of unique months
**DP property used:** Optimal substructure — total for any period = sum of sub-period totals.

---

## Greedy Algorithm — Budget cut suggestions

**Algorithm:** Greedy
**Greedy choice:** At each step, cut the most expensive non-essential item first. This is locally optimal and leads to the globally optimal minimum number of cuts needed.

| Step           | Time      |
|----------------|-----------|
| Classify items | O(n)      |
| Sort by amount | O(n log n)|
| Greedy cut loop | O(n)    |
| **Total**      | **O(n log n)** |

**Space:** O(n)
**Why greedy works here?** Each non-essential expense is independent. Removing the biggest one always saves the most money per cut — no future decision is affected by the current choice.
