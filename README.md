# Expense Tracker - DAA Project

A C++ backend + HTML/JS frontend expense tracking system demonstrating core Data Structures and Algorithms.

## Team Members & Modules

| Member | Module | Files | DAA Concept |
|--------|--------|-------|-------------|
| Member 1 | Sorting | sort/quicksort.cpp, sort/mergesort.cpp | QuickSort, MergeSort |
| Member 2 | Searching | search/binarysearch.cpp, search/hashmap.cpp | Binary Search, Hashing |
| Member 3 | Analytics | analytics/dp.cpp, analytics/greedy.cpp | Dynamic Programming, Greedy |
| Member 4 | Storage | storage/trie.cpp, storage/persist.cpp | Trie, File I/O |

## How to Run Each Module

```bash
# Member 1
g++ -std=c++17 backend/sort/quicksort.cpp -o quicksort && ./quicksort
g++ -std=c++17 backend/sort/mergesort.cpp -o mergesort && ./mergesort

# Member 2
g++ -std=c++17 backend/search/binarysearch.cpp -o bsearch && ./bsearch
g++ -std=c++17 backend/search/hashmap.cpp -o hashmap && ./hashmap

# Member 3
g++ -std=c++17 backend/analytics/dp.cpp -o dp && ./dp
g++ -std=c++17 backend/analytics/greedy.cpp -o greedy && ./greedy

# Member 4
g++ -std=c++17 backend/storage/trie.cpp -o trie && ./trie
g++ -std=c++17 backend/storage/persist.cpp -o persist && ./persist
```

## Tech Stack
- **Backend:** C++17
- **Frontend:** HTML + CSS + JavaScript
- **Storage:** CSV file (expenses.csv)

## File Structure
See project tree below.
