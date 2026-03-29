let expenses = JSON.parse(localStorage.getItem("expenses")) || [];

function addExpense() {
    let date = document.getElementById("date").value;
    let category = document.getElementById("category").value;
    let amount = document.getElementById("amount").value;

    if (!date || !category || !amount) {
        alert("Fill all fields!");
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

    expenses.forEach((e, index) => {
        total += Number(e.amount);

        let row = `<tr>
            <td>${e.date}</td>
            <td>${e.category}</td>
            <td>${e.amount}</td>
            <td><button onclick="deleteExpense(${index})">Delete</button></td>
        </tr>`;

        table.innerHTML += row;
    });

    document.getElementById("total").innerText = "Total: ₹ " + total;
}

display();
