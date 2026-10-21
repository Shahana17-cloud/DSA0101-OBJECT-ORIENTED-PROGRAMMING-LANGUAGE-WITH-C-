#include <array>
#include <iostream>
using namespace std;
enum class Zone { Inner = 0, Middle = 1, Outer = 2, Airport = 3 };
constexpr array<long long, 4> BASE_FARE = {1000, 2000, 3000, 6000};
constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr int WEEKEND_DISCOUNT_PERCENT = 10;
constexpr long long MIN_BALANCE_PAISE = 5000;
long long calculateFare(Zone zone, bool peak, bool weekend) {
    int index = static_cast<int>(zone);
    if (index < 0 || index >= static_cast<int>(BASE_FARE.size())) return -1;
    long long amount = BASE_FARE[index];
    if (weekend) amount -= amount * WEEKEND_DISCOUNT_PERCENT / 100;
    else if (peak) amount += amount * PEAK_SURCHARGE_PERCENT / 100;
    return amount;
}
class MonthlyPass {
private:
    Zone firstZone, secondZone;
    bool active;
public:
    MonthlyPass(Zone a, Zone b, bool isActive = true)
        : firstZone(a), secondZone(b), active(isActive) {}
    bool covers(Zone zone) const {
        return active && (zone == firstZone || zone == secondZone);
    }
};
int main() {
    cout << "Airport peak weekday fare (paise): "
         << calculateFare(Zone::Airport, true, false) << '\n';
    cout << "Airport weekend fare (paise): "
         << calculateFare(Zone::Airport, true, true) << '\n';
    MonthlyPass pass(Zone::Inner, Zone::Airport);
    cout << boolalpha << "Pass covers Airport: " << pass.covers(Zone::Airport) << '\n';
}
