#pragma once
#include <string>
using namespace std;

struct Expense {
    int    id;
    string description;
    float  amount;
    string category;
    string date;   // "YYYY-MM-DD"
    string mode;   // "UPI", "Cash", "Card"
};
