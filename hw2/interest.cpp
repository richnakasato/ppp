#include <iostream>
#include <string>

int main() {
    double balance {0.0};
    int periods {0};
    double rate {0.0};
    std::cout << "balance: " << std::endl;
    std::cin >> balance;
    std::cout << "periods: " << std::endl;
    std::cin >> periods;
    std::cout << "rate: " << std::endl;
    std::cin >> rate;
    std::cout << "entered: " << balance << ", " << periods << ", " << rate << std::endl;
    for (int period=0; period<periods; ++period) {
        balance += balance * rate/100.0;
    }
    std::cout << "result: " << balance << std::endl;

    return 0;
}
