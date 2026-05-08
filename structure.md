

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
