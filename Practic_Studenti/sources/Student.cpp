//
// Created by culbec on 19.06.2023.
//

#include "../headers/Student.h"

Student::Student(int _nrMatricol, const std::string &_nume, int _varsta, const std::string &_facultate) : nrMatricol{
        _nrMatricol}, nume{_nume}, varsta{_varsta}, facultate{_facultate} {}

const string &Student::getNume() const {
    return this->nume;
}

int Student::getVarsta() const {
    return this->varsta;
}

void Student::setVarsta(int _varsta) {
    this->varsta = _varsta;
}

int Student::getNrMatricol() const {
    return this->nrMatricol;
}

const string &Student::getFacultate() const {
    return this->facultate;
}