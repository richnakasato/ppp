#include <iostream>
#include <vector>

int main() {
    std::string dislike = {"dog"};
    std::string bleep = {"BLEEP"};
    std::vector<std::string> bleeped = {};
    for (std::string temp; std::cin>>temp;) {
        if (temp != dislike) {
            bleeped.push_back(temp);
        }
        else {
            bleeped.push_back(bleep);
        }
    }
    for (auto word : bleeped) {
        std::cout << word << std::endl;
    }
    return 0;
}
