#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Prescription {
    int n;
    string* medicines;

public:
    explicit Prescription(int count)
        : n(count), medicines(count > 0 ? new string[count] : nullptr) {
        if (count < 0)
            throw invalid_argument("Invalid medicine count");
    }

    // TODO 1: Deep copy constructor
    Prescription(const Prescription& other)
        : n(other.n),
          medicines(n > 0 ? new string[n] : nullptr) {
        for (int i = 0; i < n; i++)
            medicines[i] = other.medicines[i];

        cout << "Copy constructor called\n";
    }

    // TODO 2: Copy assignment operator
    Prescription& operator=(const Prescription& other) {
        if (this == &other)
            return *this;

        string* temp = other.n > 0
                     ? new string[other.n] : nullptr;

        for (int i = 0; i < other.n; i++)
            temp[i] = other.medicines[i];

        delete[] medicines;

        medicines = temp;
        n = other.n;

        return *this;
    }

    // TODO 3: Destructor
    ~Prescription() {
        delete[] medicines;
    }

    void set(int i, const string& m) {
        medicines[i] = m;
    }

    string get(int i) const {
        return medicines[i];
    }
};

int main() {
    Prescription p(2);

    p.set(0, "Paracetamol");
    p.set(1, "ORS");

    Prescription q = p;

    q.set(1, "Cetirizine");

    Prescription r(1);
    r = p;

    p = p; // Self-assignment test

    cout << p.get(0) << " " << p.get(1) << " | "
         << q.get(0) << " " << q.get(1) << " | "
         << r.get(0) << " " << r.get(1) << '\n';

    return 0;
}

<img width="382" height="46" alt="image" src="https://github.com/user-attachments/assets/575e3558-7fdd-4d76-99b5-a0c2756849e2" />
