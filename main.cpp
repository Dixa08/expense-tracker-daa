#include <iostream>
#include <vector>
using namespace std;

// Define Expense first
struct Expense {
    int id;
    string description;
    float amount;
};

// QuickSort functions
int partition(vector<Expense>& arr, int low, int high) {
    float pivot = arr[high].amount;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].amount <= pivot) {
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

int main() {
    vector<Expense> expenses;
    int choice, id = 1;

    while (true) {
        cout << "\n====== EXPENSE TRACKER ======\n";
        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Expense e;
            e.id = id++;

            cout << "Enter description: ";
            cin >> e.description;

            cout << "Enter amount: ";
            cin >> e.amount;

            expenses.push_back(e);
            cout << "Expense added!\n";
        }
        else if (choice == 2) {
            cout << "\n--- All Expenses ---\n";
            quickSort(expenses, 0, (int)expenses.size() - 1);
            for (auto e : expenses) {
                cout << e.id << " | " << e.description << " | Rs." << e.amount << endl;
            }
        }
        else if (choice == 3) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}