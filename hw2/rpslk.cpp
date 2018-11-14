#include <iostream>
#include <set>
#include <map>

enum HandType {unknown, rock, paper, scissors, lizard, spock};

struct InputHandler {
    const std::set<std::string> shortnames = {"r", "p", "s", "l", "k"};
    const std::set<std::string> longnames = {"rock", "paper", "scissors", "lizard", "spock"};

    bool is_valid_input(const std::string& input) {
        auto found_short = shortnames.find(input) != shortnames.end();
        auto found_long = longnames.find(input) != longnames.end();
        return found_short || found_long;
    }

    HandType get_hand_type(const std::string& input) {
        if (is_valid_input(input)) {
            if (input == "r" || input == "rock") return rock;
            else if (input == "p" || input == "paper") return paper;
            else if (input == "s" || input == "scissors") return scissors;
            else if (input == "l" || input == "lizard") return lizard;
            else if (input == "k" || input == "spock") return spock;
        }
        return unknown;
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

    Hand() : Hand(
            "unknown",
            {"unknown"},
            {std::make_pair("unknown", "beats")}) {};

    bool is_defeats(const Hand& opponent_hand) {
        return defeats.find(opponent_hand.name) != defeats.end();
    }

    bool is_tie(const Hand& opponent_hand) {
        return name == opponent_hand.name;
    }

    std::string defeat_method(const Hand& opponent_hand) {
        if (is_defeats(opponent_hand)) {
            return name + " " + methods[opponent_hand.name] + " " + opponent_hand.name;
        }
        else if (is_tie(opponent_hand)) {
            return name + " ties with " + opponent_hand.name;
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

struct HandFactory {
    Hand get_hand_from_type(HandType hand) {
        switch (hand) {
            case rock:
            {
                return Rock();
                break;
            }
            case paper:
            {
                return Paper();
                break;
            }
            case scissors:
            {
                return Scissors();
                break;
            }
            case lizard:
            {
                return Lizard();
                break;
            }
            case spock:
            {
                return Spock();
                break;
            }
            default:
            {
                return Hand();
                break;
            }
        }
    }
};

struct ComputerPlayer {
    constexpr int computer_array_length = 10;
    const HandType computer_array[computer_array_length] = {rock,
                                                            paper,
                                                            lizard,
                                                            paper,
                                                            spock,
                                                            scissors,
                                                            lizard,
                                                            spock,
                                                            rock,
                                                            scissors};
    int count;
    ComputerPlayer() : count(0) {};

};

struct GameHandler {
};

int main() {
    constexpr int computer_array_length = 10;
    HandType computer_array[computer_array_length] = {rock,
                                                      paper,
                                                      lizard,
                                                      paper,
                                                      spock,
                                                      scissors,
                                                      lizard,
                                                      spock,
                                                      rock,
                                                      scissors};
    int computer_count = 0;
    InputHandler ih = {};
    HandFactory hf = {};
    for (std::string user_input; std::cin >> user_input;) {
        std::cout << "user selected: " << user_input << std::endl;
        auto ht = ih.get_hand_type(user_input);
        auto player_hand = hf.get_hand_from_type(ht);
        ht = computer_array[computer_count++%computer_array_length];
        auto computer_hand = hf.get_hand_from_type(ht);
        if (player_hand.is_defeats(computer_hand)) {
            std::cout << player_hand.defeat_method(computer_hand) << std::endl;
        }
        else {
            std::cout << computer_hand.defeat_method(player_hand) << std::endl;
        }
    }
    return 0;
}
