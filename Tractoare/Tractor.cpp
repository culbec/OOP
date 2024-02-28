//
// Created by culbec on 17.06.2023.
//

#include "Tractor.h"

Tractor::Tractor(int _id, std::string _denumire, std::string _tip, int _numarRoti) : id{_id}, denumire{std::move(_denumire)},
                                                                                    tip{std::move(_tip)}, numarRoti{_numarRoti} {}

int Tractor::getId() const {
    return this->id;
}

const string& Tractor::getDenumire() const {
    return this->denumire;
}

const string& Tractor::getTip() const {
    return this->tip;
}

int Tractor::getNumarRoti() const {
    return this->numarRoti;
}

void Tractor::setNumarRoti(int _numarRoti) {
    this->numarRoti = _numarRoti;
}