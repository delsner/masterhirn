//
// Created by Daniel Elsner on 26.03.17.
//

#include "game.h"
#include <iostream>

using namespace std;

void Game::create_players_() {
    for (int p = 0; p < 2; p++) {
        Player player;
        player.request_name();
        players_.push_back(player);
    }
}

void Game::request_combination_() {
    cout << players_[0].getName_() << " please set a combination." << endl;
    for (int c = 0; c < 4; c++) {
        combination_.push_back(request_());
    }
}

Color Game::request_() {
    int input_var;

    cout << "Rot (0), Grün (1), Gelb (2), Blau (3), Schwarz (4), Weiß (5)" << endl;
    cout << "Welche Farbe (index): ";

    while (true) {
        if (!(cin >> input_var) || !(input_var <= 5 && input_var >= 0)) {
            cout << "Bitte eine Farbe wählen: ";
            input_var = -1;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        break;
    }

    return (Color) input_var;
}

bool Game::request_solution_() {
    cout << players_[1].getName_() << " please set a combination for your attempt." << endl;

    std::vector<Color> attempt;
    for (int c = 0; c < 4; c++) {
        attempt.push_back(request_());
    }
    attempts_.push_back(attempt);
    return check_last_solution_();
}

bool Game::check_last_solution_() {
    int amount_black = 0;
    int amount_white = 0;


    // check for white
    for (int c = 0; c < attempts_.back().size(); c++) {
        for (int p = 0; p < combination_.size(); p++) {
            if (attempts_.back()[c] == combination_[p]) {
                amount_white++;
            }
        }
    }

    // check for black
    for (int c = 0; c < attempts_.back().size(); c++) {
        if (attempts_.back()[c] == combination_[c]) {
            amount_white--;
            amount_black++;
        }
    }

    cout << "Your solution has " << amount_black << " completely correct and " << amount_white
         << " only colors correct."
         << endl;

    if (amount_black == combination_.size()) {
        return true;
    }

    return false;

}

void Game::win_() {
    cout << "Won in " << attempts_.size() << " attempts." << endl;
}

void Game::loose_() {
    cout << "You loose. " << endl;
}

void Game::start() {
    cout << "A new game Masterhirn has begun!" << endl;

    // create 2 players
    create_players_();

    // request color combination that is to be found from first player
    request_combination_();

    // while rounds played is less than max game length
    while (attempts_.size() < MAX_GAME_LENGTH) {

        // play round: request solution attempt from second player and check for validity
        if (request_solution_()) {
            break;
        }
    }

    if (attempts_.size() < MAX_GAME_LENGTH) {
        win_();
    } else {
        loose_();
    }

}
