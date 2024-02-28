//
// Created by profi on 6/18/2023.
//

#ifndef TICTACTOE_SERVICE_H
#define TICTACTOE_SERVICE_H

#include "Repository.h"
#include "Validator.h"


using std::sort;

class Service {
private:
    int currentId = 1;
    Repository &repository;
public:
    Service(Repository &repo);

    vector<Game> &getGames();

    void add(int dim, const string &sequence, const string &player);

    void modify(int id, int dim, const string &sequence, const string &player, const string &stare);

    void sortGames();

    bool checkEnded(Game &game);

};


#endif //TICTACTOE_SERVICE_H
