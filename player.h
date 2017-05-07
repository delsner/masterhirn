//
// Created by Daniel Elsner on 26.03.17.
//

#ifndef MASTERHIRN_PLAYER_H
#define MASTERHIRN_PLAYER_H

#include <iostream>

class Player {
    std::string name_;
public:
    void request_name();

    const std::string &getName_() const;
};


#endif //MASTERHIRN_PLAYER_H
