#include <iostream>
#include <cmath>
#include <limits>

int main() {
    const double epsilon = std::numeric_limits<double>::epsilon();
    double a, b, c, d, x1, x2;
    std::cout << "Enter coefficient a: ";
    std::cin >> a;

    std::cout << "Enter coefficient b: ";
    std::cin >> b;

    std::cout << "Enter coefficient c: ";
    std::cin >> c;

    if (abs(a) < epsilon) {
        if (abs(b) < epsilon) {
            if (abs(c) < epsilon) {
                std::cout << "Endless solutions";
            }
            else {
                std::cout << "No solutions";
            }            
        }
        else {
            x1 = -c / b;
            std::cout << "Solution:" << '\n' << x1;
        }

    }
    else {
        d = b * b - 4.0 * a * c;
        if (d < -epsilon) {
            std::cout << "No solutions";
        }
        if (abs(d) < epsilon) {
            x1 = -b / (2.0 * a);
            std::cout << "Solution:" << '\n' << x1;
        }
        if (d > epsilon) {
            x1 = (-b + sqrt(d)) / (2.0 * a);
            x2 = (-b - sqrt(d)) / (2.0 * a);
            std::cout << "Solutions:" << '\n' << x1 << '\n' << x2;
        }

    }
    
    return 0;
}