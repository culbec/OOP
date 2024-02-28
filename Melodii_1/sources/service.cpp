//
// Created by culbec on 16.06.2023.
//

#include "../headers/service.h"

Service::Service(Repository &repo): repository{repo} {}

vector<Melodie>& Service::getMelodii() {
    return this->repository.getMelodii();
}

map<int, int>& Service::getRanks() {
    return this->repository.getRanks();
}

void Service::updateRank(const int& _id, const int &_rank) {
    auto& melodie = this->repository.find(_id);
    this->repository.updateRank(melodie, _rank);
}

void Service::sterge(const int &id) {
    auto melodie = this->repository.find(id);
    this->repository.sterge(id);
}

void Service::sortMelodii() {
    sort(this->repository.getMelodii().begin(), this->repository.getMelodii().end(), [](const Melodie& mel1, const Melodie& mel2){
        return mel1.getRank() < mel2.getRank();
    });
}