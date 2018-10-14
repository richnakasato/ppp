#include "../std_lib_facilities.h"

int main()
{
    std::string prev = " ";
    std::string curr;
    while (std::cin >> curr) {
        if (prev == curr) {
            std::cout << "repeated word: " << curr << std::endl;
        }
        prev = curr;
    }
    return 0;
}
