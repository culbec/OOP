//
// Created by culbec on 17.06.2023.
//

#include "../headers/melodie.h"

Melodie::Melodie(int _id, std::string _titlu, std::string _artist, std::string _gen) : id{_id},
                                                                                       titlu{std::move(_titlu)},
                                                                                       artist{std::move(_artist)},
                                                                                       gen{std::move(_gen)} {}

int Melodie::getId() const {
    return this->id;
}

const string& Melodie::getTitlu() const {
    return this->titlu;
}

const string& Melodie::getArtist() const {
    return this->artist;
}

const string& Melodie::getGen() const {
    return this->gen;
}

void Melodie::setId(const int &_id) {
    this->id = _id;
}