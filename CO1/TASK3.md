# TASK 3 — Choose Data Types and Check Type Compatibility (4 Marks)

## 1. Data-Type Selection

| Value | Recommended type | Typical size | Reason |
|---|---|---:|---|
| Fare in paise | `long long` | 8 bytes | Exact integer arithmetic |
| Card balance | `long long` | 8 bytes | Supports large balances |
| Zone | `enum class Zone` | Usually 4 bytes | Restricts valid zone values |
| Peak-hour flag | `bool` | Usually 1 byte | Stores true or false |
| Passenger name | `string` | Varies | Stores text |
| Hour and minute | `int` | Usually 4 bytes | Stores time components |
| Journey count | `long long` | 8 bytes | Supports large totals |
| Surcharge percentage | `constexpr int` | Usually 4 bytes | Compile-time constant |

Sizes are typical, not guaranteed. Use `sizeof()` to inspect sizes and `<climits>` to inspect numeric limits.

## 2. Why Store Money in Integer Paise?
Floating-point values cannot represent every decimal fraction exactly. For example:

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double amount = 0.1 + 0.2;
    cout << fixed << setprecision(17) << amount << '\\n';
}
```

Possible output:

```text
0.30000000000000004
```

Integer paise avoids this binary floating-point rounding issue for amounts with at most two decimal places:

```cpp
long long fare = 3000; // Rs. 30.00
```

## 3. Type Compatibility

```cpp
int a = 7, b = 2;
double c = a / b;
double d = static_cast<double>(a) / b;
```

`c` becomes `3.0`, because integer division happens first. `d` becomes `3.5`, because `a` is converted to `double` before division.

## 4. Integer Range and Journey Counts
The network processes up to 3,000,000 journeys per day. If every journey costs ₹30:

3,000,000 × 3,000 paise = 9,000,000,000 paise.

This exceeds the maximum value of a typical signed 32-bit `int` (2,147,483,647). A `long long` is a safer choice for accumulated monetary totals.

## 5. Alternative Concept and Complexity
Both `double` and `long long` commonly occupy 8 bytes, and addition is O(1) for either type. However, integer paise avoids floating-point rounding errors. Adding N fares takes O(N) time overall. Integer overflow remains possible if totals exceed the selected type's range, so production systems should validate arithmetic and transaction limits.
