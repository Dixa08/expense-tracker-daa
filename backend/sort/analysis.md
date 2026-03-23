# Sort Module — DAA Analysis (Member 1)

## QuickSort — Sort by Amount

**Algorithm:** Divide and Conquer
**How it works:** Pick pivot (last element). Partition so all smaller amounts go left, larger go right. Recurse on both halves.

| Case    | Time       | Reason                          |
|---------|------------|---------------------------------|
| Best    | O(n log n) | Pivot always splits evenly      |
| Average | O(n log n) | Random data, balanced splits    |
| Worst   | O(n²)      | Already sorted, pivot is always min/max |

**Space:** O(log n) — recursive call stack
**Why QuickSort for amount?** In-place, very fast in practice for random expense values.

---

## MergeSort — Sort by Date

**Algorithm:** Divide and Conquer
**How it works:** Split array in half until size 1. Merge sorted halves comparing date strings.

| Case    | Time       | Reason                     |
|---------|------------|----------------------------|
| Best    | O(n log n) | Always divides evenly      |
| Average | O(n log n) | Consistent                 |
| Worst   | O(n log n) | Never degrades             |

**Space:** O(n) — temporary merge arrays
**Why MergeSort for date?** Stable sort (preserves equal-date order). Guaranteed O(n log n) always, unlike QuickSort.
