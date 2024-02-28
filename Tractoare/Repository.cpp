//
// Created by culbec on 17.06.2023.
//

#include "Repository.h"

Repository::Repository(string _file) : file{std::move(_file)} {
    this->loadFromFile();
}

void Repository::loadFromFile() {
    ifstream fin(this->file);

    if (!fin.is_open()) {
        throw runtime_error("Fisierul nu a putut fi deschis pentru citire!\n");
    }

    while (!fin.eof()) {
        string _id;

        getline(fin, _id, ',');

        if (fin.eof()) {
            break;
        }

        string _denumire, _tip, _numarRoti;

        getline(fin, _denumire, ',');
        getline(fin, _tip, ',');
        getline(fin, _numarRoti, '\n');

        this->tractoare.emplace_back(stoi(_id), _denumire, _tip, stoi(_numarRoti));
        this->tipuri[_tip]++;
    }
    fin.close();
}

void Repository::writeToFile() {
    ofstream fout(this->file);

    for(const auto& tractor: this->tractoare) {
        fout << tractor.getId() << "," << tractor.getDenumire() << "," << tractor.getTip() << ","
             << tractor.getNumarRoti() << "\n";
    }

    fout.close();
}

vector<Tractor>& Repository::getTractoare() {
    return this->tractoare;
}

unordered_map<string, int>& Repository::getTipuri() {
    return this->tipuri;
}

void Repository::add(const Tractor &tractor) {
    this->tractoare.push_back(tractor);
    this->tipuri[tractor.getTip()]++;
    this->writeToFile();
}

void Repository::update(int _id, int _numarRoti) {
    for(auto& tractor: this->tractoare) {
        if(tractor.getId() == _id) {
            tractor.setNumarRoti(_numarRoti);
            this->writeToFile();
            break;
        }
    }
}