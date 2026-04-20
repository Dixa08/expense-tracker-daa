// Simple API server

const express = require("express");
const cors = require("cors");

const app = express();
app.use(cors());
app.use(express.json());

// In-memory data (for now)
let expenses = [];

// -----------------------------
// GET ALL EXPENSES
// -----------------------------
app.get("/expenses", (req, res) => {
    res.json(expenses);
});

// -----------------------------
// ADD EXPENSE
// -----------------------------
app.post("/expenses", (req, res) => {
    const expense = req.body;
    expenses.push(expense);
    res.json({ message: "Expense added" });
});

// -----------------------------
// ANALYTICS
// -----------------------------
app.get("/analytics", (req, res) => {

    let total = expenses.reduce((sum, e) => sum + e.amount, 0);

    res.json({
        totalExpense: total
    });
});

// -----------------------------
// PREDICTION
// -----------------------------
app.get("/predict", (req, res) => {

    if (expenses.length === 0) {
        return res.json({ prediction: 0 });
    }

    let total = expenses.reduce((sum, e) => sum + e.amount, 0);
    let avg = total / expenses.length;

    res.json({
        prediction: Math.round(avg)
    });
});


// 🏠 Home route (optional)
app.get("/", (req, res) => {
    res.send("Expense Tracker API is running 🚀");
});

// TEMP TEST - Add before app.listen
app.get('/test', (req, res) => {
    res.json({ message: "DAA routes loaded!" });
});


// DAA Endpoints
// SIMPLE DAA (Pure JS)
app.get('/daa/:algorithm/:budget', (req, res) => {
    const { algorithm, budget = 50000 } = req.params;
    let result = '';
    
    if (algorithm === 'greedy') {
        result = `⚡ GREEDY (50-30-20 Rule)
Needs: ₹${budget*0.5}
Wants: ₹${budget*0.3}
Savings: ₹${budget*0.2}`;
    } else if (algorithm === 'dp') {
        result = `🎒 DP Knapsack
Max value in ₹${budget}: ${budget*0.8}`;
    } else if (algorithm === 'dijkstra') {
        result = `🗺️ Dijkstra
Min cost to savings: ₹5000`;
    }
    
    res.json({ algorithm, budget, result });
});

// -----------------------------
app.listen(5000, () => {
    console.log("Server running on http://localhost:5000");
});