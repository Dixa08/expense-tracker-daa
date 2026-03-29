#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>

struct Expense {
    int id;
    std::string description;
    float amount;
};

#endif