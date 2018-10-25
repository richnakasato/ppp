#include <iostream>

int square(int x) {
    int retval = 0;
    for (int i=0; i<x; ++i) {
        retval+=x;
    }
    return retval;
}

int main() {
    int i = 0;
    while (i<100) {
        std::cout << i << '\t' << square(i) << std::endl;
        ++i;
    }
    return 0;
}
