#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Account {
public:
    virtual double rate() const {
        return 3.5;
    }

    virtual ~Account() {
        cout << "Account destroyed\n";
    }
};

class SeniorAccount : public Account {
    double* history;

public:
    SeniorAccount() : history(new double[100]{}) {}

    double rate() const override {
        return 4.0;
    }

    ~SeniorAccount() override {
        delete[] history;
        cout << "SeniorAccount destroyed; history released\n";
    }
};

int main() {
    vector<unique_ptr<Account>> accounts;

    accounts.push_back(make_unique<Account>());
    accounts.push_back(make_unique<SeniorAccount>());

    for (const auto& a : accounts)
        cout << a->rate() << '\n';

    return 0;
}



<img width="274" height="128" alt="image" src="https://github.com/user-attachments/assets/9380afbf-939d-42ec-8a23-380223b264e8" />
