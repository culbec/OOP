//
// Created by profi on 6/18/2023.
//

#include "Service.h"

Service::Service(Repository &repo) : repository{repo} {
    if (!this->repository.getGames().empty()) {
        this->currentId = this->repository.getGames().back().getId() + 1;
    }
}

vector<Game> &Service::getGames() {
    return this->repository.getGames();
}

void Service::add(int dim, const std::string &sequence, const std::string &player) {
    string errors = Validator::validateAdd(dim, sequence, player);

    if (errors.empty()) {
        Game game{currentId++, dim, sequence, player};
        this->repository.add(game);
        return;
    }

    throw runtime_error(errors);
}

void
Service::modify(int id, int dim, const std::string &sequence, const std::string &player, const std::string &stare) {
    string errors = Validator::validateModif(dim, sequence, player, stare);

    if (errors.empty()) {
        try {
            Game &game = this->repository.find(id);
            this->repository.modify(game, dim, sequence, player, stare);
            return;
        } catch (runtime_error &rE) {
            throw runtime_error(string{rE.what()});
        }
    }

    throw runtime_error(errors);
}

void Service::sortGames() {
    sort(this->getGames().begin(), this->getGames().end(), [](const Game &g1, const Game &g2) {
        return g1.getStatus() < g2.getStatus();
    });
}

bool Service::checkEnded(Game &game) {
    bool isEnded = true;

    // checking on lines
    for (auto i = 0; i < game.getTable().size(); i++) {
        isEnded = true;
        for (auto j = 0; j < game.getTable().size() - 1; j++) {
            if (game.getTable()[i][j] == 0 || game.getTable()[i][j] != game.getTable()[i][j + 1]) {
                isEnded = false;
                break;
            }
        }

        if (isEnded && game.getTable()[i][0] != 0) {
            return true;
        }
    }

    // checking on columns
    for (auto i = 0; i < game.getTable().size(); i++) {
        isEnded = true;
        for (auto j = 0; j < game.getTable().size() - 1; j++) {
            if (game.getTable()[j][i] == 0 || game.getTable()[j][i] != game.getTable()[j + 1][i]) {
                isEnded = false;
                break;
            }
        }
        if (isEnded && game.getTable()[0][i] != 0) {
            return true;
        }
    }

    // checking on primary diagonal
    isEnded = true;
    for (auto i = 0; i < game.getTable().size() - 1; i++) {
        if (game.getTable()[i][i] == 0 || game.getTable()[i][i] != game.getTable()[i + 1][i + 1]) {
            isEnded = false;
            break;
        }
    }
    if (isEnded && game.getTable()[0][0] != 0) {
        return true;
    }

    // checking on secondary diagonal
    isEnded = true;
    for (auto i = 0; i < game.getTable().size() - 1; i++) {
        if (game.getTable()[i][game.getTable().size() - i - 1] == 0 ||
            game.getTable()[i][game.getTable().size() - i - 1] !=
            game.getTable()[i + 1][game.getTable().size() - i - 2]) {
            isEnded = false;
            break;
        }
    }
    if (isEnded && game.getTable()[0][game.getTable().size() - 1] != 0) {
        return true;
    }

    return false;
}

