# DSA in C++ — Notes & Examples

Study notes + runnable examples. The folders are **numbered in the order you should learn them**.

```
DSA/
├── 01-CPP-Basics/    Language basics: I/O, types, conditions, loops, arrays, strings, functions, pointers, Big-O
├── 02-Patterns/      Pattern printing: trains nested-loop thinking (22 patterns)
├── 03-STL/           Standard Template Library: containers + algorithms used in every DSA problem
├── 04-Basic-Maths/   Digits, palindrome, Armstrong, divisors, prime, GCD (the √n trick)
└── 05-Sorting/       Selection, Bubble, Insertion sort (dry runs + comparison)
```

## Progress

| Step | Folder | Status |
|---|---|---|
| 1 | [01-CPP-Basics](01-CPP-Basics/README.md) | ✅ 11 files |
| 2 | [02-Patterns](02-Patterns/README.md) | ✅ 22 patterns |
| 3 | [03-STL](03-STL/README.md) | ✅ 10 files |
| 4 | [04-Basic-Maths](04-Basic-Maths/README.md) | ✅ 8 files |
| 5 | [05-Sorting](05-Sorting/README.md) | 🟡 Sorting I done (3/3). Sorting II (merge, quick) next |
| 6 | Basic Recursion | ⬜ |
| 7 | Basic Hashing | ⬜ |
| 8 | Arrays | ⬜ |
| 9 | Binary Search | ⬜ |
| … | Strings → Linked List → Recursion/Backtracking → Bit Manipulation → Stack/Queue → Sliding Window/Two Pointers → Heaps → Greedy → Trees → BST → Graphs → DP → Tries | ⬜ |

## Folder layout (use this for every new topic)

```
NN-Topic-Name/          ← NN = next step number, words joined with "-" (no spaces)
├── README.md           ← notes: idea, dry run, complexity, edge cases, practice
├── 01-first-problem.cpp
├── 02-second-problem.cpp
├── input.txt           ← what the programs read with cin
└── output.txt          ← what they printed (written by the build task)
```

Inside each `.cpp`, use this layout:
1. A top comment with the problem, the idea, the complexity, and the expected input.
2. The code.
3. An `EXPECTED OUTPUT` comment at the bottom.

`.exe` files are ignored by git (see `.gitignore`). They're rebuilt every time you run a file.

## How to study a file

1. Read the folder's `README.md`, then the comments in the `.cpp`.
2. **Before running**, predict the output on paper.
3. Run it (Ctrl + Shift + B) and compare against your guess and the `EXPECTED OUTPUT` comment.
4. Change something (the input, a loop bound, a comparison) and predict again. That's how it sticks.

## How to compile & run (VS Code)

Open any `.cpp` file and press **Ctrl + Shift + B** (the default build task, *compile and run*, from `.vscode/tasks.json`). It:

1. compiles the file with `g++ -std=c++17`
2. runs it with `input.txt` as the input and writes everything to `output.txt` (both in the same folder)

From a terminal, the same thing is:

```bash
g++ -std=c++17 -o prog 05-loops.cpp
./prog < input.txt > output.txt
```

> Each file's top comment says whether it reads input and what format it expects.
> - In `04-Basic-Maths`, files read **every** number in `input.txt`, so one run tests many cases.
> - In `05-Sorting`, the input is `n` followed by `n` elements.

## Why `#include <bits/stdc++.h>` and `using namespace std;`?

- `bits/stdc++.h` is a GCC header that includes **every** standard header at once. It's great for practice and contests, but not portable (MSVC doesn't have it), so in real projects include only what you need (`<iostream>`, `<vector>`, …).
- `using namespace std;` lets you write `cout` instead of `std::cout`. That's fine in practice files, but avoid it in header files of real projects.
