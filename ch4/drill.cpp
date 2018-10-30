#include <iostream>
#include <vector>

void print(int lo, int hi) {
    std::cout << "the smaller value is: " << lo << std::endl;
    std::cout << "the larger value is: " << hi << std::endl;
}

void print(double lo, double hi) {
    std::cout << "the smaller value is: " << lo << std::endl;
    std::cout << "the larger value is: " << hi << std::endl;
}

void nearly_equal(double lo, double hi) {
    if (hi - lo < 1.0/100) {
        std::cout << "the numbers are almost equal" << std::endl;
    }
}

bool valid_units(const std::string &units) {
    if (units == "cm"
            || units == "in"
            || units == "ft"
            || units == "m") {
        return true;
    }
    else {
        return false;
    }
}

double convert_meters(const int &val, const std::string &units) {
    if (units == "cm") {
        return val * 0.01;
    }
    else if (units == "in") {
        return val * 0.0254;
    }
    else if (units == "ft") {
        return val * 0.3048;
    }
    else if (units == "m") {
        return val;
    }
    else {
        // error!
        return 0.0;
    }
}

int main() {
    double temp = {0}, lo = {0}, hi = {0}, sum = {0};
    int count = {0};
    std::string units = {};
    while(std::cin >> temp >> units) {
        if (valid_units(units)) {
            double meters = convert_meters(temp, units);
            sum += meters;
            ++count;
            std::cout << "entered: " << meters << " m" << std::endl;
            if (meters < lo || lo == 0) {
                lo = meters;
            }
            if (meters > hi || hi == 0) {
                hi = meters;
            }
        }
    }
    std::cout << "the smallest: " << lo << " m" << std::endl;
    std::cout << "the largest: " << hi << " m" << std::endl;
    std::cout << "count: " << count << " lengths" << std::endl;
    std::cout << "sum: " << sum << " m" << std::endl;

    return 0;
}
