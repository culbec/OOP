//
// Created by culbec on 16.06.2023.
//

#include "../headers/melodie.h"

Melodie::Melodie(int i, std::string t, std::string a, int r) : id{i}, titlu{std::move(t)}, artist{std::move(a)},
                                                               rank{r} {}

int Melodie::getId() const {
    return this->id;
}

const string& Melodie::getTitlu() const {
    return this->titlu;
}

const string& Melodie::getArtist() const {
    return this->artist;
}

int Melodie::getRank() const {
    return this->rank;
}

void Melodie::setRank(int r) {
    this->rank = r;
}