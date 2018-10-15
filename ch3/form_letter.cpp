#include "../std_lib_facilities.h"

int main()
{
    std::cout << "Enter the name of the person you want to write to:\n";
    std::string first_name;
    std::cin >> first_name;
    std::cout << "Enter the name of a friend:\n";
    std::string friend_name;
    std::cin >> friend_name;
    std:: cout << "Enter the sex ('m' or 'f') of the friend:\n";
    char friend_sex = 0;
    std::cin >> friend_sex;
    std::string sex_string;
    if (friend_sex == 'm') {
        sex_string = "him";
    }
    else if (friend_sex == 'f') {
        sex_string = "her";
    }
    else {
        sex_string = "it";
    }
    std:: cout << "Enter the age (in years) of the friend:\n";
    int friend_age = 0;
    std::cin >> friend_age;
    if (friend_age < 1 || friend_age > 109) {
        simple_error("you're kidding!");
    }

    std::cout << "\nDear " << first_name << ",\n";
    std::cout << "\tHow are you? I am fine.\n";
    std::cout << "I am writing a lot of code. It's fun!\n";
    std::cout << "Have you seen " << friend_name << " lately? I have not.\n";
    std::cout << "If you see " << friend_name << " please ask " << sex_string << " to call me.\n";
    std::cout << "I hear you just had a birthday and are " << friend_age << " years old!\n";
    if (friend_age < 12) {
        std::cout << "Next year you will be " << friend_age+1 << ".\n";
    }
    else if (friend_age == 17) {
        std::cout << "Next year you will be able to vote.\n";
    }
    else if (friend_age > 70) {
        std::cout << "I hope you are enjoying retirement.\n";
    }
    std::cout << "Yours sincerely,\n\n\n";
    std::cout << "Rich\n";

    return 0;
}
