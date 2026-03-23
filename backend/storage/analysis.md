# Storage Module — DAA Analysis (Member 4)

## Trie — Autocomplete for expense names

**Algorithm:** Trie (Prefix Tree)
**How it works:** Each character is a node. Words are paths root → leaf. To search a prefix, walk character by character — O(m) regardless of how many words exist.

| Operation       | Time         | Reason              |
|-----------------|--------------|---------------------|
| Insert word     | O(m)         | m = word length     |
| Search prefix   | O(m)         | Walk m nodes        |
| Get suggestions | O(m + k)     | k = results count   |

**Space:** O(ALPHABET_SIZE × m × n) where n = total words
**vs Linear scan:** Without Trie, autocomplete = O(n × m) scan all words each time. Trie = O(m) always.

---

## File Persistence — Save/Load expenses as CSV

**Algorithm:** Sequential scan + string tokenization
**How it works:** Write each expense as one comma-separated line. Load by reading line-by-line and splitting at each comma with `stringstream`.

| Operation     | Time  | Reason                     |
|---------------|-------|----------------------------|
| Save n items  | O(n)  | One write per expense      |
| Load n items  | O(n)  | One read + parse per line  |
| Parse one line | O(k) | k = number of characters   |

**Space:** O(n) for the loaded vector
**Why CSV?** Simple, human-readable, importable into Excel. No external library needed — pure C++ file I/O.
