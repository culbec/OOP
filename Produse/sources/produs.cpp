#include "../headers/produs.h"

Produs::Produs(int i, const std::string &n, const std::string &t, double p): id{i}, nume{n}, tip{t}, pret{p} {}

int Produs::getId() const {
    return this->id;
}

const string& Produs::getNume() const {
    return this->nume;
}

const string& Produs::getTip() const {
    return this->tip;
}

double Produs::getPret() const {
    return this->pret;
}

int Produs::getVowels() const {
    int vowels = 0;

    for(const auto& ch: this->nume) {
        if(strchr(VOWELS, ch)) {
            vowels++;
        }
    }

    return vowels;
}