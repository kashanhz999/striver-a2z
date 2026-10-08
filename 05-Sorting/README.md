# Sorting Algorithms — Notes

Sorting means arranging elements in order, usually ascending. These three are the **basic O(n²) sorts**. They're slow on big data, but they teach how to reason about loops, swaps and invariants, and they come up in interviews ("dry-run insertion sort", "which one is stable?").

| #  | File | Algorithm | Idea in one line |
|----|------|-----------|------------------|
| 01 | [01-Selection-Sort.cpp](01-Selection-Sort.cpp) | Selection sort | Find the **minimum** and put it at the front |
| 02 | [02-Bubble-Sort.cpp](02-Bubble-Sort.cpp) | Bubble sort | Swap **adjacent** pairs so the **maximum** bubbles to the end |
| 03 | [03-Insertion-Sort.cpp](03-Insertion-Sort.cpp) | Insertion sort | Take the next element and **insert** it into the sorted left part |

**Input** ([input.txt](input.txt)): first `n`, then `n` elements. For example, `5 4 3 2 1 0` means n = 5 and the array is `{4, 3, 2, 1, 0}`.

All the dry runs below use the array **`[13, 46, 24, 52, 20, 9]`**.

---

## 1. Selection sort

**Idea:** for each position `i`, select the smallest element in `i … n-1` and swap it into position `i`. After round `i`, the first `i + 1` elements are sorted and final.

```cpp
for (int i = 0; i < n - 1; i++) {
    int mini = i;
    for (int j = i + 1; j < n; j++)
        if (arr[j] < arr[mini]) mini = j;
    swap(arr[i], arr[mini]);
}
```

| Round | Min found | Array after the swap |
|---|---|---|
| start | | 13 46 24 52 20 9 |
| i=0 | 9 | **9** 46 24 52 20 13 |
| i=1 | 13 | **9 13** 24 52 20 46 |
| i=2 | 20 | **9 13 20** 52 24 46 |
| i=3 | 24 | **9 13 20 24** 52 46 |
| i=4 | 46 | **9 13 20 24 46 52** ✅ |

- Always O(n²), even when the array is already sorted, because it still scans to find the minimum every round.
- **At most n − 1 swaps.** This is the fewest swaps of the three, which helps when writing to memory is expensive.
- **Not stable.** The long-distance swap can reorder equal elements. For example, in `[5a, 5b, 2]` the first swap moves 5a past 5b, giving `[2, 5b, 5a]`.

## 2. Bubble sort

**Idea:** walk through the array and swap any adjacent pair that's out of order. After each pass, the **largest remaining element** has bubbled to the end, so the next pass can stop one position earlier.

```cpp
for (int i = n - 1; i >= 1; i--) {
    bool didSwap = false;
    for (int j = 0; j <= i - 1; j++)
        if (arr[j] > arr[j + 1]) { swap(arr[j], arr[j + 1]); didSwap = true; }
    if (!didSwap) break;          // no swaps means already sorted, so stop early
}
```

| Pass | Array after the pass (the sorted tail is in **bold**) |
|---|---|
| start | 13 46 24 52 20 9 |
| 1 | 13 24 46 20 9 **52** |
| 2 | 13 24 20 9 **46 52** |
| 3 | 13 20 9 **24 46 52** |
| 4 | 13 9 **20 24 46 52** |
| 5 | **9 13 20 24 46 52** ✅ |

- Worst and average case O(n²). **Best case O(n)** with the `didSwap` optimisation (added to your file): on an already-sorted array the first pass makes no swaps, so the loop stops.
- **Stable**, because it only swaps when `>` (never on equal elements).

## 3. Insertion sort

**Idea:** like sorting playing cards in your hand. The left part `0 … i-1` is already sorted. Take `arr[i]` and keep swapping it left while the element to its left is larger.

```cpp
for (int i = 1; i < n; i++) {
    int j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
        swap(arr[j - 1], arr[j]);
        j--;
    }
}
```

| i | Element | Array after inserting it (the sorted part is in **bold**) |
|---|---|---|
| start | | **13** 46 24 52 20 9 |
| 1 | 46 | **13 46** 24 52 20 9 (no move) |
| 2 | 24 | **13 24 46** 52 20 9 |
| 3 | 52 | **13 24 46 52** 20 9 (no move) |
| 4 | 20 | **13 20 24 46 52** 9 |
| 5 | 9 | **9 13 20 24 46 52** ✅ |

- Worst case O(n²) when the input is reverse sorted. **Best case O(n)** when it's already sorted, because the `while` never runs.
- Very fast on **nearly sorted** or small arrays. Real-world sorts (like the one inside `std::sort`) switch to insertion sort for small pieces.
- **Stable**, because it uses `>` and stops at equal elements.

---

## Comparison

| | Selection | Bubble | Insertion |
|---|---|---|---|
| Best | O(n²) | **O(n)** (with `didSwap`) | **O(n)** |
| Average | O(n²) | O(n²) | O(n²) |
| Worst | O(n²) | O(n²) | O(n²) |
| Extra space | O(1) | O(1) | O(1) |
| Stable? | ❌ | ✅ | ✅ |
| Swaps (worst) | **O(n)** | O(n²) | O(n²) |
| Good for | few writes | teaching, detecting "already sorted" | small or nearly-sorted data |

**Definitions**
- **In-place:** uses only O(1) extra memory. All three are in-place.
- **Stable:** equal elements keep their original relative order. This matters when sorting records by one field (for example, sorting students by marks while keeping a previous sort by name).

**What does each pass guarantee?** (This is the key to understanding and debugging a sort.)
- **Selection:** after round i, `arr[0..i]` holds the i + 1 smallest elements, in their **final** places.
- **Bubble:** after pass k, the last k elements are the k largest, in their **final** places.
- **Insertion:** after step i, `arr[0..i]` is sorted, but it's **not final**: later elements may still be inserted between them.

---

## Notes on the code

- `int arr[n];` with `n` read at runtime is a **variable-length array**. GCC allows it, but it's not standard C++ (MSVC rejects it). The portable version is `vector<int> arr(n);`, and the rest of the code stays the same.
- In practice you'd just call `sort(arr, arr + n)` or `sort(v.begin(), v.end())`, which is O(n log n). See [03-STL/10-algorithms.cpp](../03-STL/10-algorithms.cpp). You learn these three to understand how sorting works.

## Coming next (Sorting II)

| Algorithm | Time | Space | Stable | Idea |
|---|---|---|---|---|
| Merge sort | O(n log n) always | O(n) | ✅ | split in half, sort each half recursively, merge the two sorted halves |
| Quick sort | O(n log n) average, O(n²) worst | O(log n) stack | ❌ | pick a pivot, put smaller elements left and larger right, recurse |
| Recursive bubble / insertion sort | O(n²) | O(n) stack | ✅ | the same algorithms written with recursion |

## Practice

1. Dry-run all three sorts by hand on `[5, 1, 4, 2, 8]` and count the swaps each one makes.
2. Change each sort to produce **descending** order. *(Hint: flip one comparison.)*
3. Count how many swaps bubble sort makes. *(That number equals the number of **inversions** in the array.)*
4. Show with `[(5,'a'), (5,'b'), (2,'c')]` that selection sort is not stable.
5. Rewrite one of the sorts as a function `void sortArr(vector<int> &v)`.
