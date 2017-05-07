//
// Created by Daniel Elsner on 26.03.17.
//

#ifndef MASTERHIRN_GAME_H
#define MASTERHIRN_GAME_H


#include <vector>
#include "player.h"
#include "color.h"

const unsigned int MAX_GAME_LENGTH = 10;

class Game {
    std::vector<Player> players_;

    std::vector<Color> combination_;

    std::vector<std::vector<Color>> attempts_;

    void create_players_();

    Color request_();

    void request_combination_();

    bool request_solution_();

    bool check_last_solution_();

    void win_();

    void loose_();

public:
    // start new game
    void start();
};

#endif //MASTERHIRN_GAME_H
