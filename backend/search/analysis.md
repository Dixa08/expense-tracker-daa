# Search Module — DAA Analysis (Member 2)

## Binary Search — Find expense by name

**Algorithm:** Decrease and Conquer
**Prerequisite:** Array must be sorted by description first.
**How it works:** Compare target with middle element. If smaller → search left half. If larger → search right half. Repeat.

| Case    | Time      | Reason                     |
|---------|-----------|----------------------------|
| Best    | O(1)      | Target is the middle element |
| Average | O(log n)  | Halves search space each step |
| Worst   | O(log n)  | Target at extreme end      |

**Space:** O(1) — no extra memory needed
**vs Linear Search:** For 1000 expenses, linear = 1000 steps worst case. Binary search = max 10 steps.

---

## HashMap — Filter by category

**Algorithm:** Hashing
**How it works:** One-time O(n) build of hash table mapping category → expense list. After that, any category lookup is O(1).

| Operation       | Time      |
|-----------------|-----------|
| Build map       | O(n)      |
| Lookup category | O(1) avg  |
| Insert expense  | O(1) avg  |

**Space:** O(n)
**Why HashMap?** Filtering without hash = O(n) scan every single time. With HashMap = O(1) per query after setup.
