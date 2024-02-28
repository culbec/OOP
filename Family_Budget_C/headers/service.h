//
// Created by culbec on 3/12/23.
//
#pragma once

#include "utils.h"
#include "repo.h"

typedef struct {
    ListaCheltuieli* repoCheltuieli;
} ServiceCheltuieli;

    /*
     * Creeaza un service de cheltuieli
     * @pre: -
     * @post: un service de cheltuieli
     */

ServiceCheltuieli* creeazaServiceCheltuieli();

    /*
     * Distruge service-ul de cheltuieli
     * @pre: ptr_service_cheltuieli -> pointer spre service cheltuieli
     * @post: service cheltuieli este distrus
     */

void distrugeServiceCheltuieli(ServiceCheltuieli*);

    /*
     * Adauge cheltuiala cu proprietatile 'ziua', 'suma', 'tip'
     * @pre: ziua, suma, tip reprezinta parametrii unei cheltuieli
     * @post: adaugarea(sau nu) a cheltuielii:
     *        - 0: nu s-a adaugat;
     *        - 1: s-a adaugat;
     *        - 2: a fost adaugata deja;
     */

int serviceAdaugaCheltuiala(ServiceCheltuieli*, int, double, char*);

    /*
     * Modifica o cheltuiala cu proprietatile date
     * @pre: ziua, suma, tipul sunt proprietatile cheltuielii de modificat
     *       newZiua, newSuma, newTip sunt proprietatile noi
     * @post: - 0: cheltuiala nu s-a modificat
     *        - 1: cheltuiala s-a modificat
     */

int serviceModificaCheltuiala(ServiceCheltuieli*, int, double, char*, int, double, char*);


    /*
     * Sterge o cheltuiala cu parametrii specificati
     * @pre: ziua, suma, tipul sunt proprietatile cheltuielii de modificat
     * @post: - 0: cheltuiala nu s-a sters
     *        - 1: cheltuiala nu s-a sters
     */

int serviceStergeCheltuiala(ServiceCheltuieli*, int, double, char*);

/*
 * Functii de filtrare pentru zi, suma sau tip
 * @pre: ListaCheltuieli* indica spre o lista de cheltuieli valida
 *       void* contine valoarea parametrului dupa care filtram
 *       char* contine tipul parametrului dupa care filtram
 *       compareMethod reprezinta functia de comparare
 * @post: lista de cheltuieli filtrata dupa una din proprietatile unei cheltuieli
*/

ListaCheltuieli* filtrare(ListaCheltuieli*, void*, char*, compareMethod);

/*
 * Functie de sortare
 * @pre: ListaCheltuieli* indica spre o lista de cheltuieli
 *	     compareMethod reprezinta functia de comparare
 *		 char* indica dupa ce parametru sortam
 *       bool reprezinta sensul de ordonare
 * @post: o lista de cheltuieli sortata dupa un parametru
*/

void sortare(ListaCheltuieli*, char*, bool);


//// cautare dupa zi / suma / tip
//
//void filtrare_zi(ServiceCheltuieli*, ListaCheltuieli*, int);
//
//void filtrare_suma(ServiceCheltuieli*, ListaCheltuieli*, double);
//
//void filtrare_tip(ServiceCheltuieli*, ListaCheltuieli*, char*);
//
//// ordonare dupa zi / tip (crescator / descrescator)
//void ordonare(ServiceCheltuieli*, ListaCheltuieli*, int, int);
