

[![Live Demo](https://img.shields.io/badge/Live-Demo-brightgreen)](https://dixa08.github.io/expense-tracker-daa/)
[![GitHub](https://img.shields.io/badge/GitHub-Repo-black)](https://github.com/Dixa08/expense-tracker-daa)

## 🚀 [Live Demo](https://dixa08.github.io/expense-tracker-daa/)

<div align="center">

# 💰 Expense Tracker + DAA Algorithms

### A full-stack expense management system with real-world Design & Analysis of Algorithms implementation

[![Live Demo](https://img.shields.io/badge/🌐_Live_Demo-GitHub_Pages-2ea44f?style=for-the-badge)](https://dixa08.github.io/expense-tracker-daa/)
[![GitHub Repo](https://img.shields.io/badge/📁_GitHub-Repo-181717?style=for-the-badge&logo=github)](https://github.com/Dixa08/expense-tracker-daa)
[![Algorithms](https://img.shields.io/badge/🧠_Algorithms-Greedy_|_DP_|_Dijkstra-blue?style=for-the-badge)]()
[![Made With](https://img.shields.io/badge/Made_With-C++_|_Node.js_|_JS-orange?style=for-the-badge)]()

</div>

---

## 📌 Overview

> A **full-stack expense tracker** that combines intuitive UI with powerful **DAA (Design and Analysis of Algorithms)** under the hood — built as a portfolio and academic project.

- Set your monthly income/budget
- Add and categorize daily expenses
- View live charts that update dynamically
- Apply **real algorithms** (Greedy / DP / Dijkstra) for smart financial analysis
- Deployed live via **GitHub Pages** + local Node.js API

---

## ✨ Features

| Feature | Description |
|--------|-------------|
| 📊 **Live Charts** | Pie & bar charts update dynamically with every expense entry |
| 🧠 **DAA Algorithms** | Greedy, Dynamic Programming, and Dijkstra — working on real data |
| ⚡ **REST API** | Node.js + Express backend with full CRUD endpoints |
| 📱 **Responsive UI** | Mobile-first design — works on all screen sizes |
| 🚨 **Budget Alerts** | Real-time warning when spending exceeds budget threshold |
| 💾 **Persistent Data** | Expenses saved and retrieved via backend API |

---

## 🧠 DAA Algorithms Explained

### 1. 🟢 Greedy Algorithm — Budget Allocation
**Use case:** Splits your income using the **50-30-20 rule**

```
Income ₹50,000
├── 50% → Needs     ₹25,000  (rent, food, bills)
├── 30% → Wants     ₹15,000  (entertainment, dining)
└── 20% → Savings   ₹10,000  (emergency fund, investments)
```

**Why Greedy?** Makes locally optimal choices at each step (allocate to most critical need first), leading to a globally optimal budget split.

---

### 2. 🔵 Dynamic Programming — Expense Knapsack
**Use case:** Maximize value of expenses within a fixed budget

```
Given budget B and list of expenses with (cost, value):
  dp[i][w] = max value using first i items with weight ≤ w
```

Helps answer: *"Which expenses give me the best value within ₹X?"*

---

### 3. 🟣 Dijkstra's Algorithm — Savings Path
**Use case:** Find the shortest (cheapest) path to reach a savings goal across spending categories

```
Graph nodes = expense categories
Edge weights = cost to transition / reduce spending
Dijkstra finds: minimum-cost savings route
```

---

## 🛠️ Tech Stack

```
Frontend        →  HTML5 · CSS3 · JavaScript · Chart.js
Backend API     →  Node.js · Express.js · REST
Algorithms      →  C++ (compiled) + optional JS bridge
Deployment      →  GitHub Pages (frontend) · localhost:5000 (API)
```

---

## 📁 Project Structure

```
expense-tracker-daa/
│
├── 🟢 frontend/                  # Live on GitHub Pages
│   ├── index.html           # Main app UI
│   ├── style.css            # Responsive styles
│   └── script.js            # Charts + API calls + DAA UI
│
├── 🔵 backend-api/              # REST API (localhost:5000)
│   ├── server.js            # Express routes + DAA logic
│   ├── package.json
│   └── daa-bridge.js        # C++ ↔ Node.js bridge (optional)
│
├── 🟣 backend/                  # C++ DAA Engine
│   ├── algorithms.cpp       # Greedy · DP · Dijkstra
│   └── algorithms.exe       # Compiled binary
│
└── README.md
```

---

## 🚀 Getting Started

### Run Frontend (Live)
```bash
# Already deployed!
# Visit: https://dixa08.github.io/expense-tracker-daa/
```

### Run Backend API (Local)
```bash
cd backend-api
npm install
node server.js
# API running at http://localhost:5000
```

### Compile C++ Algorithms
```bash
cd backend
g++ -o algorithms algorithms.cpp
./algorithms
```

---

## 🎯 Viva Demo Flow (2 Minutes)

```
Step 1  →  Open live site: https://dixa08.github.io/expense-tracker-daa/
Step 2  →  Set monthly income: ₹50,000
Step 3  →  Add 3–4 sample expenses (food, rent, entertainment)
Step 4  →  Click "Greedy" → Show 50-30-20 budget split
Step 5  →  Open GitHub → Show algorithms.cpp source code
Step 6  →  Explain DP / Dijkstra logic from code
```

---

## 📊 API Endpoints

| Method | Endpoint | Description |
|--------|----------|-------------|
| `GET` | `/api/expenses` | Fetch all expenses |
| `POST` | `/api/expenses` | Add new expense |
| `DELETE` | `/api/expenses/:id` | Delete an expense |
| `GET` | `/api/algorithm/greedy` | Run Greedy budget split |
| `GET` | `/api/algorithm/dp` | Run DP knapsack |
| `GET` | `/api/algorithm/dijkstra` | Run Dijkstra savings path |

---

## 📸 Screenshots

> 🌐 [Live App](https://dixa08.github.io/expense-tracker-daa/) · 📁 [GitHub Repo](https://github.com/Dixa08/expense-tracker-daa)

---

## 👤 Author

**Dixa08**  
📧 *Computer Science Student*  
🔗 [GitHub Profile](https://github.com/Dixa08)

---

## 🎓 Resume Line

```
Full-stack Expense Tracker with DAA (Greedy/DP/Dijkstra) | Live Demo | GitHub Pages
```

---

## 📄 License

This project is open source and available under the [MIT License](LICENSE).

---

<div align="center">

⭐ **If this project helped you, give it a star!** ⭐

Made with ❤️ for academic excellence + portfolio impact

</div>
