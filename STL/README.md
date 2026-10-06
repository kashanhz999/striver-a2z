# STL (Standard Template Library) — Notes

The STL is C++'s built-in toolbox of **data structures (containers)** and **algorithms**. In DSA you use it in almost every problem, so you need to know what each container is, its complexity, and when to pick it.

| #  | File | Topic |
|----|------|-------|
| 01 | [01-pairs.cpp](01-pairs.cpp) | `pair`, `tuple` |
| 02 | [02-vector.cpp](02-vector.cpp) | `vector`, iterators |
| 03 | [03-list.cpp](03-list.cpp) | `list` (doubly linked list) |
| 04 | [04-deque.cpp](04-deque.cpp) | `deque` + sliding-window maximum |
| 05 | [05-stack.cpp](05-stack.cpp) | `stack` + balanced brackets, next greater element |
| 06 | [06-queue.cpp](06-queue.cpp) | `queue` + BFS |
| 07 | [07-priority-queue.cpp](07-priority-queue.cpp) | max / min heap, custom comparator, k-th largest |
| 08 | [08-set.cpp](08-set.cpp) | `set`, `multiset`, `unordered_set` |
| 09 | [09-map.cpp](09-map.cpp) | `map`, `multimap`, `unordered_map` + frequency counting, two-sum |
| 10 | [10-algorithms.cpp](10-algorithms.cpp) | `sort`, comparators, `lower_bound`, `next_permutation`, … |

None of these files need input.

---

## The 4 parts of the STL

1. **Containers** hold data: `vector`, `list`, `deque`, `stack`, `queue`, `priority_queue`, `set`, `map`, …
2. **Iterators** are pointer-like objects used to walk through a container (`v.begin()`, `v.end()`).
3. **Algorithms** are ready-made functions that run on a range: `sort`, `reverse`, `find`, `lower_bound`, …
4. **Functors** are objects that behave like functions. Comparators like `greater<int>()` and lambdas are examples.

### Container families

| Family | Containers | Idea |
|---|---|---|
| **Sequence** | `vector`, `deque`, `list`, `array` | keep elements in the order you inserted them |
| **Adapters** | `stack`, `queue`, `priority_queue` | a restricted interface on top of a sequence container |
| **Ordered associative** | `set`, `multiset`, `map`, `multimap` | always sorted, tree based, O(log n) |
| **Unordered associative** | `unordered_set`, `unordered_map` | hash table, O(1) average, no order |

---

## Iterators (read this before vector)

```
 v = {10, 20, 30, 40}
       ^               ^
   v.begin()        v.end()    <- one PAST the last element (not the last element!)
```

- `*it` gives the value. `it++` moves to the next element. `it->first` works when the elements are pairs.
- `v.rbegin()` and `v.rend()` are reverse iterators, for walking backwards.
- Ranges are always **half-open, `[first, last)`**: first is included, last is excluded.
- **Iterator − begin = index:** `int idx = it - v.begin();` This works for vector, deque and arrays.
- `vector` and `deque` iterators can jump (`it + 3`). `list`, `set` and `map` iterators can only step (`++`, `--`), or use `next(it, k)`.
- `auto it = v.begin();` saves typing out `vector<int>::iterator`.
- After inserting into or erasing from a vector, old iterators may become **invalid**. Don't use them.

---

## 01. pair

```cpp
pair<int, int> p = {1, 2};          // p.first = 1, p.second = 2
pair<int, pair<int,int>> t = {1, {2, 3}};   // t.second.first = 2
pair<int, int> arr[] = {{1,2}, {2,4}};
auto [a, b] = p;                    // C++17 unpacking
```

- Pairs compare by `first`, then by `second`. That's why sorting a `vector<pair>` sorts by first and breaks ties with second.
- Use pairs for (value, index), (x, y), (distance, node), and so on.

## 02. vector (dynamic array) — the most used container

```cpp
vector<int> v;                 // empty
vector<int> v(5);              // {0,0,0,0,0}
vector<int> v(5, 100);         // {100 ×5}
vector<int> v2(v);             // copy
vector<int> v = {1, 2, 3};
vector<vector<int>> grid(n, vector<int>(m, 0));   // n × m 2D grid
```

| Operation | Code | Time |
|---|---|---|
| add / remove at end | `push_back(x)`, `emplace_back(x)`, `pop_back()` | O(1) amortised |
| access | `v[i]`, `v.at(i)` (bounds-checked), `front()`, `back()` | O(1) |
| size / empty | `size()`, `empty()` | O(1) |
| insert / erase in the middle | `insert(it, x)`, `erase(it)`, `erase(first, last)` | O(n) |
| clear | `clear()` | O(n) |
| resize | `resize(n)` | O(n) |
| swap two vectors | `a.swap(b)` | O(1) |

- `push_back({1, 2})` builds the object first and then copies it in. `emplace_back(1, 2)` builds it directly inside the vector, which is slightly faster.
- **How it grows:** when the vector is full, it allocates about twice the space and copies everything over. That's why `push_back` is O(1) *amortised* (on average). If you know the final size, call `reserve(n)` to avoid the copies.
- Pass vectors to functions as `vector<int> &v`. Without the `&`, the whole vector is copied.
- `v.size()` is **unsigned**. `v.size() - 1` when `v` is empty wraps around to a huge number. Write `(int)v.size() - 1`.

## 03. list (doubly linked list)

- O(1) `push_front`, `push_back`, `pop_front`, `pop_back`, and insert/erase at an iterator.
- **No `l[i]`.** You have to walk there, which is O(n).
- It has its own `l.sort()`, `l.reverse()`, `l.unique()` and `l.remove(x)`. `std::sort` doesn't work on lists.

## 04. deque (double-ended queue)

- O(1) push/pop at **both** ends **and** O(1) `d[i]`.
- Used for the sliding-window maximum (monotonic deque) and 0-1 BFS.

## 05. stack (LIFO)

```cpp
stack<int> st; st.push(1); st.top(); st.pop(); st.size(); st.empty();
```

- Last in, first out. All operations are O(1). No indexing and no iteration.
- `pop()` returns nothing. Read `top()` before popping.
- Never call `top()` or `pop()` on an empty stack.
- Used for brackets, next greater/smaller element (monotonic stack), undo, and iterative DFS.

## 06. queue (FIFO)

```cpp
queue<int> q; q.push(1); q.front(); q.back(); q.pop();
```

- First in, first out. All operations are O(1).
- Used for **BFS**, level-order traversal of trees, and scheduling.

## 07. priority_queue (heap)

```cpp
priority_queue<int> maxH;                                  // top() = largest
priority_queue<int, vector<int>, greater<int>> minH;       // top() = smallest
```

| Operation | Time |
|---|---|
| `push` | O(log n) |
| `top` | O(1) |
| `pop` | O(log n) |

- The custom comparator works **backwards** compared to `sort`. Returning `a > b` puts the *smallest* element on top.
- Used for the k largest/smallest elements (keep a heap of size k), Dijkstra (a min-heap of `{dist, node}`), merging k sorted lists, and the median of a stream.

## 08. set / multiset / unordered_set

| | Sorted | Duplicates | Insert / find / erase |
|---|---|---|---|
| `set` | ✅ | ❌ | O(log n) |
| `multiset` | ✅ | ✅ | O(log n) |
| `unordered_set` | ❌ | ❌ | **O(1)** average, O(n) worst |

- `st.find(x) != st.end()` and `st.count(x)` both check whether x is present.
- `lower_bound(x)` is the first element ≥ x. `upper_bound(x)` is the first element > x. These are only on ordered sets.
- `*st.begin()` is the smallest element and `*st.rbegin()` is the largest.
- In a **multiset**, `ms.erase(x)` removes **all** copies of x. `ms.erase(ms.find(x))` removes one copy.
- You can't modify an element in place. Erase it and insert the new value.

## 09. map / multimap / unordered_map

```cpp
map<string, int> m;  m["a"] = 1;  m.insert({"b", 2});
for (auto &[key, val] : m) ...    // keys in sorted order
```

| | Key order | Duplicate keys | Operations |
|---|---|---|---|
| `map` | sorted | ❌ | O(log n) |
| `multimap` | sorted | ✅ | O(log n), no `[]` |
| `unordered_map` | none | ❌ | **O(1)** average |

- ⚠️ `m[key]` on a **missing** key inserts it with a default value (0, "" and so on). Use `m.count(key)` or `m.find(key)` to check without inserting.
- That auto-insert is exactly what makes **frequency counting** a one-liner: `for (int x : a) freq[x]++;`
- Keys can be pairs in a `map`. In an `unordered_map`, a pair key needs a custom hash.

## 10. Algorithms

| Function | What it does | Time |
|---|---|---|
| `sort(b, e)` / `sort(b, e, greater<int>())` / `sort(b, e, cmp)` | sort the range | O(n log n) |
| `reverse(b, e)` | reverse the range | O(n) |
| `*max_element(b, e)`, `*min_element(b, e)` | largest / smallest value | O(n) |
| `accumulate(b, e, 0)` | sum (use `0LL` as the start for big sums) | O(n) |
| `count(b, e, x)`, `find(b, e, x)` | count / locate x | O(n) |
| `binary_search(b, e, x)` | is x present? (**sorted** range) | O(log n) |
| `lower_bound(b, e, x)` | first element ≥ x (sorted range) | O(log n) |
| `upper_bound(b, e, x)` | first element > x (sorted range) | O(log n) |
| `next_permutation(b, e)` | next lexicographic order (start sorted to get all) | O(n) |
| `v.erase(unique(b, e), e)` | remove duplicates (sort first) | O(n) |
| `fill(b, e, x)`, `iota(b, e, start)` | fill with x / with start, start+1, … | O(n) |
| `__builtin_popcount(x)`, `__builtin_popcountll(x)` | count the set bits | O(1) |

**Comparator rule for `sort`:** `cmp(a, b)` returns **true if a should come before b**. It must be a strict comparison, so use `<` and never `<=`. Using `<=` can crash the sort.

```cpp
sort(v.begin(), v.end(), [](const pair<int,int> &a, const pair<int,int> &b) {
    if (a.second != b.second) return a.second < b.second;  // by second ascending
    return a.first > b.first;                             // tie: first descending
});
```

---

## Cheat sheet: which container should I use?

| I need to… | Use |
|---|---|
| store a list and access by index | `vector` |
| add/remove at **both** ends | `deque` |
| process the most recent item first (undo, brackets) | `stack` |
| process the oldest item first (BFS) | `queue` |
| always get the max / min quickly | `priority_queue` |
| check "seen before?" quickly | `unordered_set` |
| keep unique items **sorted**, or find the next bigger / smaller | `set` |
| sorted with duplicates | `multiset` |
| count frequencies / key → value lookup | `unordered_map` (or `map` if you need sorted keys) |
| frequent insert/erase in the middle via iterators | `list` |

## Complexity summary

| Container | Access | Search | Insert | Erase |
|---|---|---|---|---|
| vector | O(1) | O(n) | O(1) end / O(n) middle | O(1) end / O(n) middle |
| deque | O(1) | O(n) | O(1) ends / O(n) middle | O(1) ends / O(n) middle |
| list | O(n) | O(n) | O(1) at an iterator | O(1) at an iterator |
| stack / queue | top / front only | — | O(1) | O(1) |
| priority_queue | top O(1) | — | O(log n) | O(log n) |
| set / map | — | O(log n) | O(log n) | O(log n) |
| unordered_set / map | — | O(1) avg | O(1) avg | O(1) avg |

## Common mistakes

1. `m[key]` used just to *check* for a key. It inserts the key.
2. Passing `vector`, `string` or `map` to a function without `&`, which copies it every call.
3. Calling `lower_bound` or `binary_search` on an **unsorted** vector.
4. Using `<=` in a sort comparator.
5. Calling `top()`, `front()` or `pop()` on an empty stack, queue or priority_queue.
6. `ms.erase(x)` on a multiset when you meant to remove one copy.
7. Looping `for (int i = 0; i <= v.size() - 1; i++)` on an empty vector. `size()` is unsigned.

## Practice

1. Count the frequency of each element and print them in sorted order (`map`).
2. Print the distinct elements of an array in sorted order (`set`).
3. Find the k-th smallest element (`priority_queue` max-heap of size k).
4. Check whether two strings are anagrams (`unordered_map` or a sorted copy).
5. Sort intervals by start time, then merge overlapping ones (`vector<pair>` + `sort`).
6. Reverse the first k elements of a queue (`queue` + `stack`).
7. Find the first non-repeating character in a string (`unordered_map` + a second pass).
8. Find the next greater element for every element (monotonic `stack`).
