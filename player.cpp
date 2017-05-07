//
// Created by Daniel Elsner on 26.03.17.
//

#include "player.h"
#include <iostream>

using namespace std;

const std::string &Player::getName_() const {
    return name_;
}

void Player::request_name() {
    std::string input_var = "";

    cout << "Spielername: ";
    while (true) {
        if (!(cin >> input_var)) {
            cout << "Bitte einen gültigen Namen eingeben: ";
            input_var = "";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        break;
    }

    name_ = input_var;
}
