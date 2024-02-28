#pragma once

#include "produs.h"
#include <vector>
#include <fstream>
#include <exception>

using std::vector;
using std::ifstream;
using std::ofstream;
using std::runtime_error;
using std::getline;

class Repository {
private:
    string fileName; // numele fisierului
    vector<Produs> produse;

    /*
     * Functie de incarcare a datelor din fisier
     * @pre: fisierul cu numele fileName sa existe pe disc
     * @post: se incarca datele din fisierul cu numele fileName
     * @exceptions: - runtime_error: fisierul nu exista pe disc
     */
    void loadFromFile();

    /*
     * Functie de scriere a datelor in fisier
     * @pre: fisierul cu numele fileName sa existe pe disc
     * @post: se scriu datele in fisierul cu numele fileName
     * @exceptions: - runtime_error: fisierul nu exista pe disc
     */
    void writeToFile();

public:
    /*
     * Construieste un repository
     * @param: file -> string(fileName)
     */
    Repository(const string& file);

    /*
     * Returneaza lista de produse al repository-ului
     * @return: lista de produse repository-ului
     */
    vector<Produs>& getProduse();

    /*
     * Returneaza adevarat sau fals, daca se gaseste un produs cu id-ul specificat in lista
     * @param: _id -> id-ul produsului de cautat
     * @return: - true -> produsul exista
     *          - false -> produsul nu exista
     */
    bool search(int _id) const;

    /*
     * Adauga un produs in lista de produse
     * @param: produs -> Produs
     * @post: se adauga produsul in lista de produse
     */
    void add(const Produs& produs);

};