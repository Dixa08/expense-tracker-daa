#include <bits/stdc++.h>
using namespace std;

// -----------------------------
// 🟢 GREEDY BUDGET ALLOCATION
// Time Complexity: O(1)
// -----------------------------

struct Budget {
    double needs;
    double wants;
    double savings;
};

// Greedy function
Budget allocateBudget(double salary) {

    Budget b;

    // Greedy choice: fixed percentage allocation
    b.needs = salary * 0.5;    // 50% needs
    b.wants = salary * 0.3;    // 30% wants
    b.savings = salary * 0.2;  // 20% savings

    return b;
}

// -----------------------------
// MAIN (Testing)
// -----------------------------
int main() {

    double salary;
    cout << "Enter Salary: ";
    cin >> salary;

    Budget result = allocateBudget(salary);

    cout << "\n📊 Budget Allocation:\n";
    cout << "Needs: " << result.needs << endl;
    cout << "Wants: " << result.wants << endl;
    cout << "Savings: " << result.savings << endl;

    return 0;
}