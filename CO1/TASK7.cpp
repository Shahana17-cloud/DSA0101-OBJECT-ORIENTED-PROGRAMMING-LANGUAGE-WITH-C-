#include <iostream>
using namespace std;
class SmartCard {
private:
    long long balance;
    const long long minimumBalance;
public:
    SmartCard(long long initialBalance, long long minimum = 5000)
        : balance(initialBalance), minimumBalance(minimum) {}
    bool canTravel(long long fare) const {
        return fare >= 0 && balance - fare >= minimumBalance;
    }
    bool deduct(long long fare) {
        if (!canTravel(fare)) return false;
        balance -= fare;
        return true;
    }
    long long getBalance() const { return balance; }
};
int main() {
    SmartCard card(10000);
    if (card.deduct(3000))
        cout << "Approved. Balance in paise: " << card.getBalance() << '\n';
    else
        cout << "Rejected. Balance in paise: " << card.getBalance() << '\n';
}
