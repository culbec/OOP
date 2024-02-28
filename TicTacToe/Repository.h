//
// Created by profi on 6/18/2023.
//

#ifndef TICTACTOE_REPOSITORY_H
#define TICTACTOE_REPOSITORY_H

#include "Game.h"
#include <fstream>
#include <exception>
#include <cstring>
#include <algorithm>

using std::stoi;
using std::getline;
using std::ifstream;
using std::ofstream;
using std::runtime_error;
using std::find_if;

class Repository {
private:
    string file;
    vector<Game> games;

    void loadFromFile();

    void writeToFile();

public:
    Repository(const string &_file);

    vector<Game> &getGames();

    void add(const Game &game);

    Game &find(const int &id);

    void modify(Game &game, int dim, const string &sequence, const string &player, const string &stare);
};


#endif //TICTACTOE_REPOSITORY_H
