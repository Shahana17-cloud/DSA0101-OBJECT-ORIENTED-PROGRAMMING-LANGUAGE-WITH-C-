# TASK 10 — Compare Expectations with Execution (4 Marks)

## Network total calculations

Assuming every journey costs ₹30:

| Journeys | Total in rupees | Total in paise |
|---:|---:|---:|
| 20,000 | ₹600,000 | 60,000,000 |
| 500,000 | ₹15,000,000 | 1,500,000,000 |
| 3,000,000 | ₹90,000,000 | 9,000,000,000 |

A typical signed 32-bit `int` has a maximum value of 2,147,483,647. Therefore, the total in paise for 3,000,000 journeys overflows a 32-bit `int`. The total in rupees, ₹90,000,000, fits in a typical 32-bit signed integer, but using `long long` is safer for intermediate and accumulated values.

## C++ comparison program

```cpp
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    const long long farePaise = 3000;
    const long long counts[] = {20000, 500000, 3000000};

    for (long long n : counts) {
        long long integerTotalPaise = n * farePaise;
        double doubleTotalRupees = n * 30.0;

        cout << "Journeys: " << n << '\n';
        cout << "Integer paise total: " << integerTotalPaise << '\n';
        cout << fixed << setprecision(2)
             << "Double rupee total: Rs. " << doubleTotalRupees << '\n';
        cout << "Integer rupee total: Rs. "
             << integerTotalPaise / 100 << "\n\n";
    }
}
```

## Discussion
- `int` may overflow when accumulating large totals in paise.
- `long long` supports much larger integer totals and preserves exact paise arithmetic, as long as the range is not exceeded.
- `double` supports a wide range but can represent decimal fractions approximately; it is not ideal for exact financial totals.
- `-Wall -Wextra` enables common compiler warnings, such as unused variables, suspicious conversions, and missing return paths. The exact warnings depend on the compiler and code.
- Each addition is O(1); summing N journeys is O(N). A `long long` and a `double` commonly use 8 bytes per variable.
