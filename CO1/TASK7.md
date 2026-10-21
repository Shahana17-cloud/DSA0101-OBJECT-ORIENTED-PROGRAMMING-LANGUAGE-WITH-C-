# TASK 7 — From Procedural to Object-Oriented (4 Marks)

## Procedural version

```cpp
#include <iostream>
using namespace std;

bool canTravel(long long balance, long long fare,
               long long minimumBalance) {
    return balance - fare >= minimumBalance;
}

int main() {
    long long balance = 10000;
    const long long minimumBalance = 5000;
    const long long fare = 3000;

    if (canTravel(balance, fare, minimumBalance)) {
        balance -= fare;
        cout << "Approved. Balance in paise: " << balance << '\n';
    } else {
        cout << "Rejected. Balance in paise: " << balance << '\n';
    }
}
```

## Object-oriented version

```cpp
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

    long long getBalance() const {
        return balance;
    }
};

int main() {
    SmartCard card(10000);

    if (card.deduct(3000))
        cout << "Approved. Balance in paise: "
             << card.getBalance() << '\n';
    else
        cout << "Rejected. Balance in paise: "
             << card.getBalance() << '\n';
}
```

## Comparison
Both examples have O(1) time and O(1) space for one transaction. The OOP version keeps `balance` private, so outside code cannot directly set it to a negative value. The class enforces the minimum-balance rule through `deduct()`.

If the balance were public, any part of the program could bypass validation, for example `card.balance = -500;`. This does not change complexity, but it weakens correctness and makes bugs harder to find. A centralized class is easier to update if the minimum balance changes.
