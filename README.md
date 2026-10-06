# DSA in C++ — Notes & Examples

Study notes + runnable examples, organised in the order you should learn them.

```
DSA/
├── C++/        Step 1 — Language basics (I/O, types, conditions, loops, arrays, strings, functions, pointers, complexity)
├── Patterns/   Step 2 — Pattern printing (trains your nested-loop thinking)
└── STL/        Step 3 — Standard Template Library (containers + algorithms you use in every DSA problem)
```

Every folder has:

| File            | What it is                                                    |
|-----------------|---------------------------------------------------------------|
| `README.md`     | The theory / notes for that topic — read this first           |
| `NN-topic.cpp`  | Runnable example, heavily commented. Read top to bottom.      |
| `input.txt`     | What the program reads from `cin`                             |
| `output.txt`    | What the program printed with `cout`                          |

## Suggested order

1. [C++/README.md](C++/README.md) → files `01` … `11`
2. [Patterns/README.md](Patterns/README.md) → `patterns.cpp` (22 patterns)
3. [STL/README.md](STL/README.md) → files `01` … `10`

For each `.cpp` file:
1. Read the comments.
2. **Before running**, guess the output on paper.
3. Run it and compare against your guess. The expected output is also written in the comments.
4. Change something and predict again. This is how it sticks.

## How to compile & run (VS Code)

Open any `.cpp` file and press **Ctrl + Shift + B** (the default build task, *compile and run*, from `.vscode/tasks.json`). It:

1. compiles the file with `g++ -std=c++17`
2. runs it with `input.txt` as the input and writes everything to `output.txt` (both in the same folder)

From a terminal, the same thing is:

```bash
g++ -std=c++17 -o prog 05-loops.cpp
./prog < input.txt > output.txt
```

> Most example files don't need any input; they print everything themselves.
> When a file *does* read input, the top comment says exactly what to put in `input.txt`.

## Why `#include <bits/stdc++.h>` and `using namespace std;`?

- `bits/stdc++.h` is a GCC header that includes **every** standard header at once. It's great for practice and contests, but not portable (MSVC doesn't have it), so in real projects include only what you need (`<iostream>`, `<vector>`, …).
- `using namespace std;` lets you write `cout` instead of `std::cout`. That's fine in practice files, but avoid it in header files of real projects.

## What comes after these three folders

Following the same roadmap: Basic Maths → Basic Recursion → Basic Hashing → Sorting → Arrays → Binary Search → Strings → Linked List → Recursion/Backtracking → Bit Manipulation → Stack/Queue → Sliding Window/Two Pointers → Heaps → Greedy → Trees → BST → Graphs → DP → Tries.
