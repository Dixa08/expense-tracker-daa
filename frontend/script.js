let expenses = JSON.parse(localStorage.getItem("expenses")) || [];
let budget = 50000;

function addExpense() {
  let category = document.getElementById("category").value;
  let amount = parseInt(document.getElementById("amount").value);
  let date = document.getElementById("date").value;

  if (!amount || !date) return alert("Fill all fields");

  expenses.push({ category, amount, date });
  localStorage.setItem("expenses", JSON.stringify(expenses));

  updateUI();
}

function updateUI(data = expenses) {
  let total = data.reduce((s,e)=>s+e.amount,0);
  document.getElementById("total").innerText = total;
  document.getElementById("remaining").innerText = budget - total;

  let map = {};
  data.forEach(e=>{
    map[e.category]=(map[e.category]||0)+e.amount;
  });

  let keys = Object.keys(map);
  let top = keys.length ? keys.reduce((a,b)=>map[a]>map[b]?a:b) : "-";
  document.getElementById("top").innerText = top;

  drawCharts(map);
  updateTable(data);
}

function updateTable(data = expenses) {
  let table = document.getElementById("table");

  table.innerHTML = `
    <tr>
      <th>Date</th>
      <th>Category</th>
      <th>Amount</th>
      <th>Action</th>
    </tr>
  `;

  data.forEach((e, index) => {
    table.innerHTML += `
      <tr>
        <td>${e.date}</td>
        <td>${e.category}</td>
        <td>${e.amount}</td>
        <td><button onclick="deleteExpense(${index})">Delete</button></td>
      </tr>
    `;
  });
}

function deleteExpense(index) {
  expenses.splice(index, 1);
  localStorage.setItem("expenses", JSON.stringify(expenses));
  updateUI();
}

function searchExpense() {
  let text = document.getElementById("search").value.toLowerCase();
  updateUI(expenses.filter(e=>e.category.toLowerCase().includes(text)));
}

function sortExpense() {
  let type = document.getElementById("sort").value;
  let sorted = [...expenses];

  if(type==="Amount") sorted.sort((a,b)=>a.amount-b.amount);
  else if(type==="Date") sorted.sort((a,b)=>new Date(a.date)-new Date(b.date));
  else sorted.sort((a,b)=>a.category.localeCompare(b.category));

  updateUI(sorted);
}

let pie,bar,line;

function drawCharts(data){
  let labels = Object.keys(data);
  let values = Object.values(data);

  if(pie) pie.destroy();
  if(bar) bar.destroy();
  if(line) line.destroy();

  pie = new Chart(pieChart,{
    type:'pie',
    data:{labels,datasets:[{data:values}]}
  });

  bar = new Chart(barChart,{
    type:'bar',
    data:{labels,datasets:[{data:values}]}
  });

  line = new Chart(lineChart,{
    type:'line',
    data:{
      labels:["Jan","Feb","Mar","Apr","May"],
      datasets:[{data:[5000,8000,12000,15000,20000]}]
    }
  });
}

updateUI();
