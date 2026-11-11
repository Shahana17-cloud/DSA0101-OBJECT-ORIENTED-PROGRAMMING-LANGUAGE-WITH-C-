#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdexcept>
using namespace std;

class Complex {
    double real, imag;

public:
    // Default constructor
    Complex() : real(0), imag(0) {}

    // Real-only constructor
    Complex(double r) : real(r), imag(0) {}

    // Real and imaginary constructor
    Complex(double r, double i) : real(r), imag(i) {}

    double getReal() const {
        return real;
    }

    double getImag() const {
        return imag;
    }

    // Addition
    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    // Subtraction
    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    // Multiplication
    Complex operator*(const Complex& c) const {
        return Complex(
            real * c.real - imag * c.imag,
            real * c.imag + imag * c.real
        );
    }

    // Division
    Complex operator/(const Complex& c) const {
        double denominator =
            c.real * c.real + c.imag * c.imag;

        if (denominator == 0)
            throw domain_error("Division by zero complex impedance");

        return Complex(
            (real * c.real + imag * c.imag) / denominator,
            (imag * c.real - real * c.imag) / denominator
        );
    }

    // Equality
    bool operator==(const Complex& c) const {
        const double epsilon = 1e-9;

        return fabs(real - c.real) < epsilon &&
               fabs(imag - c.imag) < epsilon;
    }

    // Magnitude
    double magnitude() const {
        return sqrt(real * real + imag * imag);
    }

    // Stream insertion
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << fixed << setprecision(3) << c.real;

        if (c.imag >= 0)
            out << " + " << c.imag << "j";
        else
            out << " - " << -c.imag << "j";

        return out;
    }
};

int main() {
    const double w = 100.0;
    const double L = 0.01;
    const double C = 0.001;

    Complex R(10.0, 0.0);
    Complex ZL(0.0, w * L);
    Complex ZC(0.0, -1.0 / (w * C));

    // Series impedance
    Complex series = R + ZL + ZC;

    cout << "R = " << R << '\n';
    cout << "ZL = " << ZL << '\n';
    cout << "ZC = " << ZC << '\n';

    cout << "Series impedance = " << series << '\n';

    cout << "Series magnitude = "
         << series.magnitude() << '\n';

    // Parallel impedance
    Complex parallel = (R * ZL) / (R + ZL);

    cout << "R parallel L = " << parallel << '\n';

    // Division by zero test
    try {
        Complex invalid = R / Complex(0.0, 0.0);
        cout << invalid << '\n';
    }
    catch (const domain_error& e) {
        cout << "Error: " << e.what() << '\n';
    }

    return 0;
}


<img width="261" height="134" alt="image" src="https://github.com/user-attachments/assets/f0e05eb0-f58e-423e-9575-5a0d843bf77c" />
