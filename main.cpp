#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // For better table formatting
#include "models/expense.h"
#include "sort/quicksort.cpp"   // Include your custom sorting
#include "search/binarysearch.cpp" // Include your custom search
#include "storage/persist.cpp"  // Include your file handling

using namespace std;

vector<Expense> expenses;
int idCounter = 1;

// Load data and sync the ID counter
void loadFromFile() {
    ifstream file("data.txt");
    if (!file.is_open()) return;
    
    Expense e;
    // Note: Ensure your persist.cpp uses the same format!
    while (file >> e.id >> e.description >> e.amount) {
        expenses.push_back(e);
        if (e.id >= idCounter) idCounter = e.id + 1;
    }
    file.close();
}

void displayHeader() {
    cout << "\n" << setfill('=') << setw(40) << "" << endl;
    cout << "  ID  |  Description       |  Amount" << endl;
    cout << setfill('-') << setw(40) << "" << setfill(' ') << endl;
}

int main() {
    loadFromFile();
    int choice;

    while (true) {
        cout << "\n--- SMART EXPENSE TRACKER (v1.0) ---\n";
        cout << "1. Add Expense\n";
        cout << "2. View All (Unsorted)\n";
        cout << "3. QuickSort (By Amount)\n"; // Showcase your sort folder
        cout << "4. Binary Search (By Amount)\n"; // Showcase your search folder
        cout << "5. Total Analytics\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Expense e;
            e.id = idCounter++;
            cout << "Description: "; cin >> e.description;
            cout << "Amount: ";      cin >> e.amount;
            expenses.push_back(e);
            saveExpenses(expenses); // Function from storage/persist.cpp
            cout << "Saved to disk.\n";

        } else if (choice == 2) {
            displayHeader();
            for (auto &e : expenses) 
                cout << setw(4) << e.id << " | " << setw(18) << left << e.description << " | Rs." << e.amount << endl;

        } else if (choice == 3) {
            if (expenses.empty()) continue;
            // Calling the logic from your sort/ folder
            quickSort(expenses, 0, expenses.size() - 1);
            cout << "Data sorted using QuickSort algorithm.\n";

        } else if (choice == 4) {
            if (expenses.empty()) continue;
            
            // CRITICAL: Binary search only works on sorted data
            quickSort(expenses, 0, expenses.size() - 1);
            
            float target;
            cout << "Enter exact amount to search: ";
            cin >> target;

            int idx = binarySearchAmount(expenses, target); // From search/ folder
            if (idx != -1) {
                cout << "Match Found: " << expenses[idx].description << " (ID: " << expenses[idx].id << ")\n";
            } else {
                cout << "No expense found with that amount.\n";
            }

        } else if (choice == 5) {
            float total = 0;
            for(auto &e : expenses) total += e.amount;
            cout << "Total Expenditure: Rs." << total << endl;

        } else if (choice == 6) {
            break;
        }
    }
    return 0;
}