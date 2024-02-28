//
// Created by culbec on 17.06.2023.
//

#ifndef MELODII_2_REPO_H
#define MELODII_2_REPO_H

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <fstream>

#include "melodie.h"

using std::vector;
using std::unordered_map;

using std::ofstream;
using std::ifstream;
using std::stoi;
using std::getline;
using std::ios;

using std::runtime_error;
using std::find_if;

class Repository {
private:
    string file;
    vector<Melodie> melodii;
    unordered_map<string, int> artisti;
    unordered_map<string, int> genuri;

    void loadFromFile();
    void writeToFile();

public:
    Repository(string _file);

    vector<Melodie>& getMelodii();

    unordered_map<string, int>& getArtisti();

    unordered_map<string, int>& getGenuri();

    void add(const Melodie& melodie);

    void sterge(const int& _id);
};

#endif //MELODII_2_REPO_H
