# TASK 9 — Implement and Test the Fare Logic (4 Marks)

## Complete testable C++ program

```cpp
#include <iostream>
#include <string>
using namespace std;

enum class Zone { Inner = 1, Middle = 2, Outer = 3 };

constexpr long long MIN_BALANCE = 5000;
constexpr int SURCHARGE = 20;

long long calculateFare(int zone, int hour, int minute) {
    if (zone < 1 || zone > 3 || hour < 0 || hour > 23 ||
        minute < 0 || minute > 59) return -1;

    long long fare = (zone == 1 ? 1000 : zone == 2 ? 2000 : 3000);
    int t = hour * 60 + minute;
    bool peak = (t >= 480 && t < 600) ||
                (t >= 1020 && t < 1200);

    if (peak) fare += fare * SURCHARGE / 100;
    return fare;
}

bool canTravel(long long balance, long long fare) {
    return fare >= 0 && balance - fare >= MIN_BALANCE;
}

int main() {
    struct Test {
        int zone, hour, minute;
        long long balance;
        long long expectedFare;
        bool expectedAllowed;
        const char* label;
    };

    Test tests[] = {
        {1, 12, 0, 10000, 1000, true,  "Inner off-peak"},
        {2, 9, 0, 10000, 2400, true,   "Middle peak"},
        {3, 18, 0, 10000, 3600, true,  "Outer peak"},
        {1, 10, 0, 6000, 1000, true,   "Exactly 10 AM"},
        {1, 20, 0, 6000, 1000, true,   "Exactly 8 PM"},
        {4, 12, 0, 10000, -1, false,   "Invalid zone"},
        {1, 8, 0, 6000, 1200, false,   "Leaves less than Rs. 50"},
        {1, 7, 0, 6000, 1000, true,    "Leaves exactly Rs. 50"}
    };

    int passed = 0;
    for (const Test& test : tests) {
        long long actualFare =
            calculateFare(test.zone, test.hour, test.minute);
        bool allowed = canTravel(test.balance, actualFare);

        bool ok = actualFare == test.expectedFare &&
                  allowed == test.expectedAllowed;

        cout << (ok ? "PASS: " : "FAIL: ") << test.label
             << " | fare=" << actualFare
             << " | allowed=" << boolalpha << allowed << '\n';

        if (ok) ++passed;
    }

    cout << "Passed " << passed << " of "
         << (sizeof(tests) / sizeof(tests[0])) << " tests.\n";
}
```

## Test table

| Test | Expected fare (paise) | Expected decision |
|---|---:|---|
| Inner off-peak | 1000 | Allow with sufficient balance |
| Middle peak | 2400 | Allow with sufficient balance |
| Outer peak | 3600 | Allow with sufficient balance |
| Exactly 10:00 AM | 1000 for Inner | Off-peak |
| Exactly 8:00 PM | 1000 for Inner | Off-peak |
| Invalid zone | -1 | Reject |
| Balance ₹60, peak Inner fare ₹12 | 1200 | Reject: only ₹48 would remain |
| Balance ₹60, off-peak Inner fare ₹10 | 1000 | Allow: exactly ₹50 remains |

A test table loop takes O(T) time for T test cases and uses O(T) space for the table. Adding a new boundary case is easy: add one row with the input and expected result.
