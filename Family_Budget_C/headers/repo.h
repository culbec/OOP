//
// Created by culbec on 3/12/23.
//
#pragma once

#include "./domain.h"

typedef struct {
    unsigned int capacitate;
    unsigned int lungime;
    Cheltuiala** cheltuieli;
}ListaCheltuieli;

    /*
     * Creeaza un repo
     * @pre: -
     * @post: se creeaza repo-ul de lungime 0
     */
ListaCheltuieli* creeazaRepo(unsigned int, unsigned int);

    /*
     * Distruge repo-ul
     * @pre: ListaCheltuieli* refera un repo valid
     * @post: se distruge repo-ul
     */
void distrugeRepo(ListaCheltuieli*);

    /*
     * Redimensioneaza repo-ul
     * @pre: ListaCheltuieli* refera un repo valid
     * @post: repo-ul va fi extins
     */

void repoRedimensionare(ListaCheltuieli*);

    /*
     * Adauga cheltuiala lista de cheltuieli a repo-ului
     * @pre: ListaCheltuieli* refera un repo valid
     *       Cheltuiala este cheltuiala de adaugat
     * @post: cheltuiala este adaugata in lista de cheltuieli
     */

void repoAdaugareCheltuiala(ListaCheltuieli*, Cheltuiala*);

    /*
    * Modifica cheltuiala de pe o pozitie data
    * @pre: ListaCheltuieli* refera un repo valid
    *       int este pozitia cheltuielii de modificat
    *       Cheltuiala este cheltuiala ce va inlocui cheltuiala de modificat
    * @post: cheltuiala se va modifica
    */

void repoModificaCheltuiala(ListaCheltuieli*, int, Cheltuiala*);

    /*
     * Sterge cheltuiala de pe o pozitie data
     * @pre: ListaCheltuieli* refera un repo valid
     *       int este pozitia elementului de sters
     * @post: cheltuiala se va sterge
     */

void repoStergeCheltuiala(ListaCheltuieli*, int);

    /*
     * Cauta o cheltuiala in lista de cheltuieli
     * @pre: ListaCheltuieli* refera un repo valid
     *       Cheltuiala este cheltuiala pe care o cautam
     * @post: pozitia cheltuielii in lista
     */
int repoCautaCheltuiala(ListaCheltuieli*, Cheltuiala*);

    /*
     * Returneaza cheltuielile unui repo
     * @pre: ListaCheltuieli* refera un repo valid
     * @post: lista de cheltuieli a repo-ului
     */

Cheltuiala** getCheltuieli(ListaCheltuieli*);

    /*
     * Returneaza lungimea listei de cheltuieli a unui repo
     * @pre: ptr_repo_cheltuieli = pointer catre RepoCheltuieli
     * @post: lungimea cheltuielilor aceului repo
     */

unsigned int getLungime(ListaCheltuieli*);

    /*
     * Face o copie a listei de cheltuieli
     * @pre: ListaCheltuieli* indica o lista de cheltuieli
     * @post: lista de cheltuieli copiata
    */

ListaCheltuieli* copieListaCheltuieli(ListaCheltuieli*);
