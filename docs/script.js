// Chart instances (we store them to update later)
let pieChart;
let barChart;


let user = JSON.parse(localStorage.getItem("user")) || null;
let expenses = JSON.parse(localStorage.getItem("expenses")) || [];

const form = document.getElementById("expenseForm");
const table = document.getElementById("expenseTable");

const totalExpenseEl = document.getElementById("totalExpense");
const remainingBudgetEl = document.getElementById("remainingBudget");
const savingsGoalEl = document.getElementById("savingsGoal");

// 🔙 RESET USER (start fresh)
function resetUser() {

    // remove stored data
    localStorage.removeItem("user");
    localStorage.removeItem("expenses");

    // reload page
    location.reload();
}



// Temporary fixed values (we'll make user profile later)
let salary = 50000;
let savingsGoal = 10000;


// 🚀 ADD EXPENSE USING API 
form.addEventListener("submit", async function(e) {
    e.preventDefault();

    const expense = {
        amount: Number(document.getElementById("amount").value),
        category: document.getElementById("category").value,
        date: document.getElementById("date").value,
        desc: document.getElementById("desc").value
    };

    // 🔗 SEND DATA TO BACKEND API
    await fetch("http://localhost:5000/expenses", {
        method: "POST",
        headers: {
            "Content-Type": "application/json"
        },
        body: JSON.stringify(expense)
    });

    // 🔄 Reload data from server
    loadExpenses();

    form.reset();
});


// SAVE DATA
function saveData() {
    localStorage.setItem("expenses", JSON.stringify(expenses));
}

// RENDER EVERYTHING
function renderAll() {
    renderTable();
    updateDashboard();
    updateCharts(); // NEW: update charts whenever data changes
    runAnalytics(); // NEW: alerts + insights
    runPrediction(); // NEW 🔮
    showMonthlySummary(); // ✅ ADD THIS LINE
}

// TABLE
function renderTable() {
    table.innerHTML = "";

    expenses.forEach((exp, index) => {
        const row = `
            <tr>
                <td>₹${exp.amount}</td>
                <td>${exp.category}</td>
                <td>${exp.date}</td>
                <td>${exp.desc}</td>
                <td>
                    <button onclick="editExpense(${index})">Edit</button>
                    <button onclick="deleteExpense(${index})">Delete</button>
                </td>
            </tr>
        `;
        table.innerHTML += row;
    });
}

// DELETE
function deleteExpense(index) {
    expenses.splice(index, 1);
    saveData();
    renderAll();
}

// EDIT
function editExpense(index) {
    const exp = expenses[index];

    document.getElementById("amount").value = exp.amount;
    document.getElementById("category").value = exp.category;
    document.getElementById("date").value = exp.date;
    document.getElementById("desc").value = exp.desc;

    // remove old entry
    expenses.splice(index, 1);

    saveData();
    renderAll();
}

// DASHBOARD CALCULATIONS
function updateDashboard() {
    let total = expenses.reduce((sum, exp) => sum + exp.amount, 0);

    let remaining = salary - total;

    totalExpenseEl.innerText = "₹" + total;
    remainingBudgetEl.innerText = "₹" + remaining;
    savingsGoalEl.innerText = "₹" + savingsGoal;
}


//step 2.5...pop up
function saveProfile() {
    const name = document.getElementById("nameInput").value;
    const salaryInput = Number(document.getElementById("salaryInput").value);
    const goalInput = Number(document.getElementById("goalInput").value);

    user = {
        name: name,
        salary: salaryInput,
        savingsGoal: goalInput
    };

    localStorage.setItem("user", JSON.stringify(user));

    document.getElementById("setupScreen").style.display = "none";

    loadUser();
    renderAll();
}

function loadUser() {
    if (user) {
        document.getElementById("username").innerText = user.name;
        salary = user.salary;
        savingsGoal = user.savingsGoal;

        document.getElementById("setupScreen").style.display = "none";
    }
}
function updateCharts() {

    // -------------------------
    // CATEGORY DATA (PIE CHART)
    // -------------------------
    let categoryData = {};

    expenses.forEach(exp => {
        if (!categoryData[exp.category]) {
            categoryData[exp.category] = 0;
        }
        categoryData[exp.category] += exp.amount;
    });

    const pieLabels = Object.keys(categoryData);
    const pieValues = Object.values(categoryData);

    // Destroy old chart before creating new one (important)
    if (pieChart) {
        pieChart.destroy();
    }

    pieChart = new Chart(document.getElementById("pieChart"), {
        type: "pie",
        data: {
            labels: pieLabels,
            datasets: [{
                data: pieValues
            }]
        }
    });


// -------------------------
// MONTHLY DATA (BAR CHART)
 // -------------------------
let monthlyData = {};

expenses.forEach(exp => {
        let month = exp.date.substring(0, 7); // YYYY-MM

        if (!monthlyData[month]) {
            monthlyData[month] = 0;
        }
        monthlyData[month] += exp.amount;
    });

const barLabels = Object.keys(monthlyData);
const barValues = Object.values(monthlyData);

    if (barChart) {
        barChart.destroy();
    }

    barChart = new Chart(document.getElementById("barChart"), {
        type: "bar",
        data: {
            labels: barLabels,
            datasets: [{
            label: "Monthly Trend",
            data: barValues,
            fill: false,
            tension: 0.3

            }]
        }
    });
}

// 🚨 Alerts + 📊 Analytics
function runAnalytics() {

    let total = expenses.reduce((sum, exp) => sum + exp.amount, 0);

    // 🔴 ALERT 1: Total exceeds budget
    let budget = salary - savingsGoal;

    let alertText = "";

    if (total > budget) {
        alertText = "⚠️ You exceeded your total budget!";
    }

    // -------------------------
    // CATEGORY ANALYSIS
    // -------------------------
    let categoryData = {};

    expenses.forEach(exp => {
        if (!categoryData[exp.category]) {
            categoryData[exp.category] = 0;
        }
        categoryData[exp.category] += exp.amount;
    });

    // 🔍 Find highest spending category
    let maxCategory = "";
    let maxValue = 0;

    for (let cat in categoryData) {
        if (categoryData[cat] > maxValue) {
            maxValue = categoryData[cat];
            maxCategory = cat;
        }
    }

    // 🟠 ALERT 2: High spending in one category
    if (maxValue > budget * 0.5) {
        alertText = `⚠️ You are spending too much on ${maxCategory}`;
    }

    // 🟢 If no alerts
    if (alertText === "") {
        alertText = `👍 Good job! Your highest spending is on ${maxCategory}`;
    }

    // Show alert
    document.getElementById("alertMessage").innerText = alertText;
}

// 🔮 Prediction Logic
function runPrediction() {

    if (expenses.length === 0) {
        document.getElementById("predictionText").innerText = "Add expenses to see prediction";
        return;
    }

    // -------------------------
    // GROUP BY MONTH
    // -------------------------
    let monthlyData = {};

    expenses.forEach(exp => {
        let month = exp.date.substring(0, 7); // YYYY-MM

        if (!monthlyData[month]) {
            monthlyData[month] = 0;
        }

        monthlyData[month] += exp.amount;
    });

    let values = Object.values(monthlyData);

    // -------------------------
    // SIMPLE AVERAGE PREDICTION
    // -------------------------
    let sum = values.reduce((a, b) => a + b, 0);
    let avg = Math.round(sum / values.length);

    // -------------------------
    // SHOW RESULT
    // -------------------------
    document.getElementById("predictionText").innerText =
        `📊 Estimated next month expense: ₹${avg}`;
}


// 📥 LOAD EXPENSES FROM API
async function loadExpenses() {

    const res = await fetch("http://localhost:5000/expenses");
    expenses = await res.json();

    renderAll(); // update UI
}

// 🔍 SEARCH (Linear Search concept)
function searchExpense() {

    const value = Number(document.getElementById("searchAmount").value);

    // Filter matching expenses
    const result = expenses.filter(exp => exp.amount === value);

    if (result.length === 0) {
        alert("No expense found");
        return;
    }

    // Show only searched results
    table.innerHTML = "";

    result.forEach(exp => {
        const row = `
            <tr>
                <td>₹${exp.amount}</td>
                <td>${exp.category}</td>
                <td>${exp.date}</td>
                <td>${exp.desc}</td>
                <td>-</td>
            </tr>
        `;
        table.innerHTML += row;
    });
}
// 🔃 SORT ASC (like Quick/Merge sort)
function sortAsc() {

    expenses.sort((a, b) => a.amount - b.amount);

    renderTable();
}
// 🔃 SORT DESC
function sortDesc() {

    expenses.sort((a, b) => b.amount - a.amount);

    renderTable();
}



// 📅 Monthly Summary (NEW FUNCTION)
function showMonthlySummary() {

    let monthlyData = {};

    expenses.forEach(exp => {
        let month = exp.date.substring(0, 7); // YYYY-MM

        if (!monthlyData[month]) {
            monthlyData[month] = 0;
        }

        monthlyData[month] += exp.amount;
    });

    const list = document.getElementById("monthlyList");

    if (!list) return; // safety (if HTML not added yet)

    list.innerHTML = "";

    for (let m in monthlyData) {
        list.innerHTML += `<li>${m} : ₹${monthlyData[m]}</li>`;
    }
}



// 🧠 DAA Functions (ADD THESE AT BOTTOM)
let daaLoading = false;

async function runDAA(algorithm) {
    if (daaLoading) return;
    
    const budgetInput = document.getElementById('daaBudget');
    const budget = budgetInput.value || 50000;
    const resultDiv = document.getElementById('daa-result');
    
    daaLoading = true;
    resultDiv.innerHTML = `🔄 Running ${algorithm.toUpperCase()}...\nConnecting to C++ backend...`;
    resultDiv.style.opacity = '0.7';
    
    try {
        const response = await fetch(`http://localhost:5000/daa/${algorithm}/${budget}`);
        if (!response.ok) throw new Error(`API Error: ${response.status}`);
        
        const data = await response.json();
        resultDiv.innerHTML = 
            `💰 Budget: ₹${data.budget.toLocaleString()}\n` +
            `⚙️ Algorithm: ${data.algorithm.toUpperCase()}\n` +
            `⏰ Time: ${new Date(data.timestamp).toLocaleTimeString()}\n\n` +
            `${data.result}`;
        resultDiv.style.opacity = '1';
        
    } catch (error) {
        resultDiv.innerHTML = 
            `❌ Error: ${error.message}\n\n` +
            `💡 Run backend: cd backend-api && node server.js`;
        resultDiv.style.color = '#ff6b6b';
    } finally {
        daaLoading = false;
    }
}

function showDAASection() {
    const daaSection = document.getElementById('daa-section');
    if (user && user.salary) {
        daaSection.style.display = 'block';
        document.getElementById('daaBudget').value = user.salary;
    }
}

// UPDATE loadUser() - ADD THIS LINE AT END
// Find your loadUser() function and add:
function loadUser() {
    if (user) {
        document.getElementById("username").innerText = user.name;
        salary = user.salary;
        savingsGoal = user.savingsGoal;
        document.getElementById("setupScreen").style.display = "none";
    }
    showDAASection(); // ADD THIS LINE
}

// INITIAL LOAD
loadUser();
loadExpenses(); // this will internally call renderAll()