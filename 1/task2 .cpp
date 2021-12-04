#include <iostream>
#include <iomanip>

int main() {
    int choise;
    const double n_to_dyn=1e5, j_to_erg=1e7, am_to_oe=12.57e-3, f_to_cm= 8.99e11, c_to_esu= 2997924580;
    double value;
    std::cout << "Select the type of translation" << '\n'
        << "1.N to dyn" << '\n'
        << "2.J to erg" << '\n'
        << "3. A/m to Oe" << '\n'
        << "4. F to cm" << '\n'
        << "5. C to esu" << '\n';
    std::cin >> choise;

    std::cout << "Enter value:";

    std::cin >> value;

    switch (choise) {
        case 1:
            value = value * n_to_dyn;
            break;
        case 2:
            value = value * j_to_erg;
            break;
        case 3:
            value = value * am_to_oe;
            break;
        case 4:
            value = value * f_to_cm;
            break;
        case 5:
            value = value * c_to_esu;
            break;

    }
    std::cout << "Result:" << value;
    return 0;
}