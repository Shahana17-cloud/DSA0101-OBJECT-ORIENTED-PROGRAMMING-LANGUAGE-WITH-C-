#include <iostream>
#include <iomanip>
using namespace std;

class Money {
    long long paise;

public:
    Money(long long rupees = 0, int p = 0)
        : paise(rupees * 100 + p) {}

    Money operator+(const Money& m) const {
        Money result;
        result.paise = paise + m.paise;
        return result;
    }

    Money operator-(const Money& m) const {
        Money result;
        result.paise = paise - m.paise;
        return result;
    }

    Money& operator+=(const Money& m) {
        paise += m.paise;
        return *this;
    }

    bool operator==(const Money& m) const {
        return paise == m.paise;
    }

    bool operator<(const Money& m) const {
        return paise < m.paise;
    }

    friend ostream& operator<<(ostream& out, const Money& m) {
        long long value = m.paise;
        if (value < 0) {
            out << "-";
            value = -value;
        }

        out << "Rs " << value / 100 << "."
            << setw(2) << setfill('0') << value % 100
            << setfill(' ');

        return out;
    }

    friend istream& operator>>(istream& in, Money& m) {
        long long rupees;
        int p;

        if (in >> rupees >> p)
            m.paise = rupees * 100 + p;

        return in;
    }
};

int main() {
    Money a(120, 75), b(79, 25);

    Money c = a + b;

    cout << c << '\n';
    cout << boolalpha << (c == Money(200)) << '\n';

    Money carry = Money(0, 75) + Money(0, 50);
    cout << carry << '\n';

    Money negative = Money(5, 0) - Money(8, 25);
    cout << negative << '\n';

    Money bill(100, 0);
    bill += a;

    cout << "Bill: " << bill << '\n';

    return 0;
}


<img width="149" height="151" alt="image" src="https://github.com/user-attachments/assets/502531e7-6564-48e3-bac0-98f769e7419f" />
