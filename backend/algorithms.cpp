#include <bits/stdc++.h>
using namespace std;

struct Expense {
    int amount;
    string category;
    string date;
};

// ===== YOUR ORIGINAL FUNCTIONS (UNCHANGED) =====
int linearSearch(vector<Expense>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i].amount == target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(vector<Expense>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid].amount == target)
            return mid;
        else if (arr[mid].amount < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void merge(vector<Expense>& arr, int l, int m, int r) {
    vector<Expense> temp;
    int i = l, j = m + 1;
    while (i <= m && j <= r) {
        if (arr[i].amount <= arr[j].amount)
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }
    while (i <= m) temp.push_back(arr[i++]);
    while (j <= r) temp.push_back(arr[j++]);
    for (int k = l; k <= r; k++) {
        arr[k] = temp[k - l];
    }
}

void mergeSort(vector<Expense>& arr, int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

int partition(vector<Expense>& arr, int low, int high) {
    int pivot = arr[high].amount;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].amount < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<Expense>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// ===== NEW DAA ALGORITHMS =====
void greedyBudget(double totalBudget) {
    cout << "⚡ GREEDY ALGORITHM (50-30-20 Rule)\n";
    cout << "Total Budget: ₹" << fixed << setprecision(2) << totalBudget << "\n";
    cout << "Needs (50%): ₹" << totalBudget * 0.5 << "\n";
    cout << "Wants (30%): ₹" << totalBudget * 0.3 << "\n";
    cout << "Savings (20%): ₹" << totalBudget * 0.2 << "\n";
    cout << "Time Complexity: O(1)\n\n";
}

void knapsackDP(double budget) {
    vector<pair<double, double>> expenses = {
        {5000, 0.8}, {3000, 0.7}, {2000, 0.9}, 
        {1000, 0.6}, {4000, 0.85}, {2500, 0.75}
    };
    
    int n = expenses.size();
    vector<vector<double>> dp(n + 1, vector<double>((int)budget + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= budget; w++) {
            if (expenses[i-1].first <= w) {
                dp[i][w] = max(dp[i-1][w], 
                             dp[i-1][w - expenses[i-1].first] + expenses[i-1].second);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    
    cout << "🎒 DYNAMIC PROGRAMMING (0/1 Knapsack)\n";
    cout << "Budget Limit: ₹" << fixed << setprecision(2) << budget << "\n";
    cout << "Max Value Achievable: " << dp[n][budget] << "\n";
    cout << "Time Complexity: O(n × W)\n\n";
}

void dijkstraSavings() {
    vector<vector<pair<int, double>>> graph(4);
    graph[0] = {{1, 2000}, {2, 5000}};
    graph[1] = {{3, 1000}};
    graph[2] = {{3, 3000}};
    
    vector<double> dist(4, 1e9);
    dist[0] = 0;
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    pq.push({0, 0});
    
    while (!pq.empty()) {
        double cost = pq.top().first;
        int u = pq.top().second; pq.pop();
        if (cost > dist[u]) continue;
        
        for (auto p : graph[u]) {
            int v = p.first;
            double w = p.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    cout << "🗺️ DIJKSTRA (Min Cost to Savings Goal)\n";
    cout << "Min Cost Path: ₹" << fixed << setprecision(2) << dist[3] << "\n";
    cout << "Best Path: Current → Invest → Savings Goal\n";
    cout << "Time Complexity: O(E log V)\n\n";
}

void demoSearchSort() {
    vector<Expense> expenses = {
        {500, "Food", "2026-04"},
        {2000, "Travel", "2026-04"},
        {1000, "Bills", "2026-03"},
        {300, "Food", "2026-02"}
    };
    
    cout << "📊 SEARCH + SORT DEMO\n";
    cout << "Before Sort: ";
    for (auto &e : expenses) cout << e.amount << " ";
    cout << "\n";
    
    mergeSort(expenses, 0, expenses.size() - 1);
    cout << "After Merge Sort: ";
    for (auto &e : expenses) cout << e.amount << " ";
    cout << "\n";
    
    int target = 1000;
    int idx = binarySearch(expenses, target);
    cout << "Binary Search " << target << ": Index " << (idx != -1 ? to_string(idx) : "Not Found") << "\n\n";
}

// ===== MAIN: API READY =====
int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Usage: ./algorithms <budget> <greedy|dp|dijkstra|demo>\n";
        return 1;
    }
    
    double budget = stod(argv[1]);
    string algorithm = argv[2];
    
    cout << fixed << setprecision(2);
    
    if (algorithm == "greedy") {
        greedyBudget(budget);
    } else if (algorithm == "dp") {
        knapsackDP(budget);
    } else if (algorithm == "dijkstra") {
        dijkstraSavings();
    } else if (algorithm == "demo") {
        demoSearchSort();
    } else {
        cout << "Unknown algorithm\n";
        return 1;
    }
    
    return 0;
}




























/*


#include <bits/stdc++.h>
using namespace std;

// -----------------------------
// EXPENSE STRUCTURE
// -----------------------------
struct Expense {
    int amount;
    string category;
    string date;
};

// -----------------------------
// 🔍 LINEAR SEARCH
// Time Complexity: O(n)
// -----------------------------
int linearSearch(vector<Expense>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i].amount == target) {
            return i; // found
        }
    }
    return -1; // not found
}

// -----------------------------
// 🔍 BINARY SEARCH (sorted)
// Time Complexity: O(log n)
// -----------------------------
int binarySearch(vector<Expense>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid].amount == target)
            return mid;

        else if (arr[mid].amount < target)
            left = mid + 1;

        else
            right = mid - 1;
    }

    return -1;
}

// -----------------------------
// 🔃 MERGE SORT
// Time Complexity: O(n log n)
// -----------------------------
void merge(vector<Expense>& arr, int l, int m, int r) {
    vector<Expense> temp;

    int i = l, j = m + 1;

    while (i <= m && j <= r) {
        if (arr[i].amount <= arr[j].amount)
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= m) temp.push_back(arr[i++]);
    while (j <= r) temp.push_back(arr[j++]);

    for (int k = l; k <= r; k++) {
        arr[k] = temp[k - l];
    }
}

void mergeSort(vector<Expense>& arr, int l, int r) {
    if (l >= r) return;

    int mid = (l + r) / 2;

    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);

    merge(arr, l, mid, r);
}

// -----------------------------
// ⚡ QUICK SORT
// Time Complexity: O(n log n) avg
// -----------------------------
int partition(vector<Expense>& arr, int low, int high) {
    int pivot = arr[high].amount;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].amount < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<Expense>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// -----------------------------
// MAIN (Testing)
// -----------------------------
int main() {

    vector<Expense> expenses = {
        {500, "Food", "2026-04"},
        {2000, "Travel", "2026-04"},
        {1000, "Bills", "2026-03"},
        {300, "Food", "2026-02"}
    };

    // 🔃 Sort using Merge Sort
    mergeSort(expenses, 0, expenses.size() - 1);

    cout << "Sorted Expenses:\n";
    for (auto &e : expenses) {
        cout << e.amount << " " << e.category << endl;
    }

    // 🔍 Search
    int target = 1000;

    int index = binarySearch(expenses, target);

    if (index != -1)
        cout << "Found at index: " << index << endl;
    else
        cout << "Not Found\n";

    return 0;
}






*/