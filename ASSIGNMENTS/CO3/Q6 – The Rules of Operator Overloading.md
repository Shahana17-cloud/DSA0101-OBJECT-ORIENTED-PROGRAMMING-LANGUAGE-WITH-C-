#include <iostream>
#include <cstring>
using namespace std;

class Text {
    char* data;

public:
    // Constructor
    Text(const char* s = "") {
        if (s == nullptr)
            s = "";

        data = new char[strlen(s) + 1];
        strcpy(data, s);
    }

    // Copy constructor
    Text(const Text& t) {
        data = new char[strlen(t.data) + 1];
        strcpy(data, t.data);
    }

    // Copy assignment operator
    Text& operator=(const Text& t) {
        if (this == &t)
            return *this;

        char* temp = new char[strlen(t.data) + 1];
        strcpy(temp, t.data);

        delete[] data;
        data = temp;

        return *this;
    }

    // Concatenation operator
    Text operator+(const Text& t) const {
        size_t len = strlen(data) + strlen(t.data);

        char* temp = new char[len + 1];

        strcpy(temp, data);
        strcat(temp, t.data);

        Text result(temp);

        delete[] temp;

        return result;
    }

    // Equality operator
    bool operator==(const Text& t) const {
        return strcmp(data, t.data) == 0;
    }

    // Inequality operator
    bool operator!=(const Text& t) const {
        return !(*this == t);
    }

    // Stream insertion operator
    friend ostream& operator<<(ostream& out, const Text& t) {
        out << t.data;
        return out;
    }

    // Destructor
    ~Text() {
        delete[] data;
    }
};

int main() {
    Text a("Hello ");
    Text b("World");
    Text c("!");

    Text result = a + b + c;

    cout << result << '\n';

    Text empty("");
    Text longMessage("This is a longer SMS message used for testing.");

    cout << "Empty=[" << empty << "]\n";
    cout << longMessage << '\n';

    a = a; // Self-assignment test

    Text copy = a;

    cout << boolalpha;
    cout << (copy == a) << " " << (copy != b) << '\n';

    return 0;
}


<img width="295" height="102" alt="image" src="https://github.com/user-attachments/assets/50134666-31d8-4f32-af2d-dcc600ee3271" />
