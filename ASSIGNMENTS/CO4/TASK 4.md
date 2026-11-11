#include <iostream>
using namespace std;

struct Engine {
    Engine() {
        cout << "Engine ";
    }

    ~Engine() {
        cout << "~Engine ";
    }
};

struct Vehicle {
    Vehicle() {
        cout << "Vehicle ";
    }

    ~Vehicle() {
        cout << "~Vehicle ";
    }
};

struct Car : Vehicle {
    Engine e;

    Car() {
        cout << "Car ";
    }

    ~Car() {
        cout << "~Car ";
    }
};

int main() {
    {
        Car c;
        cout << "| ";
    }

    cout << '\n';

    return 0;
}
<img width="307" height="57" alt="image" src="https://github.com/user-attachments/assets/6ed45d95-cd36-4978-871d-c03f84ca09e0" />
