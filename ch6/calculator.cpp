#include<iostream>
#include<string>

int main() {
    std::cout << "Please enter expression (+ or -): ";
    int lval = 0;
    int rval;
    char op;
    int res;
    std::cin>>lval>>op>>rval;

    if (op=='+') {
        res = lval + rval;
    }
    else if (op=='-') {
        res = lval - rval;
    }
    std::cout << "Result: " << res << '\n';
    return 0;
}
