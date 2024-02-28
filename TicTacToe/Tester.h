//
// Created by profi on 6/18/2023.
//

#ifndef TICTACTOE_TESTER_H
#define TICTACTOE_TESTER_H

#include <cassert>
#include "Game.h"
#include "Repository.h"
#include "Validator.h"
#include "Service.h"

class Tester {
public:
    static void testGame();

    static void testRepo();

    static void testValidator();

    static void testService();

    static void testAll();
};


#endif //TICTACTOE_TESTER_H
