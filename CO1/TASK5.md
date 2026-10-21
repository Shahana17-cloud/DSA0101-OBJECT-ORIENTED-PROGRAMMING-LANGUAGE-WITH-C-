# TASK 5 — Write Correct Expressions with the Right Precedence (4 Marks)

## Correct fare expressions

```cpp
bool peak = (hour >= 8 && hour < 10) ||
            (hour >= 17 && hour < 20);

fare = peak ? fare + fare * 20 / 100 : fare;

fare = fare - fare * concessionPercent / 100;
```

The peak-hour expression uses `&&` to combine the lower and upper bounds for each interval, and `||` to combine the morning and evening intervals. Parentheses make the intention clear. The surcharge and concession use integer arithmetic in paise.

## Operator precedence and associativity

- `*`, `/`, `%` have higher precedence than `+` and `-`.
- Arithmetic operators at the same precedence level generally associate left to right.
- Relational operators such as `>=` and `<` are evaluated before `&&`.
- `&&` has higher precedence than `||`.
- The conditional operator `?:` has lower precedence than arithmetic and comparison operators.
- Compound assignment such as `k += i` updates `k` using the result of the addition.

`x++` returns the old value and then increments `x`. `++y` increments `y` first and returns the new value. Therefore, `i = i++` is a mistake: it relies on confusing side effects and can lead to undefined behaviour in relevant C++ versions/contexts. Prefer `++i` or `i += 1`.

For integer division, C++ truncates toward zero. Thus `-10 / 3` is `-3`, and `-10 % 3` is `-1`.

## Predict the output

```cpp
#include <iostream>

int main()
{
    int x = 5, y = 3;
    std::cout << x + y * 2 << ' ' << (x + y) * 2 << '\n';

    int z = x++ + ++y;
    std::cout << z << ' ' << x << ' ' << y << '\n';

    std::cout << ((x > y ? x : y) << x % 4 * 2) << '\n';
    std::cout << 10 / 3 << ' ' << 10 % 3 << ' '
              << -10 / 3 << ' ' << -10 % 3 << '\n';

    int k = 0;
    for (int i = 0; i < 10; i += 3) k += i;
    std::cout << k << '\n';
}
```

### Expected output

```text
11 16
9 6 4
96
3 1 -3 -1
18
```

### Explanation
1. `x + y * 2` is `5 + 6 = 11`; parentheses in `(x + y) * 2` produce `16`.
2. `x++` contributes `5`, then `x` becomes `6`; `++y` makes `y` become `4` and contributes `4`. Therefore `z = 9`.
3. The conditional selects `x` (6). `%` and `*` are evaluated before the shift: `(x % 4) * 2 = 4`; `6 << 4` is `96`.
4. Integer division truncates toward zero; the remainder has the sign of the dividend.
5. The loop uses `i = 0, 3, 6, 9`, so `k = 18`.

## Lookup-table alternative
A `bool peak[24]` lookup table checks peak status in O(1), just like the logical expression. It can reduce repeated comparisons but uses about 24 bytes if `bool` is one byte, plus implementation-dependent overhead if stored in another structure. A table is convenient when many time rules exist; a clear expression is simpler for only two intervals.
