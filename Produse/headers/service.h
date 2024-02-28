#pragma once

#include "repo.h"
#include <unordered_map>

using std::unordered_map;

class Service {
private:
    Repository& repository; // repo-ul dependent
    unordered_map<string, int> tipuri; // pereche Tip + Numar de produse cu acelasi tip

public:
    /*
     * Construieste un service
     * @param: repo -> Repository
     */
    Service(Repository& repo);

    /*
     * Se returneaza lista de produse a service-ului
     * @return: lista de produse a service-ului
     */
    vector<Produs>& getProduse();

    /*
     * Se returneaza perechile de <Tip, Numar de produse cu acelasi Tip>
     */
    unordered_map<string, int>& getTipuri();

    /*
     * Se valideaza un produs
     * @param: produs -> Produs
     * @return: string -> erorile intalnite pe parcursul validarii
     * @details: - produsul sa nu aiba acelasi id cu un alt produs din lista;
     *           - produsul sa nu aiba numele gol;
     *           - produsul sa aiba pretul intre 1.0 si 100.0
     */
    string validate(const Produs& produs);

    /*
     * Adauga un produs in lista de produse
     * @pre: parametrii valizi
     * @post: se adauga produsul in lista
     * @exceptions: - runtime_error: produsul nu este unul valid
     */
    void add(int _id, const string& _nume, const string& _tip, double _pret);

    /*
     * Filtreaza lista de produse cu produsele care au pretul mai mic decat pretul primit ca parametru
     * @param: _pret -> double
     * @return: lista de produse cu pretul mai mic decat _pret
     */
    vector<Produs> filter(double _pret);

    /*
     * Actualizeaza numarul de produse cu acelasi tip al produsului cu tipul _tip
     */
    void updateTipuri(const string& _tip);
};