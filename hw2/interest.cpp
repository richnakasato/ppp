#include <iostream>
#include <string>
#include <vector>

struct CompoundInterest {
    double balance;
    int periods;
    double rate;
    double result;
};

void print_error() {
    std::cout << "\ninvalid entry, try again!\n";
}

bool check_input() {
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        print_error();
        return false;
    }
    return true;
}

bool validate_input(double balance, int periods, double rate) {
    if (balance < 0 || periods < 0 || rate < 0) {
        print_error();
        return false;
    }
    return true;
}

double calculate(double balance, int periods, double rate) {
    for (auto period=0; period<periods; ++period) {
        balance += balance * rate/100.0;
    }
    return balance;
}

std::vector<CompoundInterest> get_inputs() {
    std::vector<CompoundInterest> inputs;
    while (true) {
        CompoundInterest temp;
        std::cout << "balance: ";
        std::cin >> temp.balance;
        if (check_input()) {
            if (temp.balance == 0) { break; }
            else {
                std::cout << "periods: ";
                std::cin >> temp.periods;
                if (check_input()) {
                    std::cout << "rate: ";
                    std::cin >> temp.rate;
                    if (check_input()
                            && validate_input(temp.balance,
                                              temp.periods,
                                              temp.rate)) {
                        temp.result = calculate(temp.balance,
                                                temp.periods,
                                                temp.rate);
                        inputs.push_back(temp);
                    }
                }
            }
        }
    }
    return inputs;
}

void show_results(std::vector<CompoundInterest> inputs) {
    for (auto& input : inputs) {
        std::cout << "bal\t\tperiods\t\trate\t\tresult\n";
        std::cout << input.balance << "\t\t"
                  << input.periods << "\t\t"
                  << input.rate << "\t\t"
                  << input.result << "\t\t\n";
    }
}

int main() {
    std::vector<CompoundInterest> inputs;
    inputs = get_inputs();
    show_results(inputs);
    return 0;
}
