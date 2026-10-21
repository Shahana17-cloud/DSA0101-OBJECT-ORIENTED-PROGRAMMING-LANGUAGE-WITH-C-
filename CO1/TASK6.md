# TASK 6 — Design the Control Structures (4 Marks)

## Pseudocode

```text
INPUT balance
FOR each journey
    INPUT zone, hour, minute
    IF input is invalid
        SKIP this journey
    END IF
    peak = time is in [08:00, 10:00) OR [17:00, 20:00)
    baseFare = fare selected by zone
    IF peak
        baseFare = baseFare + baseFare * surchargePercent / 100
    END IF
    IF balance - baseFare >= minimumBalance
        deduct baseFare
        PRINT approved journey and new balance
    ELSE
        PRINT denied journey
    END IF
END FOR
```

## Completed C++ code

```cpp
#include <iomanip>
#include <iostream>
using namespace std;

enum class Zone { Inner, Middle, Outer };

constexpr long long BASE_PAISE[] = {1000, 2000, 3000};
constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long MIN_BALANCE_PAISE = 5000;

long long fare(Zone z, bool peak) {
    long long amount = 0;

    switch (z) {
        case Zone::Inner:  amount = BASE_PAISE[0]; break;
        case Zone::Middle: amount = BASE_PAISE[1]; break;
        case Zone::Outer:  amount = BASE_PAISE[2]; break;
        default: return -1;
    }

    if (peak)
        amount += amount * PEAK_SURCHARGE_PERCENT / 100;

    return amount;
}

bool canTravel(long long balance, long long f) {
    return f >= 0 && balance - f >= MIN_BALANCE_PAISE;
}

bool isPeak(int hour, int minute) {
    int t = hour * 60 + minute;
    return (t >= 8 * 60 && t < 10 * 60) ||
           (t >= 17 * 60 && t < 20 * 60);
}

int main() {
    long long balance = 10000; // Rs. 100 in paise
    struct Trip { Zone zone; bool peak; };
    Trip trips[] = {
        {Zone::Inner, false},
        {Zone::Outer, true},
        {Zone::Middle, false}
    };

    for (const Trip& t : trips) {
        long long f = fare(t.zone, t.peak);

        if (canTravel(balance, f)) {
            balance -= f;
            cout << "Fare Rs " << f / 100 << "."
                 << setw(2) << setfill('0') << f % 100
                 << setfill(' ') << " balance Rs "
                 << balance / 100 << '\n';
        } else {
            cout << "Denied (low balance) balance Rs "
                 << balance / 100 << '\n';
        }
    }

    cout << "10:00 AM peak? " << boolalpha << isPeak(10, 0) << '\n';
    cout << "8:00 PM peak? " << boolalpha << isPeak(20, 0) << '\n';
}
```

### Expected output

```text
Fare Rs 10.00 balance Rs 90
Fare Rs 36.00 balance Rs 54
Denied (low balance) balance Rs 54
10:00 AM peak? false
8:00 PM peak? false
```

The intervals include 8:00 AM and 5:00 PM but exclude 10:00 AM and 8:00 PM.

## Control-structure choices
- Use `if/else` for peak status and balance validation.
- Use `switch` for the small fixed set of zones.
- Use a `for` loop when the number of journeys is known.
- Use a range-based `for` loop to iterate over a collection of journeys.
- Use `while` when journeys arrive until a sentinel or end-of-input.
- Use `continue` to skip an invalid journey and `break` to stop processing.
- If no `switch` case matches and there is no `default`, no case body runs.

A fare array indexed by zone can be O(1), just like a switch. The array is compact, but adding zones requires updating the array and validating the index. A switch can be clearer for a small fixed set and can explicitly reject unsupported values.
