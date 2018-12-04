#include <iostream>
#include <vector>
#include <limits>

int main() {

    std::vector<double> temps;
    for(double x; std::cin >> x;) {
        temps.push_back(x);
    }
    double sum = 0;
    double hi = std::numeric_limits<double>::min();
    double lo = std::numeric_limits<double>::max();
    for(auto temp : temps) {
        if(temp>hi) {
            hi = temp;
        }
        if(temp<lo) {
            lo = temp;
        }
        sum += temp;
    }
    std::cout << "High temperature: " << hi << std::endl;
    std::cout << "Low temperature: " << lo << std::endl;
    std::cout << "Average temperature: " << sum/temps.size() << std::endl;
    return 0;
}
