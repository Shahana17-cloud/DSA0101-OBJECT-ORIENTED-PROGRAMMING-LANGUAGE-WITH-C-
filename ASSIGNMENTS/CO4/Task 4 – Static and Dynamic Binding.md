#include <iostream>
using namespace std;

struct Account {
    double rate() const {
        return 3.5;
    }

    virtual double vrate() const {
        return 3.5;
    }

    virtual ~Account() = default;
};

struct SeniorAccount : Account {
    double rate() const {
        return 4.0;
    }
<img width="143" height="57" alt="image" src="https://github.com/user-attachments/assets/4d735241-6561-4ad7-95c2-4be134a9881e" />

    double vrate() const override {
        return 4.0;
    }
};

int main() {
    SeniorAccount s;

    Account* p = &s;
    Account copy = s;

    cout << p->rate() << ' '
         << p->vrate() << ' '
         << copy.vrate() << '\n';

    return 0;
}
