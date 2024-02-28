#include "../headers/repo.h"

Repository::Repository(const std::string &file): fileName{file} {
    this->loadFromFile();
}

void Repository::loadFromFile() {
    ifstream fin(this->fileName);

    if(!fin.is_open()) {
        throw runtime_error("Fisierul nu a putut fi deschis pentru citire\n");
    }

    while(!fin.eof()) {
        string _id;
        getline(fin, _id, ',');

        if(fin.eof()) {
            break;
        }

        string _nume, _tip, _pret;
        getline(fin, _nume, ',');
        getline(fin, _tip, ',');
        getline(fin, _pret, '\n');

        this->produse.emplace_back(std::stoi(_id), _nume, _tip, std::stod(_pret));
    }

    fin.close();
}

void Repository::writeToFile() {
    ofstream fout(this->fileName);

    if(!fout.is_open()) {
        throw runtime_error("Fisierul nu a putut fi deschis pentru scriere!\n");
    }

    for(const auto& produs: this->produse) {
        fout << produs.getId() << "," << produs.getNume() << "," << produs.getTip() << "," << produs.getPret() << "\n";
    }

    fout.close();
}

bool Repository::search(int _id) const {
    for(const auto& produs: this->produse) {
        if(produs.getId() == _id) {
            return true;
        }
    }
    return false;
}

vector<Produs>& Repository::getProduse() {
    return this->produse;
}

void Repository::add(const Produs &produs) {
    this->produse.push_back(produs);
    this->writeToFile();
}