# TASK 4 — Control Implicit Conversions (4 Marks)

## 1. Given C++ Program

```cpp
#include <iostream>

int main()
{
    int a = 7, b = 2;
    double c = a / b;
    double d = static_cast<double>(a) / b;
    std::cout << c << ' ' << d << '\\n';

    char ch = 'A' + 2;
    std::cout << ch << ' ' << ch + 1 << '\\n';

    bool flag = 5;
    std::cout << flag << ' ' << std::boolalpha
              << flag << '\\n';

    unsigned int u = 1;
    int s = -1;
    std::cout << (s < u ? "s < u" : "s >= u") << '\\n';
}
```

## 2. Predicted Output

```text
3 3.5
C 68
1 true
s >= u
```

## 3. Explanation of Conversions

### Integer division
`a / b` performs integer division and produces `3`. Assigning it to a `double` converts the result to `3.0`, which prints as `3`.

### Explicit conversion
`static_cast<double>(a)` converts `a` before division. Therefore, the result is `3.5`.

### Character promotion
`'A' + 2` produces the character corresponding to `C` on ASCII-compatible systems. In `ch + 1`, `ch` is promoted to an integer, producing `68` for ASCII-compatible `D`.

### Integer-to-boolean conversion
The integer `5` converts to `true` because it is nonzero. By default, `true` prints as `1`; after `std::boolalpha`, it prints as `true`.

### Signed-to-unsigned conversion
In `s < u`, the usual arithmetic conversions convert `s` to an unsigned integer on typical systems where `int` and `unsigned int` have the same rank. The converted value is very large, so the comparison is false and the program prints `s >= u`.

## 4. How to Prevent Conversion Errors
- Use `static_cast<double>()` when floating-point division is intended.
- Use brace initialization, such as `int x{3}`, to detect narrowing conversions.
- Avoid mixing signed and unsigned integers unnecessarily.
- Use `std::boolalpha` when readable boolean output is required.

## 5. Alternative Concept and Complexity
Explicit casts improve readability but do not automatically guarantee safe conversions. Brace initialization catches certain narrowing conversions at compile time. Explicit casts generally do not change asymptotic runtime or memory usage. Some mistakes are caught at compile time, while invalid values must still be validated at runtime.
