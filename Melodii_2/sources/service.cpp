//
// Created by culbec on 17.06.2023.
//

#include "../headers/service.h"

Service::Service(Repository &repo) : repository{repo} {
    if(this->repository.getMelodii().empty()) {
        this->currentId = 1;
    } else {
        this->currentId = (this->getMelodii().end() - 1)->getId();
    }
}

vector<Melodie> &Service::getMelodii() {
    return this->repository.getMelodii();
}

unordered_map<string, int> &Service::getArtisti() {
    return this->repository.getArtisti();
}

unordered_map<string, int> &Service::getGenuri() {
    return this->repository.getGenuri();
}

void Service::add(const std::string &_titlu, const std::string &_artist, const std::string &_gen) {
    Melodie melodie{++this->currentId, _titlu, _artist, _gen};
    this->repository.add(melodie);
    this->sortMelodii();
}

void Service::sterge(const Melodie &melodie) {
    this->repository.sterge(melodie.getId());
    this->sortMelodii();
}

void Service::sortMelodii() {
    auto &melodii = this->repository.getMelodii();
    sort(melodii.begin(), melodii.end(), [](const Melodie &mel1, const Melodie &mel2) {
        return mel1.getArtist() < mel2.getArtist();
    });
}

