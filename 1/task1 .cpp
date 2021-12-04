#include <iostream>
#include <iomanip>

int main() {
    std::string name;
    int price, temperature;
    bool hasCashback;
    std::cout << "Product's name: ";
    std::cin >> name;
    std::cout << "Product's price: ";
    std::cin >> price;
    std::cout << "Is cash-back available for this product? (true/false) ";
    std::cin >> std::boolalpha >> hasCashback;
    std::cout << "Maximum storing temperature: ";
    std::cin >> temperature;

    std::cout << '\n' << name;

    std::cout << '\n' << std::setw(17) << std::setfill('.') << std::left << "Price:";
    std::cout << std::right<< std::setw(8) << std::setfill('0') << std::uppercase << std::hex << price;

    std::cout << std::setfill('.') << '\n' << "Has cash-back:" << std::setw(11) << std::boolalpha << hasCashback
    
    << '\n' << "Max temperature:" << std::setw(9) << std::showpos << std::dec << temperature << "\n\n";

    return 0;
}