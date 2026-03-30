#include <fstream>
#include <sstream>
#include <vector>
#include "../models/expense.h"

void loadAllFromCSV(std::string path, std::vector<Expense>& ex, int& idC) {
    ex.clear();
    std::ifstream file(path);
    std::string line; getline(file, line); // Skip Header
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string id, d, a, c;
        if (getline(ss,id,',') && getline(ss,d,',') && getline(ss,a,',') && getline(ss,c,',')) {
            ex.push_back({std::stoi(id), d, std::stof(a), c});
            if (std::stoi(id) >= idC) idC = std::stoi(id) + 1;
        }
    }
}

void saveAllToCSV(std::string path, const std::vector<Expense>& ex) {
    std::ofstream file(path);
    file << "ID,Description,Amount,Category\n";
    for (const auto& e : ex) file << e.id << "," << e.description << "," << e.amount << "," << e.category << "\n";
}