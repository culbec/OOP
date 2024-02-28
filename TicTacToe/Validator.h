//
// Created by profi on 6/18/2023.
//

#ifndef TICTACTOE_VALIDATOR_H
#define TICTACTOE_VALIDATOR_H

#include "Game.h"
#include <string>

class Validator {
public:
    static string validateAdd(int dim, const string &sequence, const string &player);

    static string validateModif(int dim, const string &sequence, const string &player, const string &stare);
};


#endif //TICTACTOE_VALIDATOR_H
