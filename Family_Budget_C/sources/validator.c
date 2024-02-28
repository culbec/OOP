//
// Created by culbec on 3/12/23.
//

#include "../headers/domain.h"
#include "../headers/validator.h"
#include "../headers/repo.h"

int validareObiect(Cheltuiala* cheltuiala, ListaCheltuieli* repoCheltuieli) {
    const char* cheltuieli[][50] = { "mancare", "transport", "telefon&internet", "imbracaminte"
                              ,"altele" };

    if (cheltuiala->ziua < 1 || cheltuiala->ziua > 31)
        return 0; // zi invalida
    if (cheltuiala->suma - 0 <= EPSILON || cheltuiala->suma < 0)
        return 0; // suma invalida

    int cheltuialaOk = 0;
    for (unsigned int i = 0; i < 5 && cheltuialaOk == 0; i++)
        if (strcmp(cheltuiala->tip, cheltuieli[0][i]) == 0)
            cheltuialaOk = 1;
    if (cheltuialaOk == 0)
        return 0; // tip invalid
    if (repoCautaCheltuiala(repoCheltuieli, cheltuiala) != -1)
        return 2; // obiectul deja exista

    return 1; // obiect valid
}
