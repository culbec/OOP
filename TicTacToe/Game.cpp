//
// Created by profi on 6/18/2023.
//

#include "Game.h"

Game::Game(int _id, int _dim, const string &seq, const string &_player) : id{_id}, dim{_dim}, sequence{seq},
                                                                          player{_player}, status{"Neinceput"} {
    int contor = 0;
    this->table.resize(this->dim);
    for (auto &seq: this->table) {
        seq.resize(this->dim);
    }

    for (auto i = 0; i < this->dim; i++) {
        for (auto j = 0; j < this->dim; j++) {
            auto ch = this->sequence.at(contor++);
            if (ch == 'O') {
                this->table[i][j] = -1;
            } else if (ch == '-') {
                this->table[i][j] = 0;
            } else if (ch == 'X') {
                this->table[i][j] = 1;
            }
        }
    }
}

int Game::getId() const {
    return this->id;
}

int Game::getDim() const {
    return this->dim;
}

const string &Game::getSequence() const {
    return this->sequence;
}

const string &Game::getPlayer() const {
    return this->player;
}

const string &Game::getStatus() const {
    return this->status;
}

vector<vector<int>> &Game::getTable() {
    return this->table;
}

void Game::setDim(int _dim) {
    this->dim = _dim;

    this->table.clear();
    this->table.resize(this->dim);

    for (auto &seq: this->table) {
        seq.resize(this->dim);
    }
}

void Game::setStatus(const std::string &_status) {
    this->status = _status;
}

void Game::setSequence(const std::string &_sequence) {
    this->sequence = _sequence;
}

void Game::setPlayer(const std::string &_player) {
    this->player = _player;
}


