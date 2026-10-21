# TASK 12 — Re-evaluate and Adapt the Design (8 Marks)

## Changed requirements
The metro adds:
1. A fourth Airport Zone with base fare ₹60.
2. A 10% weekend discount that does not combine with the peak surcharge.
3. A monthly pass allowing unlimited journeys in two selected zones.

## A. Impact Analysis
- Add `Airport` to `enum class Zone`.
- Add ₹6000 paise to the base-fare table.
- Update the fare calculation and all zone-validation checks.
- Introduce a weekend flag or date/policy object.
- Define the precedence between weekend discount and peak surcharge: on weekends, apply the 10% weekend discount and do not apply the peak surcharge.
- Add a `MonthlyPass` class storing the two eligible zones and pass validity dates.
- Update journey validation so a valid pass in an allowed zone can authorize travel according to the stated pass rules.

## B. Evaluate the Original Design
The original `switch` and `SmartCard` class can be retained, but every switch and zone-range check must be updated for the airport zone. Weekend rules should not be scattered across the program. A dedicated fare policy and pass class are more maintainable.

## C. Revised C++ example

```cpp
#include <array>
#include <iostream>
using namespace std;

enum class Zone { Inner = 0, Middle = 1, Outer = 2, Airport = 3 };

constexpr array<long long, 4> BASE_FARE = {
    1000, 2000, 3000, 6000
};
constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr int WEEKEND_DISCOUNT_PERCENT = 10;
constexpr long long MIN_BALANCE_PAISE = 5000;

long long calculateFare(Zone zone, bool peak, bool weekend) {
    int index = static_cast<int>(zone);
    if (index < 0 || index >= static_cast<int>(BASE_FARE.size()))
        return -1;

    long long amount = BASE_FARE[index];

    // Weekend discount replaces the peak surcharge.
    if (weekend) {
        amount -= amount * WEEKEND_DISCOUNT_PERCENT / 100;
    } else if (peak) {
        amount += amount * PEAK_SURCHARGE_PERCENT / 100;
    }

    return amount;
}

class MonthlyPass {
private:
    Zone firstZone;
    Zone secondZone;
    bool active;

public:
    MonthlyPass(Zone a, Zone b, bool isActive = true)
        : firstZone(a), secondZone(b), active(isActive) {}

    bool covers(Zone zone) const {
        return active && (zone == firstZone || zone == secondZone);
    }
};

class SmartCard {
private:
    long long balance;

public:
    explicit SmartCard(long long initialBalance)
        : balance(initialBalance) {}

    bool canTravel(long long fare) const {
        return fare >= 0 && balance - fare >= MIN_BALANCE_PAISE;
    }

    bool deduct(long long fare) {
        if (!canTravel(fare)) return false;
        balance -= fare;
        return true;
    }

    long long getBalance() const { return balance; }
};

int main() {
    cout << "Airport peak weekday fare (paise): "
         << calculateFare(Zone::Airport, true, false) << '\n';
    cout << "Airport weekend fare (paise): "
         << calculateFare(Zone::Airport, true, true) << '\n';

    MonthlyPass pass(Zone::Inner, Zone::Airport);
    cout << boolalpha
         << "Pass covers Airport: " << pass.covers(Zone::Airport) << '\n';
}
```

### Expected output

```text
Airport peak weekday fare (paise): 7200
Airport weekend fare (paise): 5400
Pass covers Airport: true
```

The example illustrates fare-policy separation and pass-zone checking. A full deployment must also check pass expiry, selected zones, and how monthly-pass journeys interact with card balance and minimum-balance rules. The assignment states that a pass permits unlimited journeys in two selected zones, so a covered journey should follow a clearly documented pass-payment policy rather than automatically charging the ordinary fare.

## D. Evidence-Based Defence
The airport fare is ₹60 off-peak and ₹72 during weekday peak hours. On weekends, the 10% discount gives ₹54 and the peak surcharge is not applied. These examples verify that the weekend discount does not combine with the peak surcharge.

A table-driven fare policy scales more easily than repeatedly extending a switch statement, while the `MonthlyPass` class isolates pass eligibility. The design should be retained with these modifications and tested at all fare boundaries.
