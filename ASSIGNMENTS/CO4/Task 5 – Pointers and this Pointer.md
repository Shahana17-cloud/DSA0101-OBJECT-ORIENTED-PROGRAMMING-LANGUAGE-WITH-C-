#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class Cart {
    string items[10];
    double prices[10];
    int n = 0;
    double discount = 0;

public:
    Cart& add(const string& item, double price) {
        if (n < 10) {
            items[n] = item;
            prices[n] = price;
            ++n;
        }

        return *this;
    }

    Cart& setDiscount(double discount) {
        this->discount = discount;
        return *this;
    }

    double total() const {
        double t = 0;

        for (int i = 0; i < n; ++i)
            t += prices[i];

        return t * (100 - discount) / 100.0;
    }
};

int main() {
    Cart c;

    c.add("Rice", 60).add("Dal", 120).setDiscount(10);

    Cart* p = &c;
    p->add("Oil", 180);

    Cart& ref = c;

    cout << "Through reference: " << ref.total() << '\n';

    Cart* dynamicCart = new Cart;

    dynamicCart->add("Milk", 50);

    cout << "Dynamic cart: " << dynamicCart->total() << '\n';

    delete dynamicCart;

    cout << fixed << setprecision(2)
         << "Main cart total: " << p->total() << '\n';

    Cart a, b, d;

    a.add("Rice", 60);
    b.add("Rice", 60).add("Oil", 180);
    d.add("Dal", 120).add("Milk", 50);

    Cart* carts[] = { &a, &b, &d };

    int count = sizeof(carts) / sizeof(carts[0]);
    int best = 0;

    for (int i = 1; i < count; ++i) {
        if (carts[i]->total() > carts[best]->total())
            best = i;
    }

    cout << "Highest cart total: "
         << carts[best]->total() << '\n';

    return 0;
}

<img width="244" height="110" alt="image" src="https://github.com/user-attachments/assets/faa71d28-ed82-4900-8e42-f5f669eb1844" />
