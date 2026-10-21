#include <iostream>
using namespace std;
long long calculateFare(int zone, int hour, int minute) {
    if (zone < 1 || zone > 3 || hour < 0 || hour > 23 ||
        minute < 0 || minute > 59) return -1;
    long long fare = (zone == 1 ? 1000 : zone == 2 ? 2000 : 3000);
    int t = hour * 60 + minute;
    bool peak = (t >= 480 && t < 600) || (t >= 1020 && t < 1200);
    if (peak) fare += fare * 20 / 100;
    return fare;
}
bool canTravel(long long balance, long long fare) {
    return fare >= 0 && balance - fare >= 5000;
}
int main() {
    struct Test { int zone, hour, minute; long long balance, expectedFare;
        bool expectedAllowed; const char* label; };
    Test tests[] = {
        {1,12,0,10000,1000,true,"Inner off-peak"},
        {2,9,0,10000,2400,true,"Middle peak"},
        {3,18,0,10000,3600,true,"Outer peak"},
        {1,10,0,6000,1000,true,"Exactly 10 AM"},
        {1,20,0,6000,1000,true,"Exactly 8 PM"},
        {4,12,0,10000,-1,false,"Invalid zone"},
        {1,8,0,6000,1200,false,"Leaves less than Rs. 50"},
        {1,7,0,6000,1000,true,"Leaves exactly Rs. 50"}
    };
    int passed = 0;
    for (const Test& t : tests) {
        long long actual = calculateFare(t.zone,t.hour,t.minute);
        bool allowed = canTravel(t.balance,actual);
        bool ok = actual == t.expectedFare && allowed == t.expectedAllowed;
        cout << (ok ? "PASS: " : "FAIL: ") << t.label
             << " | fare=" << actual << " | allowed=" << boolalpha << allowed << '\n';
        if (ok) ++passed;
    }
    cout << "Passed " << passed << " of " << sizeof(tests)/sizeof(tests[0]) << " tests.\n";
}
