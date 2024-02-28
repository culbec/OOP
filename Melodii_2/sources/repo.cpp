//
// Created by culbec on 17.06.2023.
//

#include "../headers/repo.h"


Repository::Repository(std::string _file): file{std::move(_file)} {
    this->loadFromFile();
}

void Repository::loadFromFile() {
    ifstream fin(this->file);

    if(!fin.is_open()) {
        throw runtime_error("Fisierul nu a putut fi deschis pentru citire!\n");
    }

    while(!fin.eof()) {
        string _id;

        getline(fin, _id, ',');

        if(fin.eof()) {
            break;
        }

        string _titlu, _artist, _gen;

        getline(fin, _titlu, ',');
        getline(fin, _artist, ',');
        getline(fin, _gen, '\n');

        this->melodii.emplace_back(stoi(_id), _titlu, _artist, _gen);
        this->artisti[_artist]++;
        this->genuri[_gen]++;
    }

    fin.close();
}

void Repository::writeToFile() {
    ofstream fout(this->file);

    for(const auto& melodie: this->melodii) {
        fout << melodie.getId() << "," << melodie.getTitlu() << "," << melodie.getArtist() << "," << melodie.getGen() << "\n";
    }

    fout.close();
}

vector<Melodie>& Repository::getMelodii() {
    return this->melodii;
}

unordered_map<string, int>& Repository::getArtisti() {
    return this->artisti;
}

unordered_map<string, int>& Repository::getGenuri() {
    return this->genuri;
}

void Repository::add(const Melodie &melodie) {
    this->melodii.push_back(melodie);
    this->artisti[melodie.getArtist()]++;
    this->genuri[melodie.getGen()]++;
    this->writeToFile();
}

void Repository::sterge(const int &_id) {
    auto found = find_if(this->melodii.begin(), this->melodii.end(), [_id](const Melodie& mel){
        return _id == mel.getId();
    });

    if(found != this->melodii.end()) {
        this->melodii.erase(found);
        this->artisti[found->getArtist()]--;
        this->genuri[found->getGen()]--;
        this->writeToFile();
    }
}