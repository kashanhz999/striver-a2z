# Pattern Printing — Notes

Patterns aren't asked much in interviews. They exist to train one skill: **controlling nested loops and turning an observation into a formula.** Get this right and loops will never confuse you again.

Code: [patterns.cpp](patterns.cpp) has all 22 patterns, each with a picture and its formula in the comments.

**How to run:** put lines of `<patternNumber> <n>` in [input.txt](input.txt), then press Ctrl + Shift + B.
- `0 5` prints all 22 patterns with n = 5.
- `9 3` prints only pattern 9 with n = 3.

---

## The 4-step method (use it for every pattern)

1. **Outer loop counts the rows.** How many lines are printed? Usually `n`, sometimes `2n − 1` or `2n`.
2. **Inner loop(s) handle the columns.** What does one row contain? It might be just stars, or *spaces + stars + spaces*. That's one inner loop per "block".
3. **Find the formula.** Write a small table: row number `i` → how many spaces, how many stars, which number or letter. Find the relation with `i` and `n`.
4. **Print, then newline.** Print inside the inner loops; `cout << "\n"` goes after the inner loops, inside the outer loop.

### Worked example: Pattern 7 (pyramid), n = 5

```
    *        i=0 → spaces 4, stars 1
   ***       i=1 → spaces 3, stars 3
  *****      i=2 → spaces 2, stars 5
 *******     i=3 → spaces 1, stars 7
*********    i=4 → spaces 0, stars 9
```

| i | spaces | stars |
|---|--------|-------|
| 0 | 4 | 1 |
| 1 | 3 | 3 |
| 2 | 2 | 5 |
| 3 | 1 | 7 |
| 4 | 0 | 9 |

- spaces go down by 1 each row, starting at n − 1, so **spaces = n − i − 1**
- stars are the odd numbers 1, 3, 5, …, so **stars = 2i + 1**

```cpp
for (int i = 0; i < n; i++) {                       // rows
    for (int j = 0; j < n - i - 1; j++) cout << " "; // block 1: spaces
    for (int j = 0; j < 2 * i + 1; j++) cout << "*"; // block 2: stars
    cout << "\n";
}
```

### Tricks that come up again and again

| Trick | Where |
|---|---|
| Print `j` (column) vs print `i` (row) | P3 vs P4 |
| Inverted = `n − i` instead of `i + 1` | P5, P6, P8, P15 |
| Reuse functions: diamond = pyramid + inverted pyramid | P9 |
| Grow-then-shrink over `2n − 1` rows: `stars = (i <= n) ? i : 2n − i` | P10, P20 |
| Alternating value: `start = 1 − start` | P11 |
| Counter declared **outside** both loops | P13 |
| `char` arithmetic: `'A' + i` | P14 – P18 |
| Increase until the middle, then decrease (`breakpoint`) | P17 |
| Split a shape into a top half and a bottom half | P19 |
| Loop over every cell and **decide with an `if`** | P21 (border), P22 (distance) |
| Distance to the nearest edge: `min(top, bottom, left, right)` | P22 |

---

## All 22 patterns (n = 5)

### Part A: right triangles (one inner loop)

| # | Output | Rows / formula |
|---|---|---|
| 1 | <pre>* * * * *<br>* * * * *<br>* * * * *<br>* * * * *<br>* * * * *</pre> | n rows, n stars each |
| 2 | <pre>*<br>* *<br>* * *<br>* * * *<br>* * * * *</pre> | row i: `i + 1` stars |
| 3 | <pre>1<br>1 2<br>1 2 3<br>1 2 3 4<br>1 2 3 4 5</pre> | print `j` for j = 1..i |
| 4 | <pre>1<br>2 2<br>3 3 3<br>4 4 4 4<br>5 5 5 5 5</pre> | print `i` for j = 1..i |
| 5 | <pre>* * * * *<br>* * * *<br>* * *<br>* *<br>*</pre> | row i: `n − i` stars |
| 6 | <pre>1 2 3 4 5<br>1 2 3 4<br>1 2 3<br>1 2<br>1</pre> | 1-indexed: j = 1..`n − i + 1` |

### Part B: pyramids (space + star + space)

| # | Output | Formula |
|---|---|---|
| 7 | <pre>    *<br>   ***<br>  *****<br> *******<br>*********</pre> | spaces `n − i − 1`, stars `2i + 1` |
| 8 | <pre>*********<br> *******<br>  *****<br>   ***<br>    *</pre> | spaces `i`, stars `2n − 2i − 1` |
| 9 | <pre>    *<br>   ***<br>  *****<br> *******<br>*********<br>*********<br> *******<br>  *****<br>   ***<br>    *</pre> | P7 then P8 |
| 10 | <pre>*<br>**<br>***<br>****<br>*****<br>****<br>***<br>**<br>*</pre> | `2n − 1` rows, stars `i ≤ n ? i : 2n − i` |

### Part C: numbers and alternating values

| # | Output | Formula |
|---|---|---|
| 11 | <pre>1<br>0 1<br>1 0 1<br>0 1 0 1<br>1 0 1 0 1</pre> | start = `i even ? 1 : 0`, flip each step |
| 12 | <pre>1        1<br>12      21<br>123    321<br>1234  4321<br>1234554321</pre> | 1..i, `2(n − i)` spaces, i..1 |
| 13 | <pre>1<br>2 3<br>4 5 6<br>7 8 9 10<br>11 12 13 14 15</pre> | one counter `num++` outside the loops |

### Part D: letters

| # | Output | Formula |
|---|---|---|
| 14 | <pre>A<br>A B<br>A B C<br>A B C D<br>A B C D E</pre> | `'A'` … `'A' + i` |
| 15 | <pre>A B C D E<br>A B C D<br>A B C<br>A B<br>A</pre> | `'A'` … `'A' + n − i − 1` |
| 16 | <pre>A<br>B B<br>C C C<br>D D D D<br>E E E E E</pre> | letter `'A' + i`, printed `i + 1` times |
| 17 | <pre>    A<br>   ABA<br>  ABCBA<br> ABCDCBA<br>ABCDEDCBA</pre> | P7 shape, `ch++` until the middle, then `ch--` |
| 18 | <pre>E<br>D E<br>C D E<br>B C D E<br>A B C D E</pre> | from `'A' + n − 1 − i` to `'A' + n − 1` |

### Part E: symmetric and hollow

| # | Output | Formula |
|---|---|---|
| 19 | <pre>**********<br>****  ****<br>***    ***<br>**      **<br>*        *<br>*        *<br>**      **<br>***    ***<br>****  ****<br>**********</pre> | top: stars `n − i`, spaces `2i`. bottom: stars `i + 1`, spaces `2(n − i − 1)` |
| 20 | <pre>*        *<br>**      **<br>***    ***<br>****  ****<br>**********<br>****  ****<br>***    ***<br>**      **<br>*        *</pre> | stars like P10, spaces `2(n − stars)` |
| 21 | <pre>*****<br>*   *<br>*   *<br>*   *<br>*****</pre> | `*` if `i==0 \|\| j==0 \|\| i==n−1 \|\| j==n−1` |
| 22 | <pre>4444444<br>4333334<br>4322234<br>4321234<br>4322234<br>4333334<br>4444444</pre> | (n = 4) size `2n − 1`, value `n − min(top, bottom, left, right)` |

---

## Common mistakes

- **Newline in the wrong place:** `cout << "\n"` inside the inner loop prints one star per line. It belongs after the inner loop.
- **Off-by-one:** `j < n − 1` vs `j < n`. Always test the formula on row 0 and on the last row. *(The old P1 used `n − 1` and printed a 4 × 4 square for n = 5.)*
- **Mixing 0-indexed and 1-indexed rows:** choose one per pattern and derive the formula from that choice. With `i` starting at 0 the inverted count is `n − i`; with `i` starting at 1 it's `n − i + 1`.
- **Wrong variable:** printing `i` when you meant `j` (compare P3 and P4).

## Complexity

Every pattern prints about n × (row length) characters, so all of these are **O(n²)** time and **O(1)** extra space.

## Practice (patterns not in the file)

1. Hollow pyramid (only the edges of P7 are `*`).
2. Pascal's triangle: each value is the sum of the two values above it, i.e. `C(i, j)`.
3. Right-aligned triangle (P2 flipped horizontally).
4. A number pyramid `1 / 121 / 12321 / 1234321`.
5. A hollow diamond.
