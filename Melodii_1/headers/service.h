//
// Created by culbec on 16.06.2023.
//

#ifndef MELODII_1_SERVICE_H
#define MELODII_1_SERVICE_H

#include "repository.h"
#include <algorithm>

using std::sort;

class Service {
private:
    Repository& repository;

public:
    Service(Repository& repo);

    vector<Melodie>& getMelodii();

    map<int, int>& getRanks();

    void updateRank(const int& _id, const int& _rank);

    void sterge(const int& id);

    void sortMelodii();
};

#endif //MELODII_1_SERVICE_H
