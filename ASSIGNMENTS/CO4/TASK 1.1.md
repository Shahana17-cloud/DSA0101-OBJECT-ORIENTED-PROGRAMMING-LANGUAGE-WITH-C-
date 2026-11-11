#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Staff {
protected:
    string name;
    int staffId;
    double basicPay;

public:
    Staff(string n, int id, double basic)
        : name(n), staffId(id), basicPay(basic) {}

    virtual double pay() const = 0;

    virtual void display() const {
        cout << name << " (" << staffId << ") : "
             << fixed << setprecision(2) << pay() << '\n';
    }

    virtual ~Staff() = default;
};

class Professor : public Staff {
    double researchAllowance;

public:
    Professor(string n, int id, double basic, double research)
        : Staff(n, id, basic), researchAllowance(research) {}

    double pay() const override {
        return basicPay + basicPay * 0.42 + researchAllowance;
    }
};

class LabAssistant : public Staff {
    double allowance;

public:
    LabAssistant(string n, int id, double basic, double extra)
        : Staff(n, id, basic), allowance(extra) {}

    double pay() const override {
        return basicPay + basicPay * 0.42 + allowance;
    }
};

class GuestFaculty : public Staff {
    double hours, hourlyRate;

public:
    GuestFaculty(string n, int id, double h, double r)
        : Staff(n, id, 0.0), hours(h), hourlyRate(r) {}

    double pay() const override {
        return hours * hourlyRate;
    }
};

int main() {
    vector<unique_ptr<Staff>> staff;

    staff.push_back(make_unique<Professor>("Anita", 101, 50000, 8000));
    staff.push_back(make_unique<LabAssistant>("Bala", 102, 30000, 2000));
    staff.push_back(make_unique<GuestFaculty>("Charu", 103, 40, 750));

    for (const auto& person : staff)
        person->display();

    return 0;
}


<img width="231" height="77" alt="Screenshot 2026-11-11 124702" src="https://github.com/user-attachments/assets/8bd5a284-84f4-424e-8b2f-65adf1a33357" />
