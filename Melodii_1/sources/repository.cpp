//
// Created by culbec on 16.06.2023.
//

#include "../headers/repository.h"

Repository::Repository(std::string _fileName) : fileName{std::move(_fileName)} {
    this->loadFromFile();
}

void Repository::loadFromFile() {
    ifstream fin(this->fileName);

    if (!fin.is_open()) {
        throw runtime_error("Fisierul nu poate fi deschis pentru citire!\n");
    }

    while (!fin.eof()) {
        string _id;

        getline(fin, _id, ',');

        if (fin.eof()) {
            break;
        }

        string _titlu, _artist, _rank;

        getline(fin, _titlu, ',');
        getline(fin, _artist, ',');
        getline(fin, _rank, '\n');

        this->melodii.emplace_back(stoi(_id), _titlu, _artist, stoi(_rank));
        this->ranks[stoi(_rank)]++;
    }

    fin.close();
}

void Repository::writeToFile() {
    ofstream fout(this->fileName);

    if (!fout.is_open()) {
        throw runtime_error("Fisierul nu a putut fi deschis pentru scriere!");
    }

    for(const auto& melodie: this->melodii) {
        fout << melodie.getId() << "," << melodie.getTitlu() << "," << melodie.getArtist() << ","
             << melodie.getRank()
             << "\n";
    }

    fout.close();
}

vector<Melodie> &Repository::getMelodii() {
    return this->melodii;
}

map<int, int>& Repository::getRanks() {
    return this->ranks;
}

void Repository::add(const Melodie &_melodie) {
    this->melodii.push_back(_melodie);
    this->ranks[_melodie.getRank()]++;
    this->writeToFile();
}

void Repository::sterge(const int & _id) {
    auto foundPos = find_if(this->melodii.begin(), this->melodii.end(), [_id](const Melodie& mel){
        return mel.getId() == _id;
    });

    if(foundPos != this->melodii.end()) {
        this->melodii.erase(foundPos);
        this->ranks[foundPos->getRank()]--;
        this->writeToFile();
    }
}

Melodie &Repository::find(const int &_id) {
    auto found = find_if(this->melodii.begin(), this->melodii.end(), [_id](const Melodie& mel){
        return mel.getId() == _id;
    });

    if(found != this->melodii.end()) {
        return *found;
    }

    throw runtime_error("Melodia cu id-ul specificat nu exista!");
}

void Repository::updateRank(Melodie &melodie, const int& rank) {
    this->ranks[melodie.getRank()]--;
    this->ranks[rank]++;

    melodie.setRank(rank);
    this->writeToFile();
}