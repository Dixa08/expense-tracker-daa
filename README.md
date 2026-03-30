# Expense Tracker - DAA Project

A C++ backend + HTML/JS frontend expense tracking system demonstrating core Data Structures and Algorithms.


## Team Members & Responsibilities

| Member   | Responsibility                        | Modules                                | Tech/Concepts                                                                         |
| -------- | ------------------------------------- | -------------------------------------- | ------------------------------------------------------------------------------------- |
| **Dixa** | **Backend Development (Core System)** | Sorting, Searching, Analytics, Storage | C++17, DSA (QuickSort, MergeSort, Binary Search, Hashing, DP, Greedy, Trie, File I/O) |
| Member 2 | Frontend UI                           | Dashboard, Forms, Display              | HTML, CSS, JavaScript                                                                 |
| Member 3 | Authentication                        | Login/Signup System                    | JS + Basic Backend Integration                                                        |
| Member 4 | Integration & Testing                 | Connecting frontend with backend       | API handling, Testing                                                                 |

---

## Backend Modules (Implemented by Dixa)

| Module    | Files                                                       | DAA Concept                 |
| --------- | ----------------------------------------------------------- | --------------------------- |
| Sorting   | backend/sort/quicksort.cpp, backend/sort/mergesort.cpp      | QuickSort, MergeSort        |
| Searching | backend/search/binarysearch.cpp, backend/search/hashmap.cpp | Binary Search, Hashing      |
| Analytics | backend/analytics/dp.cpp, backend/analytics/greedy.cpp      | Dynamic Programming, Greedy |
| Storage   | backend/storage/trie.cpp, backend/storage/persist.cpp       | Trie, File I/O              |

---

## How to Run Backend Modules

```bash
# Sorting
g++ -std=c++17 backend/sort/quicksort.cpp -o quicksort && ./quicksort
g++ -std=c++17 backend/sort/mergesort.cpp -o mergesort && ./mergesort

# Searching
g++ -std=c++17 backend/search/binarysearch.cpp -o bsearch && ./bsearch
g++ -std=c++17 backend/search/hashmap.cpp -o hashmap && ./hashmap

# Analytics
g++ -std=c++17 backend/analytics/dp.cpp -o dp && ./dp
g++ -std=c++17 backend/analytics/greedy.cpp -o greedy && ./greedy

# Storage
g++ -std=c++17 backend/storage/trie.cpp -o trie && ./trie
g++ -std=c++17 backend/storage/persist.cpp -o persist && ./persist
```

---





## Tech Stack

* **Backend:** C++17 (Core logic fully implemented)
* **Frontend:** HTML + CSS + JavaScript
* **Storage:** CSV file (expenses.csv)

---

## Project Description

This project is an Expense Tracker system focused on demonstrating strong backend implementation using Data Structures and Algorithms. The backend efficiently handles operations like sorting, searching, analytics, and storage, while the frontend provides a user-friendly interface.

---

## Features


* Efficient expense storage using file handling
* Fast searching using Binary Search & Hashing
* Optimized sorting using QuickSort & MergeSort
* Smart analytics using DP & Greedy approaches
* Scalable backend design using modular structure


# DAA Expense Tracker & Optimizer

## 🚀 Key Algorithms Implemented:
* **Divide & Conquer**: QuickSort and MergeSort for data organization.
* **Logarithmic Search**: Binary Search for price-point lookups.
* **Advanced Data Structures**: **Trie (Prefix Tree)** for $O(L)$ name searching and **HashMaps** for $O(1)$ category analysis.
* **Greedy Strategy**: Local optimum selection for budget cutting.
* **Dynamic Programming**: 0/1 Knapsack solution for global budget optimization.

## 📁 Structure
* `backend/`: Core logic and algorithm implementation.
* `data/`: CSV persistence layer.

  
---

## Note

This project follows a modular team-based structure where the backend focuses on implementing core Data Structures and Algorithms, while other components cover frontend design, authentication, and system integration. The work is organized to demonstrate both individual contributions and collaborative development.
