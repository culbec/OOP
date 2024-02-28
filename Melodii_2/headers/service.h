//
// Created by culbec on 17.06.2023.
//

#ifndef MELODII_2_SERVICE_H
#define MELODII_2_SERVICE_H

#include "repo.h"

using std::sort;

class Service {
private:
    int currentId;
    Repository& repository;

public:
    Service(Repository& repo);

    vector<Melodie>& getMelodii();

    unordered_map<string, int>& getArtisti();

    unordered_map<string, int>& getGenuri();

    void add(const string& _titlu, const string& _artist, const string& _gen);

    void sterge(const Melodie& melodie);

    void sortMelodii();
};

#endif //MELODII_2_SERVICE_H
