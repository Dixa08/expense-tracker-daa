let expenses = JSON.parse(localStorage.getItem("expenses")) || [];

function addExpense() {
    let date = document.getElementById("date").value;
    let category = document.getElementById("category").value;
    let amount = document.getElementById("amount").value;

    if (!date || !category || !amount) {
        alert("Fill all fields");
        return;
    }

    let expense = { date, category, amount };
    expenses.push(expense);

    localStorage.setItem("expenses", JSON.stringify(expenses));

    display();
}

function deleteExpense(index) {
    expenses.splice(index, 1);
    localStorage.setItem("expenses", JSON.stringify(expenses));
    display();
}

function display() {
    let table = document.getElementById("tableBody");
    table.innerHTML = "";

    let total = 0;
    let categories = {};

    expenses.forEach((e, i) => {
        total += Number(e.amount);

        if (!categories[e.category]) {
            categories[e.category] = 0;
        }
        categories[e.category] += Number(e.amount);

        let row = `
        <tr>
            <td>${e.date}</td>
            <td>${e.category}</td>
            <td>${e.amount}</td>
            <td><button onclick="deleteExpense(${i})">Delete</button></td>
        </tr>`;
        table.innerHTML += row;
    });

    // update cards
    document.getElementById("total").innerText = total;
    document.getElementById("count").innerText = expenses.length;

    let top = Object.keys(categories).reduce((a, b) =>
        categories[a] > categories[b] ? a : b, "-");

    document.getElementById("topCat").innerText = top;

    showCharts(categories);
}

function showCharts(categories) {
    let labels = Object.keys(categories);
    let data = Object.values(categories);

    let colors = ["red", "blue", "green", "orange"];

    if (window.pie) window.pie.destroy();
    if (window.bar) window.bar.destroy();

    let pieCtx = document.getElementById("pieChart");
    let barCtx = document.getElementById("barChart");

    window.pie = new Chart(pieCtx, {
        type: "pie",
        data: {
            labels: labels,
            datasets: [{
                data: data,
                backgroundColor: colors
            }]
        }
    });

    window.bar = new Chart(barCtx, {
        type: "bar",
        data: {
            labels: labels,
            datasets: [{
                label: "Expenses",
                data: data,
                backgroundColor: colors
            }]
        }
    });
}

// initial load
display();
