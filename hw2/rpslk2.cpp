#include<iostream>
#include<random>
#include<string>

int user_shoot(std::string user_input) {
    if (user_input == "r" || user_input == "rock") {
        return 0;
    } else if (user_input == "p" || user_input == "paper") {
        return 1;
    } else if (user_input == "s" || user_input == "scissors") {
        return 2;
    } else if (user_input == "l" || user_input == "lizard") {
        return 3;
    } else if (user_input == "k" || user_input == "spock") {
        return 4;
    }
    return -1;
}

int computer_shoot() {
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(0,4);
    return uniform_dist(e1);
}

std::string shoot_translator(int selection) {
    if (selection == 0) {
        return "Rock";
    } else if (selection == 1) {
        return "Paper";
    } else if (selection == 2) {
        return "Scissors";
    } else if (selection == 3) {
        return "Lizard";
    } else if (selection == 4) {
        return "Spock";
    }
    return "Unknown";
}

// TODO: need to handle ties
int game_decider(int user, int computer) {
    int return_val = 0;
    std::cout << shoot_translator(user);
    if (user == 0) {
        if (computer == 2 || computer == 3) {
            return_val = 1;
        }
    } else if (user == 1) {
        if (computer == 1 || computer == 4) {
            return_val = 1;
        }
    } else if (user == 2) {
        if (computer == 1 || computer == 3) {
            return_val = 1;
        }
    } else if (user == 3) {
        if (computer == 1 || computer == 4) {
            return_val = 1;
        }
    } else if (user == 4) {
        if (computer == 0 || computer == 2) {
            return_val = 1;
        }
    }
    if (return_val) {
        std::cout << " beats ";
    } else {
        std::cout << " loses to ";
    }
    std::cout << shoot_translator(computer) << std::endl;
    return return_val;
}

void score_board(int game_count, int user_score) {
    std::cout << "Current Score -> User:" << user_score << ", Computer:" << game_count - user_score << std::endl;
}

int main() {
    std::cout << "Playing Rock, Paper, Scissors, Lizard, Spock!" << std::endl;
    std::cout << "Enter and move or press CTRL-D to quit..." << std::endl;

    int game_count = 0;
    int user_score = 0;
    std::string user_input;
    while (std::cin >> user_input) {
        int user = user_shoot(user_input);
        if (user != -1) {
            int computer = computer_shoot();
            std::cout << "user: " << shoot_translator(user) << std::endl;
            std::cout << "computer: " << shoot_translator(computer) << std::endl;
            if (user != computer) {
                game_count += 1;
                user_score += game_decider(user, computer);
                score_board(game_count, user_score);
            }
            else {
                std::cout << "Tie! Try again!" << std::endl;
            }
        }
        else {
            std::cout << "please enter a valid selection!" << std::endl;
        }
    }
    return 0;
}
