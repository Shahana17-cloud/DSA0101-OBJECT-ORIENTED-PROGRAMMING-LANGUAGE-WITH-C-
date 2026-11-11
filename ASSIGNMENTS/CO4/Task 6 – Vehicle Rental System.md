#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Vehicle {
protected:
    string regNo;
    double dailyRate;
    bool rented = false;

public:
    Vehicle(string reg, double rate)
        : regNo(reg), dailyRate(rate) {}

    virtual double charge(int days) const = 0;

    bool rent() {
        if (rented)
            return false;

        rented = true;
        return true;
    }

    void returnVehicle() {
        rented = false;
    }

    bool isRented() const {
        return rented;
    }

    string registration() const {
        return regNo;
    }

    virtual void display() const {
        cout << regNo << " | daily rate: " << dailyRate
             << " | " << (rented ? "Rented" : "Available") << '\n';
    }

    virtual ~Vehicle() = default;
};

class Bicycle : public Vehicle {
public:
    Bicycle(string reg, double rate)
        : Vehicle(reg, rate) {}

    double charge(int days) const override {
        return days * dailyRate;
    }
};

class MotorVehicle : public Vehicle {
protected:
    double fuelLevel;
    string serviceDueDate;

public:
    MotorVehicle(string reg, double rate, double fuel, string due)
        : Vehicle(reg, rate), fuelLevel(fuel), serviceDueDate(due) {}
};

class TwoWheeler : public MotorVehicle {
public:
    TwoWheeler(string reg, double rate, double fuel, string due)
        : MotorVehicle(reg, rate, fuel, due) {}

    double charge(int days) const override {
        return days * dailyRate + 50.0;
    }
};

class Car : public MotorVehicle {
protected:
    int seats;

public:
    Car(string reg, double rate, double fuel, string due, int s)
        : MotorVehicle(reg, rate, fuel, due), seats(s) {}

    double charge(int days) const override {
        return days * dailyRate + 200.0;
    }
};

class ElectricCar : public Car {
    double batteryCapacity, pricePerKWh;

public:
    ElectricCar(string reg, double rate, double fuel, string due,
                int s, double battery, double tariff)
        : Car(reg, rate, fuel, due, s),
          batteryCapacity(battery), pricePerKWh(tariff) {}

    double charge(int days) const override {
        return days * dailyRate + batteryCapacity * pricePerKWh;
    }
};

class ElectricBus : public Vehicle {
    int passengerCapacity;
    double batteryKWh, pricePerKWh;

public:
    ElectricBus(string reg, double rate, int passengers,
                double battery, double tariff)
        : Vehicle(reg, rate), passengerCapacity(passengers),
          batteryKWh(battery), pricePerKWh(tariff) {}

    double charge(int days) const override {
        return days * dailyRate + batteryKWh * pricePerKWh;
    }
};

int main() {
    vector<unique_ptr<Vehicle>> fleet;

    fleet.push_back(make_unique<Bicycle>("BI-101", 100));

    fleet.push_back(make_unique<TwoWheeler>(
        "TW-202", 250, 80, "2027-01-15"));

    fleet.push_back(make_unique<Car>(
        "CA-303", 1500, 60, "2027-02-01", 5));

    fleet.push_back(make_unique<ElectricCar>(
        "EV-404", 1800, 0, "2027-02-10", 5, 60, 8));

    fleet.push_back(make_unique<ElectricBus>(
        "EB-505", 3000, 40, 120, 9));

    cout << "FLEET LIST\n";

    for (const auto& v : fleet)
        v->display();

    cout << "\nRENTAL AND RETURN DEMONSTRATION\n";

    for (const auto& v : fleet) {
        if (v->rent()) {
            int days = 2;
            double base = v->charge(days);

            int lateDays = 1;
            double lateFee = lateDays * 150.0;

            cout << v->registration()
                 << " rented. Base charge = " << base
                 << ", late fee = " << lateFee
                 << ", total = " << base + lateFee << '\n';

            v->returnVehicle();
        }
    }

    cout << "\nAFTER RETURN\n";

    for (const auto& v : fleet)
        v->display();

    return 0;
}
<img width="265" height="106" alt="image" src="https://github.com/user-attachments/assets/4d87add2-efcb-43aa-8e1e-0f186d20fada" />
<img width="390" height="108" alt="image" src="https://github.com/user-attachments/assets/41efc872-c484-4664-bf4d-8c14333f5058" />
<img width="282" height="107" alt="image" src="https://github.com/user-attachments/assets/b1054581-cd45-40f0-96df-bad5bbb4b3f4" />
