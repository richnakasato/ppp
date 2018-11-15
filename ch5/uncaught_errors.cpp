#include <iostream>
#include <stdexcept>

void error(const std::string& s1, const std::string& s2) {
    throw std::runtime_error(s1+s2);
}

int main() {
    std::string s1 = "hello";
    std::string s2 = "world";
    try {
        error(s1, s2);
    }
    catch (std::exception& e){
        std::cerr << "caught exception " << e.what() << std::endl;
    }
    return 0;
}
