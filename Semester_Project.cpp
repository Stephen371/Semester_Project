#include <iostream>
#include <cmath>

using namespace std;

class Calculator {
public:
    double add(double a, double b) {
        return a + b;
    }

    double subtract(double a, double b) {
        return a - b;
    }

    double multiply(double a, double b) {
        return a * b;
    }

    double divide(double a, double b) {
        if (b != 0) {
            return a / b;
        } else {
            throw ::invalid_argument("Division by zero");
        }
    }

    double power(double base, double exponent) {
        return ::pow(base, exponent);
    }

    double squareRoot(double x) {
        if (x >= 0) {
            return ::sqrt(x);
        } else {
            throw ::invalid_argument("Square root of negative number");
        }
    }

    double sine(double angle) {
        return ::sin(angle);
    }

    double cosine(double angle) {
        return ::cos(angle);
    }

    double logarithm(double base, double x) {
        if (base > 0 && x > 0) {
            return ::log(x) / std::log(base);
        } else {
            throw ::invalid_argument("Invalid logarithm arguments");
        }
    }


};

int main() {
    Calculator calculator;

    double a = 10.0;
    double b = 5.0;
    double angle = 30.0; // Angle in degrees

    cout << "Addition: " << calculator.add(a, b) << endl;
    cout << "Subtraction: " << calculator.subtract(a, b) << endl;
    cout << "Multiplication: " << calculator.multiply(a, b) << endl;

    try {
        cout << "Division: " << calculator.divide(a, b) << endl;
    } catch (const std::exception &e) {
        cerr << "Error: " << e.what() << endl;
    }

    cout << "Power: " << calculator.power(a, b) << endl;

    try {
        cout << "Square Root of " << a << ": " << calculator.squareRoot(a) << endl;
        cout << "Square Root of " << -a << ": " << calculator.squareRoot(-a) << endl;
    } catch (const exception &e) {
        cerr << "Error: " << e.what() << std::endl;
    }

    cout << "Sine of " << angle << " degrees: " << calculator.sine(angle * M_PI / 180.0) << endl;
    cout << "Cosine of " << angle << " degrees: " << calculator.cosine(angle * M_PI / 180.0) << endl;

    try {
        double base = 2.0;
        double x = 8.0;
        cout << "Logarithm base " << base << " of " << x << ": " << calculator.logarithm(base, x) << endl;
    } catch (const std::exception &e) {
        cerr << "Error: " << e.what() << endl;
    }


    return 0;
}
