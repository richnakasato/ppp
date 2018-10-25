#include <iostream>

int main() {
    constexpr double yen {0.0089};
    constexpr double kroner {0.11};
    constexpr double pounds {1.29};
    constexpr double yuan {0.14};

    double amount {0.0};
    char unit {' '};

    std::cout << "Please enter an amount and a unit (y/k/p/c):" << std::endl;
    std::cin >> amount >> unit;

    std::string from_currency {""};
    double value {0.0};
    switch(unit) {
    case 'y':
        from_currency = "yen";
        value = amount*yen;
        break;

    case 'k':
        from_currency = "kroner";
        value = amount*kroner;
        break;

    case 'p':
        from_currency = "pounds";
        value = amount*pounds;
        break;

    case 'c':
        from_currency = "yuan";
        value = amount*yuan;
        break;

    default:
        std::cout << "Cannot convert " << amount << unit << " to USD" << std::endl;
        return -1;
    }

    std::cout << amount << " " << from_currency << " is " << value << " USD" << std::endl;
    return 0;
}
