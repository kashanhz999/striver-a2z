# Basic Maths — Notes

These problems all use one tool: **pulling a number apart digit by digit** with `% 10` and `/ 10`. They also introduce the **√n trick**, which turns an O(n) loop into an O(√n) one.

| #  | File | Problem | Best complexity |
|----|------|---------|-----------------|
| 01 | [01-digit-concept.cpp](01-digit-concept.cpp) | Extract the digits | O(log₁₀ n) |
| 02 | [02-count-digits.cpp](02-count-digits.cpp) | Count the digits | O(log₁₀ n), or O(1) with `log10` |
| 03 | [03-reverse-number.cpp](03-reverse-number.cpp) | Reverse a number | O(log₁₀ n) |
| 04 | [04-check-palindrome.cpp](04-check-palindrome.cpp) | Palindrome number | O(log₁₀ n) |
| 05 | [05-armstrong-number.cpp](05-armstrong-number.cpp) | Armstrong number | O(log₁₀ n) |
| 06 | [06-print-all-divisor.cpp](06-print-all-divisor.cpp) | All divisors | O(√n) |
| 07 | [07-check-prime.cpp](07-check-prime.cpp) | Prime check | O(√n) |
| 08 | [08-gcd-hcf.cpp](08-gcd-hcf.cpp) | GCD / HCF and LCM | O(log min(a, b)) |

**Input:** files 01–07 read every number in [input.txt](input.txt) (`0 7 12 121 153 1634 7789`), so one run tests all of them. Add your own numbers to try more cases. File 08 needs no input.

---

## 1. Digit extraction (the core loop)

```cpp
while (n > 0) {
    int last = n % 10;   // last digit
    // ... use last ...
    n = n / 10;          // remove last digit
}
```

| n | n % 10 | n / 10 |
|---|---|---|
| 7789 | 9 | 778 |
| 778 | 8 | 77 |
| 77 | 7 | 7 |
| 7 | 7 | 0 → stop |

- The digits come out **last to first**.
- **Why O(log₁₀ n)?** n shrinks by a factor of 10 each step, so the loop runs once per digit, which is ⌊log₁₀ n⌋ + 1 times. A 9-digit number takes only 9 steps.
- ⚠️ For `n = 0` the loop never runs. Handle 0 separately when it matters (counting digits, for example).

## 2. Count digits

- Count the iterations of the core loop.
- Or use the formula **`(int)log10(n) + 1`**, which needs n > 0.

## 3. Reverse a number

```cpp
rev = rev * 10 + last;   // shift rev left one place, attach the digit
```

- `1200` becomes `21`, because leading zeros vanish.
- **Overflow:** reversing a large `int` can go past `INT_MAX`. Store `rev` in a `long long`.

## 4. Palindrome number

- Reverse the number, then compare it with the **original**.
- Save a copy first (`int cpy = n;`), because the loop turns n into 0.
- Negative numbers are not palindromes.

## 5. Armstrong number

A k-digit number is an Armstrong number when the **sum of each digit to the power k** equals the number:

- `153 = 1³ + 5³ + 3³` (3 digits, power 3)
- `1634 = 1⁴ + 6⁴ + 3⁴ + 4⁴` (4 digits, power 4)

Steps:
1. Count the digits to get k.
2. Sum `digit^k` over all digits.
3. Compare the sum with the original number.

- ⚠️ The power is the **digit count**, not always 3. *(The old version always cubed, so it rejected 1634.)*
- Use an integer power loop instead of `pow()`. `pow()` returns a `double` and can give 124.9999… instead of 125.

## 6. All divisors: the √n trick

Divisors come in **pairs** `(i, n/i)`. In each pair, one number is ≤ √n and the other is ≥ √n:

```
36:  1×36  2×18  3×12  4×9  6×6  |  9×4  12×3 ...  ← mirror of the left side
                              ↑ √36 = 6
```

```cpp
for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
        add(i);
        if (n / i != i) add(n / i);   // must be INSIDE the if; skip the duplicate for perfect squares
    }
}
// then sort if you need them in order
```

- This is O(√n) instead of O(n). For n = 10⁹, that's about 31,623 steps instead of a billion.
- Write `i * i <= n` instead of `i <= sqrt(n)`. It's exact integer maths and avoids calling `sqrt` on every step.
- ⚠️ *(Old bug: `if (n / i != i)` was outside the divisor check, so 7 printed `1 3 7`.)*

## 7. Prime check

A prime has **exactly two divisors**, 1 and itself.
- 0 and 1 are not prime.
- 2 is the only even prime.

```cpp
if (n < 2) return false;
for (int i = 2; i * i <= n; i++)   // start at 2!
    if (n % i == 0) return false;
return true;
```

- If n has any divisor other than 1 and n, one of them is ≤ √n, so checking up to √n is enough. **O(√n).**
- ⚠️ *(Old bug: the loop started at `i = 1`. Since `n % 1 == 0` for every n, every number was reported "not prime".)*
- Next level: to find **all** primes up to n, use the **Sieve of Eratosthenes**, which is O(n log log n).

## 8. GCD / HCF (Euclidean algorithm)

```
gcd(a, b) = gcd(b, a % b),    gcd(a, 0) = a
gcd(52, 20) → gcd(20, 12) → gcd(12, 8) → gcd(8, 4) → gcd(4, 0) = 4
```

- **Why it works:** anything that divides both a and b also divides `a % b`. So replacing a with `a % b` keeps the same GCD while the numbers shrink fast. **O(log min(a, b)).**
- **LCM:** `lcm(a, b) = a / gcd(a, b) * b`. Divide first to avoid overflow.
- C++17 has built-in versions: `std::gcd`, `std::lcm` (in `<numeric>`).

---

## Edge cases to always test

| Input | Why |
|---|---|
| `0` | the `while (n > 0)` loop never runs |
| a single digit | is it a palindrome? an Armstrong number? |
| a number with trailing zeros (`1200`) | reverse gives `21` |
| a negative number | `%` keeps the sign in C++: `-7 % 10 == -7` |
| a large number (around 2 × 10⁹) | the reverse or sum can overflow `int`, so use `long long` |
| a perfect square (`36`) | its √n divisor must not be added twice |
| `1` and `2` | the smallest non-prime and the smallest prime |

## Practice

1. Sum of digits of a number.
2. Check whether a number is a **strong number** (sum of factorials of its digits = n, e.g. 145).
3. Count the digits of n that evenly divide n (LeetCode "Count Digits That Divide a Number").
4. Print all primes up to n using the Sieve of Eratosthenes.
5. Find the prime factorisation of n in O(√n).
6. Find the GCD of an entire array.
