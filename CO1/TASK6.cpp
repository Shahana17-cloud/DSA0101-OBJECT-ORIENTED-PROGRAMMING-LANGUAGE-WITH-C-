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
        case Zone::Inner: amount = BASE_PAISE[0]; break;
        case Zone::Middle: amount = BASE_PAISE[1]; break;
        case Zone::Outer: amount = BASE_PAISE[2]; break;
        default: return -1;
    }
    if (peak) amount += amount * PEAK_SURCHARGE_PERCENT / 100;
    return amount;
}
bool canTravel(long long balance, long long f) {
    return f >= 0 && balance - f >= MIN_BALANCE_PAISE;
}
bool isPeak(int hour, int minute) {
    int t = hour * 60 + minute;
    return (t >= 480 && t < 600) || (t >= 1020 && t < 1200);
}
int main() {
    long long balance = 10000;
    struct Trip { Zone zone; bool peak; };
    Trip trips[] = {{Zone::Inner, false}, {Zone::Outer, true}, {Zone::Middle, false}};
    for (const Trip& t : trips) {
        long long f = fare(t.zone, t.peak);
        if (canTravel(balance, f)) {
            balance -= f;
            cout << "Fare Rs " << f / 100 << "." << setw(2) << setfill('0')
                 << f % 100 << setfill(' ') << " balance Rs " << balance / 100 << '\n';
        } else cout << "Denied (low balance) balance Rs " << balance / 100 << '\n';
    }
    cout << "10:00 AM peak? " << boolalpha << isPeak(10, 0) << '\n';
    cout << "8:00 PM peak? " << boolalpha << isPeak(20, 0) << '\n';
}
