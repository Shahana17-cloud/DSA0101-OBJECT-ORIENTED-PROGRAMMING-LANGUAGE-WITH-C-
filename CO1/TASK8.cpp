#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;
int main() {
    int zone, hour, minute;
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
    while (!(cin >> hour >> minute) || hour < 0 || hour > 23 ||
           minute < 0 || minute > 59) {
        cout << "Invalid time. Enter hour (0-23) and minute (0-59): ";
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    cout << fixed << setprecision(2);
    cout << "\n--- Journey Report ---\nZone: " << zone
         << "\nFare-card balance: Rs. " << balancePaise / 100.0
         << "\nTime: " << setw(2) << setfill('0') << hour << ':'
         << setw(2) << minute << setfill(' ') << '\n';
}
