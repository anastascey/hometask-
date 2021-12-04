#include <iostream>

int main() {
    int x, y;
    std::cout << "X =";
    std::cin >> x;
    std::cout << "Y =";
    std::cin >> y;
    x = x + y;
    y = x - y;
    x = x - y;
    std::cout << "X = " << x << '\n' << "Y = " << y;
    return 0;
}