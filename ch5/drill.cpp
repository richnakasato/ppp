#include <iostream>

int main() {
    try {
        // code here...
        return 0;
    }
    catch (exception& e) {
        std::cerr << "error: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "Oops: unknown exception!\n";
        return 2;
    }
}
