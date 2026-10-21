# TASK 8 — Read and Print Data Safely (4 Marks)

## C++ code with input validation

```cpp
#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;

int main() {
    int zone;
    int hour, minute;
    long long balancePaise;

    cout << "Enter zone (1-3): ";
    while (!(cin >> zone) || zone < 1 || zone > 3) {
        cout << "Invalid zone. Enter 1, 2, or 3: ";
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cout << "Enter balance in paise: ";
    while (!(cin >> balancePaise) || balancePaise < 0) {
        cout << "Invalid balance. Enter a non-negative integer: ";
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cout << "Enter hour and minute: ";
    while (!(cin >> hour >> minute) ||
           hour < 0 || hour > 23 || minute < 0 || minute > 59) {
        cout << "Invalid time. Enter hour (0-23) and minute (0-59): ";
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cout << fixed << setprecision(2);
    cout << "\n--- Journey Report ---\n";
    cout << "Zone: " << zone << '\n';
    cout << "Fare-card balance: Rs. "
         << balancePaise / 100.0 << '\n';
    cout << "Time: " << setw(2) << setfill('0') << hour
         << ':' << setw(2) << minute << setfill(' ') << '\n';
}
```

## Explanation
- `cin.fail()` detects failed extraction, such as letters entered where a number is required.
- `cin.clear()` resets the stream's error state.
- `cin.ignore()` discards the invalid characters through the end of the line.
- `fixed` and `setprecision(2)` display money with two decimal places.
- `setw()` sets the width for the next output field; `setfill('0')` pads the time with zeroes.

An alternative is `getline()` followed by `stoi()` inside `try/catch`. Reading a line takes O(L) time for a line of length L and requires O(L) buffer space. Direct numeric extraction is usually simpler, but recovery must be handled carefully to avoid repeating the same invalid input forever.
