#pragma once

#include <string>
#include <cstring>

using std::string;

#define VOWELS "AEIOUaeiou"

class Produs {
private:
    int id;
    string nume, tip;
    double pret;

public:
    /*
     * Initializeaza un produs
     * @param: i -> int(id)
     * @param: n -> string(nume)
     * @param: t -> string(tip);
     * @param: p -> double(pret)
     */
    Produs(int i, const string& n, const string& t, double p);

    /*
     * Returneaza id-ul unui produs
     * @return: id of this
     */
    int getId() const;

    /*
     * Returneaza numele unui produs
     * @return nume of this
     */
    const string& getNume() const;

    /*
     * Returneaza tipul unui produs
     * @return: tip of this
     */
    const string& getTip() const;

    /*
     * Returneaza pretul unui produs
     * @return: pret of this
     */
    double getPret() const;

    /*
     * Returneaza numarul de vocale continut de numele unui produs
     * @return: numarul de vocale al this->nume
     */
    int getVowels() const;
};