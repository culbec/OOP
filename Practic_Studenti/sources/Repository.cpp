//
// Created by culbec on 19.06.2023.
//

#include "../headers/Repository.h"

Repository::Repository(const std::string &_file) : file{_file} {
    this->loadFromFile();
}

void Repository::loadFromFile() {
    ifstream fin(this->file);

    if (!fin.is_open()) {
        throw runtime_error("Fisierul nu a putut fi deschis pentru citire!\n");
    }

    while (!fin.eof()) {
        string _nrMatricol;

        getline(fin, _nrMatricol, ',');

        if (fin.eof()) {
            break;
        }

        string _nume, _varsta, _facultate;

        getline(fin, _nume, ',');
        getline(fin, _varsta, ',');
        getline(fin, _facultate, '\n');

        this->studenti.emplace_back(stoi(_nrMatricol), _nume, stoi(_varsta), _facultate);
    }

    fin.close();
}

void Repository::writeToFile() {
    ofstream fout(this->file, std::ios::trunc);

    for (const auto &student: this->studenti) {
        fout << student.getNrMatricol() << "," << student.getNume() << "," << student.getVarsta() << ","
             << student.getFacultate() << "\n";
    }

    fout.close();
}

vector<Student>& Repository::getStudenti() {
    return this->studenti;
}

void Repository::add(const Student &_student) {
    this->studenti.push_back(_student);
    this->writeToFile();
}

Student &Repository::find(int _id) {
    auto found = find_if(this->studenti.begin(), this->studenti.end(), [_id](const Student &student) {
        return student.getNrMatricol() == _id;
    });

    if (found != this->studenti.end()) {
        return *found;
    }

    throw runtime_error("Nu exista studentul cu respectivul id!\n");
}

void Repository::modify(int _id, int _newVarsta) {
    auto found = find_if(this->studenti.begin(), this->studenti.end(), [_id](const Student &student) {
        return student.getNrMatricol() == _id;
    });

    if (found != this->studenti.end()) {
        found->setVarsta(_newVarsta);
        this->writeToFile();
        return;
    }

    throw runtime_error("Nu exista studentul cu respectivul id!\n");
}

void Repository::remove(int _id) {
    auto found = find_if(this->studenti.begin(), this->studenti.end(), [_id](const Student &student) {
        return student.getNrMatricol() == _id;
    });

    if (found != this->studenti.end()) {
        this->studenti.erase(found);
        this->writeToFile();
        return;
    }

    throw runtime_error("Nu exista studentul cu respectivul id!\n");
}
