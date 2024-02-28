#include "../headers/service.h"

Service::Service(Repository &repo): repository{repo} {
    for(const auto& produs: repo.getProduse()) {
        this->updateTipuri(produs.getTip());
    }
}

vector<Produs>& Service::getProduse() {
    return this->repository.getProduse();
}

unordered_map<string, int>& Service::getTipuri() {
    return this->tipuri;
}

string Service::validate(const Produs &produs) {
    string errors;

    if(this->repository.search(produs.getId())) {
        errors += "Un produs cu acest id exista deja!\n";
    }

    if(produs.getNume().empty()) {
        errors += "Numele produsului nu poate fi vid!\n";
    }

    if(1.0 > produs.getPret() || produs.getPret() > 100.0) {
        errors += "Pretul produsului trebuie sa fie intre 1.0 si 100.0!\n";
    }

    return errors;
}

void Service::add(int _id, const std::string &_nume, const std::string &_tip, double _pret) {
    Produs produs{_id, _nume, _tip, _pret};

    string errors = this->validate(produs);
    if(!errors.empty()) {
        throw runtime_error(errors);
    }

    this->repository.add(produs);
    this->updateTipuri(produs.getTip());
}

vector<Produs> Service::filter(double _pret) {
    vector<Produs> filtered;

    for(const auto& produs: this->getProduse()) {
        if(produs.getPret() <= _pret) {
            filtered.push_back(produs);
        }
    }

    return filtered;
}

void Service::updateTipuri(const std::string &_tip) {
    this->tipuri[_tip]++;
}