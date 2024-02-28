//
// Created by culbec on 17.06.2023.
//

#include "Service.h"


Service::Service(Repository &_repository) : repository{_repository} {}

vector<Tractor> &Service::getTractoare() {
    return this->repository.getTractoare();
}

unordered_map<string, int> &Service::getTipuri() {
    return this->repository.getTipuri();
}

string Service::validate(const Tractor &tractor) {
    string errors;
    for (const auto &_tractor: this->repository.getTractoare()) {
        if (_tractor.getId() == tractor.getId()) {
            errors += "Exista deja un tractor cu acest ID!\n";
            break;
        }
    }

    if (tractor.getDenumire().empty()) {
        errors += "Denumirea nu poate fi vida!\n";
    }

    if (tractor.getTip().empty()) {
        errors += "Tipul nu poate fi vid!\n";
    }

    if (tractor.getNumarRoti() % 2) {
        errors += "Numarul de roti trebuie sa fie un numar par!\n";
    }

    if (tractor.getNumarRoti() < 2 || tractor.getNumarRoti() > 16) {
        errors += "Numarul de roti trebuie sa fie intre 2 si 16!\n";
    }

    return errors;
}

void Service::add(int _id, const std::string &_denumire, const std::string &_tip, int _numarRoti) {
    Tractor tractor{_id, _denumire, _tip, _numarRoti};

    string errors = this->validate(tractor);

    if (errors.empty()) {
        this->repository.add(tractor);
        return;
    }

    throw runtime_error(errors);
}

void Service::update(int _id, int _numarRoti) {
    this->repository.update(_id, _numarRoti);
}

void Service::sortTractoare() {
    sort(this->repository.getTractoare().begin(), this->repository.getTractoare().end(),
         [](const Tractor &t1, const Tractor &t2) {
             return t1.getDenumire() < t2.getDenumire();
         });
}