# C++ Basics — Notes

Read each section, then open the matching file and run it.

| #  | File | Topic |
|----|------|-------|
| 01 | [01-basics-io.cpp](01-basics-io.cpp) | Program skeleton, `cin`, `cout`, `getline` |
| 02 | [02-data-types.cpp](02-data-types.cpp) | Data types, overflow, `/` and `%`, casting, ASCII |
| 03 | [03-if-else.cpp](03-if-else.cpp) | Conditions, logical operators, ternary |
| 04 | [04-switch.cpp](04-switch.cpp) | `switch`, `break`, fall-through |
| 05 | [05-loops.cpp](05-loops.cpp) | `for`, `while`, `do-while`, `break`, `continue`, nested loops |
| 06 | [06-arrays.cpp](06-arrays.cpp) | 1D arrays |
| 07 | [07-2d-arrays.cpp](07-2d-arrays.cpp) | 2D arrays / matrices |
| 08 | [08-strings.cpp](08-strings.cpp) | `std::string` and character tricks |
| 09 | [09-functions.cpp](09-functions.cpp) | Functions, pass by value / reference, overloading |
| 10 | [10-pointers-references.cpp](10-pointers-references.cpp) | Pointers, references, `new`/`delete`, a linked-list preview |
| 11 | [11-time-complexity.cpp](11-time-complexity.cpp) | Big-O, counting operations |

Only `01` reads from `input.txt` (`10 20` on line 1, `Hello World` on line 2). All the others print on their own.

---

## 01. Skeleton & I/O

```cpp
#include <bits/stdc++.h>   // all standard headers
using namespace std;       // write cout instead of std::cout

int main() {               // execution starts here
    int a, b;
    cin >> a >> b;         // read (stops at space / newline)
    cout << a + b << "\n"; // print
    return 0;              // 0 = success
}
```

| Thing | Meaning |
|---|---|
| `cout << x` | print x |
| `cin >> x` | read one value into x (skips spaces, stops at the next space) |
| `getline(cin, s)` | read a whole line, including spaces |
| `cin.ignore()` | throw away the leftover `\n` before calling `getline` after a `cin >>` |
| `endl` | newline **+ flush** (slow when used many times) |
| `"\n"` | newline only (fast) — prefer it |

**Fast I/O** for big inputs:
`ios_base::sync_with_stdio(false); cin.tie(nullptr);`

---

## 02. Data types

| Type | Size | Range / precision | Use for |
|---|---|---|---|
| `int` | 4 B | about ±2.1 × 10⁹ | normal counting, indices |
| `long long` | 8 B | about ±9.2 × 10¹⁸ | sums, products, anything that can exceed 2 × 10⁹ |
| `float` | 4 B | ~7 digits | (avoid) |
| `double` | 8 B | ~15 digits | decimals |
| `char` | 1 B | −128 … 127 | single characters (`'A'`) |
| `bool` | 1 B | `true`/`false` | flags |
| `string` | — | any length | text (`"abc"`) |

**Key rules**
- **Overflow:** `int * int` is calculated as an `int` even if you store it in a `long long`. Write `1LL * a * b`.
- **Integer division truncates:** `7 / 2 == 3`. Use `7.0 / 2` or `(double)a / b` for 3.5.
- **`%` is the remainder:** `n % 10` gives the last digit, `n / 10` removes the last digit, and `n % 2 == 0` means n is even.
- **Chars are numbers (ASCII):** `'A' = 65`, `'a' = 97`, `'0' = 48`.
  - `ch - '0'` turns a digit char into an int.
  - `ch - 'a'` gives the letter's index (0–25).
  - `char('a' + i)` goes back from an index to the letter.
- **`x++` vs `++x`:** `x++` uses the old value and then increases; `++x` increases first and then uses the new value.

---

## 03. Conditions

```cpp
if (cond1) { ... }
else if (cond2) { ... }   // checked only if cond1 was false
else { ... }              // runs if nothing above matched
```

- Relational operators: `==  !=  <  >  <=  >=`. Logical operators: `&&` (and), `||` (or), `!` (not).
- **Short-circuit:** in `A && B`, B is skipped when A is false. In `A || B`, B is skipped when A is true. So `if (i < n && arr[i] == x)` is a safe way to guard against going out of bounds.
- **Ternary:** `result = cond ? valueIfTrue : valueIfFalse;`
- **Traps:**
  - `if (x = 5)` assigns 5 to x, so the condition is always true.
  - `if (1 < x < 10)` is wrong; write `if (1 < x && x < 10)`.
  - Without `{ }`, only the first statement belongs to the `if`.

---

## 04. Switch

```cpp
switch (day) {
    case 1: cout << "Mon"; break;
    case 2: cout << "Tue"; break;
    default: cout << "Invalid";
}
```

- Works only on **integral values**: `int`, `char`, `enum`. It does not work on `string`, `double` or ranges.
- `break` exits the switch. Without it, execution **falls through** into the next case. That's a bug when it happens by accident, but it's also how you group cases on purpose (`case 6: case 7: weekend`).
- `default` is like the final `else`.

---

## 05. Loops

| Loop | Use when | Runs at least once? |
|---|---|---|
| `for (init; cond; update)` | you know the count | no |
| `while (cond)` | you only know the stop condition (e.g. digits of a number) | no |
| `do { } while (cond);` | the body must run once (e.g. menus) | **yes** |

- `break` leaves the loop. `continue` skips to the next iteration.
- **Nested loops:** the inner loop runs completely for each step of the outer loop, so the total work is outer × inner. The Patterns folder is all about this.
- **Digit-extraction template** (used constantly):
  ```cpp
  while (n > 0) { int d = n % 10; /* use d */ n /= 10; }
  ```
- **Off-by-one:** an array of size n has indices `0 … n-1`, so loop with `i < n`, not `i <= n`.

---

## 06. Arrays

```
int arr[5] = {10, 20, 30, 40, 50};
index:  0   1   2   3   4
```

- Fixed size, same type, stored next to each other in memory. **Access by index is O(1).**
- `int b[5] = {1, 2};` gives `{1, 2, 0, 0, 0}`. `int c[5] = {0};` gives all zeros. A local `int a[5];` without initialisation holds **garbage**.
- Size: `sizeof(arr) / sizeof(arr[0])` or `size(arr)`. This only works where the array is declared, not inside a function that received it.
- Arrays are passed to functions **as a pointer**:
  - The function can modify the original.
  - It doesn't know the size, so always pass `n` as well.
- Out-of-bounds access (`arr[5]` on a size-5 array) is **undefined behaviour**: it may crash or silently corrupt other data. *(This was the bug in the old `arr.cpp`: `i <= size(arr)`.)*
- Huge arrays (≥ 10⁶) should be declared **globally**. A global array is zero-initialised and doesn't overflow the stack.
- Patterns to know: sum / max / min in one pass, linear search, reversing with two pointers.

---

## 07. 2D arrays

- `int mat[R][C]`; access `mat[row][col]`. Stored row by row in memory.
- Pass to a function as `void f(int mat[][C], int rows)`. The column count is required.
- Traverse with `for (i < R) for (j < C)`. For column-wise work, swap the loops.
- **Transpose:** `t[j][i] = mat[i][j]`.
- **Diagonals** of an n × n matrix: the primary diagonal is where `i == j`, the secondary one is where `i + j == n - 1`.
- In practice: `vector<vector<int>> grid(R, vector<int>(C, 0));` lets you choose the size at runtime.

---

## 08. Strings

| Operation | Code | Complexity |
|---|---|---|
| length | `s.size()` / `s.length()` | O(1) |
| access | `s[i]`, `s.back()` | O(1) |
| append | `s += t`, `s.push_back(c)` | O(len t) / O(1) amortised |
| remove last | `s.pop_back()` | O(1) |
| substring | `s.substr(start, len)` | O(len) |
| search | `s.find(t)`; returns `string::npos` if not found | O(n·m) worst |
| insert / erase | `s.insert(i, t)`, `s.erase(i, len)` | O(n) |
| compare | `==`, `<` (dictionary order) | O(n) |
| reverse / sort | `reverse(s.begin(), s.end())`, `sort(...)` | O(n), O(n log n) |
| convert | `stoi`, `stoll`, `to_string` | O(n) |
| char checks | `isdigit`, `isalpha`, `isupper`, `islower`, `toupper`, `tolower` | O(1) |

- **Frequency trick:** `int freq[26] = {0}; for (char c : s) freq[c - 'a']++;`
- `for (char c : s)` gives a copy of each char. Use `for (char &c : s)` when you need to modify the string.
- `"Zebra" < "apple"` is true, because uppercase letters have smaller ASCII values than lowercase ones.

---

## 09. Functions

```cpp
int calSum(int a, int b) { return a + b; }
```

| Kind | Example |
|---|---|
| void, no params | `void greet()` |
| void, params | `void greetName(string name)` |
| returns, no params | `int getTen()` |
| returns, params | `int calSum(int a, int b)` |

**Pass by value vs pass by reference** (the most important idea here):

| | Syntax | What the function gets | Changes affect caller? |
|---|---|---|---|
| By value | `void f(int x)` | a **copy** | No |
| By reference | `void f(int &x)` | the **original** (an alias) | Yes |
| By const reference | `void f(const string &s)` | the original, read-only | Not allowed (and no copy is made, so it's fast) |
| Array | `void f(int arr[])` | a pointer to the original | Yes |

- Pass big objects (`string`, `vector`, `map`) **by reference** (`&`), or `const &` if read-only. Passing them by value copies everything, which is slow and a common cause of TLE.
- **Overloading:** the same function name with different parameter lists.
- **Default arguments:** `int power(int b, int e = 2)`. Default parameters must come last.
- **Prototype:** declare `bool isPrime(int);` above `main`, then define it below.

---

## 10. Pointers & references

| Syntax | In a declaration | In an expression |
|---|---|---|
| `*` | `int *p` means p is a pointer | `*p` gives the value at the address in p |
| `&` | `int &r = x` means r is an alias of x | `&x` gives the address of x |

- `p->field` is the same as `(*p).field`. You'll use it everywhere with linked lists and trees.
- `arr[i]` is the same as `*(arr + i)`. An array name decays to a pointer to its first element.
- `nullptr` points to nothing. Dereferencing it crashes the program.
- `new` and `delete` manage heap memory; arrays use `new[]` and `delete[]`. Prefer `vector`, which handles this for you.
- A reference must be initialised, can't be re-seated and can't be null. A pointer can be null and can be re-pointed.

---

## 11. Time & space complexity

**Big-O** describes how the number of operations grows with input size `n`, considering the **worst case** for large n.

How to calculate it:
1. Count how many times the innermost statement runs.
2. **Drop constants:** `3n + 5` becomes `O(n)`.
3. **Keep the biggest term:** `n² + n log n + n` becomes `O(n²)`.

| Code shape | Complexity |
|---|---|
| a few statements, no loop | O(1) |
| `for (i = n; i > 0; i /= 2)` | O(log n) |
| one loop to n | O(n) |
| two separate loops to n | O(n + n) = O(n) |
| loop n × halving loop | O(n log n) |
| two nested loops to n | O(n²) |
| `for i<n, for j<i` (triangle) | n(n−1)/2, which is O(n²) |
| loop to √n (`i*i <= n`) | O(√n) |
| recursion with 2 branches, depth n | O(2ⁿ) |
| all permutations | O(n!) |

**Growth order (best to worst):**
`O(1) < O(log n) < O(√n) < O(n) < O(n log n) < O(n²) < O(n³) < O(2ⁿ) < O(n!)`

**What fits in about 1 second** (a computer does roughly 10⁸ simple operations per second):

| n up to | Needed complexity |
|---|---|
| 10⁸ | O(n), O(log n) |
| 10⁶ | O(n log n) |
| 10⁴ | O(n²) |
| 500 | O(n³) |
| 20 | O(2ⁿ) |
| 10 | O(n!) |

**Space complexity** is the extra memory used, not counting the input. Examples:
- a few variables: O(1)
- an extra array of size n: O(n)
- an n × n matrix: O(n²)
- recursion depth d: O(d) of stack space

Best, average and worst case are written Ω (omega), Θ (theta) and O. In interviews and DSA, people almost always mean **worst case, O**.

---

## Practice (do these without looking)

1. Read n numbers and print the sum, max and min.
2. Count the digits of a number, reverse it, and check whether it's a palindrome.
3. Check whether a number is an Armstrong number (153 = 1³ + 5³ + 3³).
4. Print all divisors of n in O(√n).
5. Check whether a number is prime in O(√n).
6. Find the GCD of two numbers (Euclid: `gcd(a, b) = gcd(b, a % b)`).
7. Reverse an array in place and rotate it left by 1.
8. Count the vowels, consonants, digits and spaces in a line.
9. Write `swap` using pointers and again using references.
10. Find the Big-O of: `for (i = 1; i < n; i *= 2) for (j = 0; j < i; j++)`. *(Answer: O(n), because 1 + 2 + 4 + … + n ≈ 2n.)*
