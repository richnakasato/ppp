#include <iostream>
#include <set>
#include <map>

struct InputHandler {
    const std::set<std::string> shortcuts = {"r", "p", "s", "l", "k"};
    const std::set<std::string> fullname = {"rock", "paper", "scissors", "lizard", "spock"};

    bool valid_input(const std::string& input) {
        auto found_shortcut = shortcuts.find(input) != shortcuts.end();
        auto found_fullname = fullname.find(input) != fullname.end();
        return found_shortcut || found_fullname;
    }
};

struct Hand {
    std::string name;
    std::set<std::string> defeats;
    std::map<std::string, std::string> methods;

    Hand(std::string name,
         std::set<std::string> defeats,
         std::map<std::string, std::string> methods) :
        name(name),
        defeats(defeats),
        methods(methods) {};

    bool is_defeats(const Hand& opponent_hand) {
        return defeats.find(opponent_hand.name) != defeats.end();
    }

    std::string defeat_method(const Hand& opponent_hand) {
        if (is_defeats(opponent_hand)) {
            return name + " " + methods[opponent_hand.name] + " " + opponent_hand.name;
        }
        else {
            return name + " does not defeat " + opponent_hand.name;
        }
    }
};

struct Rock : public Hand {
    Rock() : Hand(
            "Rock",
            {"Scissors", "Lizard"},
            {std::make_pair("Scissors", "crushes"),
            std::make_pair("Lizard", "crushes")}) {};
};

struct Paper : public Hand {
    Paper() : Hand(
            "Paper",
            {"Rock", "Spock"},
            {std::make_pair("Rock", "covers"),
            std::make_pair("Spock", "disproves")}) {};
};

struct Scissors : public Hand {
    Scissors() : Hand(
            "Scissors",
            {"Paper", "Lizard"},
            {std::make_pair("Paper", "cuts"),
            std::make_pair("Lizard", "decapitates")}) {};
};

struct Lizard : public Hand {
    Lizard() : Hand(
            "Lizard",
            {"Paper", "Spock"},
            {std::make_pair("Paper", "eats"),
            std::make_pair("Spock", "poisons")}) {};
};

struct Spock : public Hand {
    Spock() : Hand(
            "Spock",
            {"Rock", "Scissors"},
            {std::make_pair("Rock", "vaporizes"),
            std::make_pair("Scissors", "smashes")}) {};
};

struct GameHandler {
};

int main() {
    InputHandler ih = {};
    for (std::string user_input; std::cin >> user_input;) {
        std::cout << "user selected: " << user_input << std::endl;
        if (ih.valid_input(user_input)) {
            std::cout << "valid input!" << std::endl;
            if (user_input == "r") {
                Rock r = {};
                Lizard l = {};
                auto results = r.defeat_method(l);
                std::cout << results << std::endl;
            }
        }
        else {
            std::cout << "don't know this selection!" << std::endl;
        }
    }
    return 0;
}
