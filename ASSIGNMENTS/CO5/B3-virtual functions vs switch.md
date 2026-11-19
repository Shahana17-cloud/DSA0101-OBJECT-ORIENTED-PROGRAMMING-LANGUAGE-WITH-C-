#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

class Bill {
public:
    virtual double total() const = 0;
    virtual ~Bill() {}
};

class OPBill : public Bill {
    double c, t;

public:
    OPBill(double x, double y) : c(x), t(y) {}

    double total() const override {
        return c + t;
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

struct SimpleBill {
    int type;
    double a, b, c;
};

double switchTotal(SimpleBill bill) {
    switch (bill.type) {
        case 1:
            return bill.a + bill.b;

        case 2:
            return bill.a * bill.b + bill.c;

        default:
            return 0;
    }
}

int main() {
    vector<Bill*> bills;
    vector<SimpleBill> simple;

    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            bills.push_back(new OPBill(500 + i, 1200));
            simple.push_back({1, 500.0 + i, 1200, 0});
        }
        else {
            bills.push_back(new IPBill(2, 2500, 10000 + i));
            simple.push_back({2, 2, 2500, 10000.0 + i});
        }
    }

    double vtotal = 0, stotal = 0;

    for (Bill* b : bills)
        vtotal += b->total();

    for (SimpleBill b : simple)
        stotal += switchTotal(b);

    cout << "Virtual total: " << vtotal << endl;
    cout << "Switch total: " << stotal << endl;
    cout << "Totals match: "
         << (vtotal == stotal ? "Yes" : "No") << endl;

    const int N = 1000000;
    double result = 0;

    auto start1 = chrono::high_resolution_clock::now();

    for (int i = 0; i < N; i++)
        result += bills[i % 10]->total();

    auto end1 = chrono::high_resolution_clock::now();

    auto start2 = chrono::high_resolution_clock::now();

    for (int i = 0; i < N; i++)
        result += switchTotal(simple[i % 10]);

    auto end2 = chrono::high_resolution_clock::now();

    double time1 = chrono::duration<double, milli>(end1 - start1).count();
    double time2 = chrono::duration<double, milli>(end2 - start2).count();

    cout << "Virtual function time (ms): " << time1 << endl;
    cout << "Switch time (ms): " << time2 << endl;
    cout << "Combined result: " << result << endl;

    for (Bill* b : bills)
        delete b;

    return 0;
}


<img width="269" height="157" alt="image" src="https://github.com/user-attachments/assets/706804df-41f4-4639-9517-3886f7c0849b" />
