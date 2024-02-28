//
// Created by culbec on 17.06.2023.
//

#ifndef TRACTOARE_SERVICE_H
#define TRACTOARE_SERVICE_H

#include "Repository.h"
#include <algorithm>

using std::sort;

class Service {
private:
    Repository& repository;
public:
    Service(Repository& _repository);

    vector<Tractor>& getTractoare();

    unordered_map<string, int>& getTipuri();

    string validate(const Tractor& tractor);

    void add(int _id, const string& _denumire, const string& _tip, int _numarRoti);

    void update(int _id, int _numarRoti);

    void sortTractoare();
};


#endif //TRACTOARE_SERVICE_H
