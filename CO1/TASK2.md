# TASK 2 — Use Tokens, Keywords, Identifiers and Constants Correctly (3 Marks)

## C++ Code

```cpp
#include <iostream>
using namespace std;

enum class Zone {
    Inner = 1,
    Middle = 2,
    Outer = 3
};

constexpr int INNER_FARE = 1000;   // Rs. 10 in paise
constexpr int MIDDLE_FARE = 2000;  // Rs. 20 in paise
constexpr int OUTER_FARE = 3000;   // Rs. 30 in paise
constexpr int SURCHARGE_PERCENT = 20;
constexpr int MIN_BALANCE = 5000;  // Rs. 50 in paise

int main() {
    Zone zone = Zone::Outer;
    int fare = OUTER_FARE;

    fare = fare + (fare * SURCHARGE_PERCENT) / 100;

    cout << "Fare in paise: " << fare << '\\n';
    return 0;
}
```

### Sample Output

```text
Fare in paise: 3600
```

## 1. Five Types of Tokens

| Token type | Examples | Purpose |
|---|---|---|
| Keywords | `int`, `class`, `return` | Reserved words with predefined meanings |
| Identifiers | `fare`, `MIN_BALANCE` | Names of variables, classes and functions |
| Constants | `20`, `5000`, `'A'` | Fixed values |
| Operators | `+`, `*`, `/`, `=` | Perform operations |
| Punctuators | `;`, `{}`, `()`, `::` | Structure statements and expressions |

## 2. `#define`, `const` and `constexpr`
- `#define` performs textual substitution before compilation and does not provide normal C++ type checking or ordinary variable scope.
- `const` declares a value that cannot be modified through that variable.
- `constexpr` declares a constant expression that can be evaluated at compile time when its initializer permits it.

Example:

```cpp
#define OLD_FARE 1000
const int MIN_BALANCE_LIMIT = 5000;
constexpr int OUTER_FARE_VALUE = 3000;
```

`constexpr` is preferred for compile-time fare values because it supports type checking, scope and debugging better than macros.

## 3. Why Use `enum class` for Zones?

```cpp
enum class Zone {
    Inner = 1,
    Middle = 2,
    Outer = 3
};
```

`enum class` defines a restricted set of zone values. Values must be qualified, such as `Zone::Outer`, and do not implicitly convert to integers. This reduces accidental mixing of zones with unrelated numeric values.

## 4. Identifier Naming Rules
- Identifiers may contain letters, digits and underscores.
- An identifier cannot begin with a digit.
- Keywords cannot be used as identifiers.
- Use `camelCase` for variables and functions, such as `calculateFare()`.
- Use uppercase names with underscores for constants, such as `MIN_BALANCE`.

## 5. Alternative Concept and Complexity
Replacing `constexpr` with `#define` removes type checking and scope protection. A macro itself does not occupy storage, whereas a `constexpr` variable may need storage if its address or other language requirements demand it. Compile-time constants usually introduce no runtime calculation. Neither choice changes the O(1) asymptotic time complexity of fare calculation.
