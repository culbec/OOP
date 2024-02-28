//
// Created by profi on 6/18/2023.
//

#include "Repository.h"

Repository::Repository(const std::string &_file) : file{_file} {
    this->loadFromFile();
}

void Repository::loadFromFile() {
    ifstream fin(this->file);

    if (!fin.is_open()) {
        throw runtime_error("Fisierul nu a putut fi deschis pentru citire!");
    }

    while (!fin.eof()) {
        string _id;

        getline(fin, _id, ',');

        if (fin.eof()) {
            break;
        }

        string _dim, _seq, _player, _status;

        getline(fin, _dim, ',');
        getline(fin, _seq, ',');
        getline(fin, _player, ',');
        getline(fin, _status, '\n');

        Game game{stoi(_id), stoi(_dim), _seq, _player};
        game.setSequence(_seq);
        game.setStatus(_status);

        int contor = 0;
        for (auto &seq: game.getTable()) {
            for (auto i = 0; i < seq.size(); i++) {
                auto ch = game.getSequence().at(contor++);
                if (ch == 'O') {
                    seq[i] = -1;
                } else if (ch == '-') {
                    seq[i] = 0;
                } else if (ch == 'X') {
                    seq[i] = 1;
                }
            }
        }

        this->games.push_back(game);
    }

    fin.close();
}

void Repository::writeToFile() {
    ofstream fout(this->file, std::ios::trunc);

    for (const auto &game: this->games) {
        fout << game.getId() << "," << game.getDim() << "," << game.getSequence() << "," << game.getPlayer() << ","
             << game.getStatus() << "\n";
    }

    fout.close();
}

vector<Game> &Repository::getGames() {
    return this->games;
}

void Repository::add(const Game &game) {
    this->games.push_back(game);
    this->writeToFile();
}

Game &Repository::find(const int &id) {
    auto found = find_if(this->games.begin(), this->games.end(), [id](const Game &game) {
        return game.getId() == id;
    });

    if (found != this->games.end()) {
        return *found;
    }

    throw runtime_error("Nu exista jocul cu acest id!\n");
}

void Repository::modify(Game &game, int dim, const std::string &sequence, const std::string &player,
                        const std::string &stare) {
    game.setDim(dim);
    game.setSequence(sequence);
    game.setPlayer(player);
    game.setStatus(stare);

    int contor = 0;
    for (auto i = 0; i < game.getDim(); i++) {
        for (auto j = 0; j < game.getDim(); j++) {
            auto ch = game.getSequence().at(contor++);
            if (ch == 'O') {
                game.getTable()[i][j] = -1;
            } else if (ch == '-') {
                game.getTable()[i][j] = 0;
            } else if (ch == 'X') {
                game.getTable()[i][j] = 1;
            }
        }
    }

    this->writeToFile();
}
