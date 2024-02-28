//
// Created by culbec on 16.06.2023.
//

#ifndef MELODII_1_REPOSITORY_H
#define MELODII_1_REPOSITORY_H

#include "melodie.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include <exception>
#include <map>

using std::vector;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::ios;
using std::to_string;
using std::stoi;
using std::runtime_error;
using std::find_if;
using std::map;

class Repository {
private:
    string fileName;
    vector<Melodie> melodii;
    map<int, int> ranks;

    void loadFromFile();
    void writeToFile();

public:
    Repository(string _fileName);

    vector<Melodie>& getMelodii();
    map<int, int>& getRanks();

    void add(const Melodie& _melodie);

    Melodie& find(const int& _id);

    void sterge(const int& _id);

    void updateRank(Melodie& melodie, const int& rank);

};

#endif //MELODII_1_REPOSITORY_H
