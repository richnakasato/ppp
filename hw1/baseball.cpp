#include <iostream>
#include <string>
#include <vector>

struct Player {
    std::string first_name, last_name;

    Player(std::string fn, std::string ln) : first_name(fn), last_name(ln) {}
    Player() : Player("", "") {}

    virtual void populate(void);
    virtual void display(void);
};

void Player::populate(void) {
    std::cout << "Who is this player? ";
    std::cin >> first_name >> last_name;
}

void Player::display(void) {
    std::cout << "Player:\t\t" << last_name << ", " << first_name << std::endl;
}


struct BaseballPlayer : public Player {
    std::string position;

    BaseballPlayer(std::string fn, std::string ln, std::string pos)
        : Player(fn, ln), position(pos) {}
    BaseballPlayer() : BaseballPlayer("", "", "") {}

    virtual void populate(void);
    virtual void display(void);
};

void BaseballPlayer::populate(void) {
    std::cout << "Who is the " << position << "? ";
    std::cin >> first_name >> last_name;
}

void BaseballPlayer::display(void) {
    std::cout << position << ":\t" << last_name << ", " << first_name << std::endl;
}


struct BaseballTeam {
    std::string positions[9] { "Pitcher",
                               "Catcher",
                               "First Base",
                               "Second Base",
                               "Shortstop",
                               "Third Base",
                               "Right Field",
                               "Center Field",
                               "Left Field" };
    std::vector<BaseballPlayer> players;
    BaseballTeam() {  }

    void populate_team(void);
    void display_team(void);
};

void BaseballTeam::populate_team(void) {
    for(auto pos : positions) {
        BaseballPlayer new_player {"", "", pos};
        new_player.populate();
        players.push_back(new_player);
    }
}

void BaseballTeam::display_team(void) {
    for(auto player : players) {
        player.display();
    }
}


int main()
{
    BaseballTeam new_team;
    new_team.populate_team();
    new_team.display_team();
    return 0;
}
