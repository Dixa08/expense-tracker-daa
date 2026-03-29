#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include "models/expense.h"
#include "sort/quicksort.cpp"
#include "search/binarysearch.cpp"

using namespace std;

// Global Data Structures
vector<Expense> expenses;
int idCounter = 1;

// ---------------- LOAD FROM CSV ----------------
void loadFromCSV() {
    expenses.clear(); 
    ifstream file("expenses.csv");
    
    if (!file.is_open()) {
        cout << "System: Starting with a fresh database (no CSV found).\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        
        stringstream ss(line);
        string idStr, desc, amtStr, cat;

        try {
            getline(ss, idStr, ',');
            getline(ss, desc, ',');
            getline(ss, amtStr, ',');
            getline(ss, cat, ',');

            Expense e;
            e.id = stoi(idStr);
            e.description = desc;
            e.amount = stof(amtStr);
            // e.category = cat; // Uncomment if your struct has category

            expenses.push_back(e);
            if (e.id >= idCounter) idCounter = e.id + 1;
        } catch (...) {
            continue; // Skip malformed lines
        }
    }
    file.close();
}

// ---------------- SAVE TO CSV ----------------
void saveToCSV() {
    ofstream file("expenses.csv");
    for (auto &e : expenses) {
        file << e.id << "," << e.description << "," << e.amount << ",General" << endl;
    }
    file.close();
}

// ---------------- ADD ----------------
void addExpense() {
    Expense e;
    e.id = idCounter++;
    cout << "Enter Description (single word): ";
    cin >> e.description;
    cout << "Enter Amount: ";
    cin >> e.amount;

    expenses.push_back(e);
    saveToCSV();
    cout << "Success: Data saved to CSV.\n";
}

// ---------------- VIEW ----------------
void viewExpenses() {
    if (expenses.empty()) {
        cout << "List is empty.\n";
        return;
    }
    cout << "\nID | Description | Amount\n";
    cout << "--------------------------\n";
    for (auto &e : expenses) {
        cout << e.id << " | " << setw(11) << left << e.description << " | Rs." << e.amount << endl;
    }
}

// ---------------- MAIN MENU ----------------
int main() {
    loadFromCSV(); // Run automatically on startup

    int choice;
    while (true) {
        cout << "\n=== DAA EXPENSE TRACKER (CSV BACKEND) ===\n";
        cout << "1. Add Expense\n";
        cout << "2. View All\n";
        cout << "3. QuickSort (By Amount)\n";
        cout << "4. Binary Search (By Amount)\n";
        cout << "5. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            addExpense();
        } else if (choice == 2) {
            viewExpenses();
        } else if (choice == 3) {
            if (expenses.empty()) continue;
            quickSort(expenses, 0, expenses.size() - 1);
            cout << "Sorted using QuickSort (Divide & Conquer).\n";
            viewExpenses();
        } else if (choice == 4) {
            if (expenses.empty()) continue;
            
            // Binary search requires sorting
            quickSort(expenses, 0, expenses.size() - 1);
            
            float target;
            cout << "Enter exact amount to search: ";
            cin >> target;

            int idx = binarySearchAmount(expenses, target);
            if (idx != -1) {
                cout << "Match Found: " << expenses[idx].description << " (ID: " << expenses[idx].id << ")\n";
            } else {
                cout << "Record not found.\n";
            }
        } else if (choice == 5) {
            saveToCSV(); // Final save
            break;
        }
    }
    return 0;
}