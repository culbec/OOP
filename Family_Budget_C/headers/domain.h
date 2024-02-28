//
// Created by culbec on 3/12/23.
//

#pragma once

#include <string.h>
#include <stdlib.h>

#define EPSILON 0.000000001


// ENTITATEA

typedef struct {
    int ziua;      // ziua in care s-a facut cheltuiala
    double suma;   // suma cheltuielii efectuate
    char* tip;      // tipul unei cheltuieli: 
                    //mancare, transport, telefon&internet, imbracaminte, altele
}Cheltuiala;

    /*
     * Creeaza o cheltuiala
     * @pre: int, double, char* = ziua, suma, tipul
     * @post: se creeaza cheltuiala cu proprietatile specificate
     * ! also: se poate ca cheltuiala sa nu se poata creea
     *         astfel, se va indica acest lucru
     */
Cheltuiala* creeazaCheltuiala(int, double, char*);

    /*
     * 'Distruge' cheltuiala
     * @pre: Cheltuiala* = indica o cheltuiala valida
     * @post: se distruge cheltuiala
     */

void distrugeCheltuiala(Cheltuiala*);

    /*
     * Returneaza ziua pentru o cheltuiala specificata
     *
     * @pre: Cheltuiala* = indica o cheltuiala valida
     * @post: ziua in care s-a efectuat cheltuiala
    */
int getZiua(Cheltuiala*);

    /*
     * Seteaza ziua pentru o cheltuiala
     * @pre: Cheltuiala* = indica o cheltuiala valida
     *       int = ziua ce va fi atribuita cheltuielii
     * @post: cheltuiala va avea ziua specificata
     */

void setZiua(Cheltuiala*, int);

    /*
     * Returneaza suma pentru o cheltuiala specificata
     *
     * @pre: Cheltuiala* = indica o cheltuiala valida
     * @post: suma in care s-a efectuat cheltuiala
    */

double getSuma(Cheltuiala*);

    /*
     * Seteaza ziua pentru o cheltuiala
     * @pre: Cheltuiala* = indica o cheltuiala valida
     *       double = suma ce va fi atribuita cheltuielii
     * @post: cheltuiala va avea suma specificata
     */

void setSuma(Cheltuiala*, double);

    /*
     * Returneaza tipul pentru o cheltuiala specificata
     *
     * @pre: Cheltuiala* = indica o cheltuiala valida
     * @post: suma in care s-a efectuat cheltuiala
    */

char* getTip(Cheltuiala*);

    /*
     * Seteaza tipul pentru o cheltuiala
     * @pre: Cheltuiala* = indica o cheltuiala valida
     *       char* = tipul ce va fi atribuit cheltuielii
     * @post: cheltuiala va avea tipul specificat
     */

void setTip(Cheltuiala*, char*);

    /*
     * Verifica daca doua cheltuieli sunt echivalente
     * @pre: Cheltuiala*, Cheltuiala* = indica doua cheltuieli valide
     * @post: rezultatul verificarii echivalentei
     */

int eqCheltuieli(Cheltuiala*, Cheltuiala*);

    /*
     * Copiaza cheltuiala
     * @pre: Cheltuiala* refera o cheltuiala valida
     * @post: copia cheltuielii
    */

Cheltuiala* copieCheltuiala(Cheltuiala*);