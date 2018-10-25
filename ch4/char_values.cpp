#include <iostream>

int main() {
    constexpr char a {'a'};
    const int num_alpha {26};
    int count {0};
    while (count<num_alpha) {
        std::cout << char {a+count} << "\t" << int {a+count} << std::endl;
        ++count;
    }

    constexpr char A {'A'};
    constexpr char zed {'0'};
    const int num_digit {10};
    for (int i=0; i<num_alpha; ++i) {
        std::cout << char {A+i} << "\t" << int {A+i} << std::endl;
    }
    for (int i=0; i<num_digit; ++i) {
        std::cout << char {zed+i} << "\t" << int {zed+i} << std::endl;
    }

    return 0;
}
