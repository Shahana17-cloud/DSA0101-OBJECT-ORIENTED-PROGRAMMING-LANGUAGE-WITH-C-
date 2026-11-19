#include <iostream>
using namespace std;

class Bill {
public:
    virtual double total() const = 0;
    virtual ~Bill() {}
};

class OPBill : public Bill {
    double consultation, tests;

public:
    OPBill(double c, double t) : consultation(c), tests(t) {}

    double total() const override {
        return consultation + tests;
    }
};

class IPBill : public Bill {
    int days;
    double rate, surgery;

public:
    IPBill(int d, double r, double s)
        : days(d), rate(r), surgery(s) {}

    double total() const override {
        return days * rate + surgery;
    }
};

// New bill type
class DayCareBill : public Bill {
    double price;

public:
    DayCareBill(double p) : price(p) {}

    double total() const override {
        return price;
    }
};

class Payer {
public:
    virtual double pay(double amount) const = 0;
    virtual ~Payer() {}
};

class SelfPay : public Payer {
public:
    double pay(double amount) const override {
        return amount;
    }
};

class Insurance : public Payer {
    double limit, percentage;

public:
    Insurance(double l, double p) : limit(l), percentage(p) {}

    double pay(double amount) const override {
        double covered = amount * percentage / 100;

        if (covered > limit)
            covered = limit;

        return covered;
    }
};

// New payer type
class CorporatePayer : public Payer {
    double percentage;

public:
    CorporatePayer(double p) : percentage(p) {}

    double pay(double amount) const override {
        return amount * percentage / 100;
    }
};

int main() {
    Bill* bill = new DayCareBill(15000);
    Payer* payer = new CorporatePayer(80);

    double amount = bill->total();
    double paid = payer->pay(amount);

    cout << "Bill amount: " << amount << endl;
    cout << "Paid amount: " << paid << endl;
    cout << "Patient amount: " << amount - paid << endl;

    delete bill;
    delete payer;

    return 0;
}

<img width="163" height="109" alt="image" src="https://github.com/user-attachments/assets/658fe7f4-fd38-4d3d-9de8-83cc9df0a1b6" />

