#include <iostream>
#include <vector>
#include <iomanip>

#include "models/expense.h"
#include "sort/quicksort.cpp"
#include "sort/mergesort.cpp"
#include "search/binarysearch.cpp"
#include "search/hashmap.cpp"
#include "analytics/greedy.cpp"
#include "analytics/dp.cpp"
#include "storage/file_handler.cpp"
#include "storage/trie.cpp"

using namespace std;

vector<Expense> expenses;
int idCounter = 1;
string PATH = "../data/expenses.csv";

int main() {
    int choice;
    ExpenseTrie trie;
    while (true) {
        cout << "\n1.Load 2.Add 3.QuickSort 4.MergeSort 5.BinSearch 6.TrieSearch 7.Hash 8.Greedy 9.DP 10.View 11.Exit\nChoice: ";
        if (!(cin >> choice)) { cin.clear(); cin.ignore(1000, '\n'); continue; }

        if (choice == 1) { loadAllFromCSV(PATH, expenses, idCounter); for(int i=0; i<expenses.size(); i++) trie.insert(expenses[i].description, i); cout << "Loaded!\n"; }
        else if (choice == 2) { Expense e; e.id = idCounter++; cout << "Desc Amt Cat: "; cin >> e.description >> e.amount >> e.category; expenses.push_back(e); saveAllToCSV(PATH, expenses); trie.insert(e.description, expenses.size()-1); }
        else if (choice == 3) { quickSort(expenses, 0, expenses.size()-1); cout << "Sorted (Quick)!\n"; }
        else if (choice == 4) { mergeSort(expenses, 0, expenses.size()-1); cout << "Sorted (Merge)!\n"; }
        else if (choice == 5) { float a; cout << "Amt: "; cin >> a; quickSort(expenses, 0, expenses.size()-1); int i = binarySearchAmount(expenses, a); if(i!=-1) cout << "Found: " << expenses[i].description << endl; else cout << "Not found\n"; }
        else if (choice == 6) { string s; cout << "Name: "; cin >> s; int i = trie.search(s); if(i!=-1) cout << "Found: Rs." << expenses[i].amount << endl; else cout << "Not found\n"; }
        else if (choice == 7) analyzeCategoriesWithHash(expenses);
        else if (choice == 8) { float b; cout << "Budget: "; cin >> b; greedyBudgetSelection(expenses, b); }
        else if (choice == 9) { float b; cout << "Budget: "; cin >> b; dpBudgetOptimization(expenses, b); }
        else if (choice == 10) { for(auto& e : expenses) cout << e.id << " | " << e.description << " | Rs." << e.amount << " | " << e.category << endl; }
        else if (choice == 11) break;
    }
    return 0;
}