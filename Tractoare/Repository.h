//
// Created by culbec on 17.06.2023.
//

#ifndef TRACTOARE_REPOSITORY_H
#define TRACTOARE_REPOSITORY_H

#include <fstream>
#include <vector>
#include <unordered_map>
#include <exception>
#include "Tractor.h"

using std::ifstream;
using std::ofstream;
using std::vector;
using std::unordered_map;
using std::getline;
using std::stoi;
using std::runtime_error;

class Repository {
private:
    string file;
    vector<Tractor> tractoare;
    unordered_map<string, int> tipuri;

    void loadFromFile();
    void writeToFile();

public:
    explicit Repository(string _file);

    vector<Tractor>& getTractoare();

    unordered_map<string, int>& getTipuri();

    void add(const Tractor& tractor);

    void update(int _id, int _numarRoti);
};


#endif //TRACTOARE_REPOSITORY_H
