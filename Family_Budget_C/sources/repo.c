//
// Created by culbec on 3/12/23.
//

#include "../headers/repo.h"
#include "../headers/utils.h"

ListaCheltuieli* creeazaRepo(unsigned int capacitate, unsigned int lungime) {
    ListaCheltuieli* repoCheltuieli = (ListaCheltuieli*)malloc(sizeof(ListaCheltuieli));
    if (repoCheltuieli) {
        repoCheltuieli->capacitate = capacitate;
        repoCheltuieli->lungime = lungime;
        repoCheltuieli->cheltuieli = (Cheltuiala**)malloc(repoCheltuieli->capacitate * sizeof(Cheltuiala*));
    }
    return repoCheltuieli;
}

void distrugeRepo(ListaCheltuieli* repoCheltuieli) {
    for (unsigned int i = 0; i < repoCheltuieli->lungime; i++)
        distrugeCheltuiala(repoCheltuieli->cheltuieli[i]);
    free(repoCheltuieli->cheltuieli);
    free(repoCheltuieli);
}

void repoRedimensionare(ListaCheltuieli* repoCheltuieli) {
    unsigned int capacitateNew = repoCheltuieli->capacitate * 2;
    Cheltuiala** newCheltuieli = (Cheltuiala**)malloc(capacitateNew * sizeof(Cheltuiala*));
    if (newCheltuieli != NULL) {
        for (unsigned int i = 0; i < repoCheltuieli->lungime; i++)
                newCheltuieli[i] = copieCheltuiala(repoCheltuieli->cheltuieli[i]);
        for (unsigned int i = 0; i < repoCheltuieli->lungime; i++)
            distrugeCheltuiala(repoCheltuieli->cheltuieli[i]);
        free(repoCheltuieli->cheltuieli);
        repoCheltuieli->cheltuieli = newCheltuieli;
        repoCheltuieli->capacitate = capacitateNew;
    }
}

void repoAdaugareCheltuiala(ListaCheltuieli* repoCheltuieli, Cheltuiala* cheltuiala) {
    if (repoCheltuieli->lungime == repoCheltuieli->capacitate)
        repoRedimensionare(repoCheltuieli);
    repoCheltuieli->cheltuieli[repoCheltuieli->lungime++] = cheltuiala;
}

void repoModificaCheltuiala(ListaCheltuieli* repoCheltuieli, int index, Cheltuiala* cheltuiala) {
    distrugeCheltuiala(repoCheltuieli->cheltuieli[index]);
    repoCheltuieli->cheltuieli[index] = copieCheltuiala(cheltuiala);
}

void repoStergeCheltuiala(ListaCheltuieli* repoCheltuieli, int index) {
    for (unsigned int i = index; i < repoCheltuieli->lungime - 1; i++)
        swap(&repoCheltuieli->cheltuieli[i], &repoCheltuieli->cheltuieli[i + 1]);
    distrugeCheltuiala(repoCheltuieli->cheltuieli[repoCheltuieli->lungime - 1]);
    repoCheltuieli->lungime--;
}

int repoCautaCheltuiala(ListaCheltuieli* repoCheltuieli, Cheltuiala* cheltuiala) {
    for (unsigned int i = 0; i < repoCheltuieli->lungime; i++)
        if (eqCheltuieli(repoCheltuieli->cheltuieli[i], cheltuiala) == 1)
            return i;
    return -1;
}


Cheltuiala** getCheltuieli(ListaCheltuieli* repoCheltuieli) {
    return repoCheltuieli->cheltuieli;
}

unsigned int getLungime(ListaCheltuieli* repoCheltuieli) {
    return repoCheltuieli->lungime;
}

ListaCheltuieli* copieListaCheltuieli(ListaCheltuieli* repoCheltuieli) {
    ListaCheltuieli* copieLista = creeazaRepo(repoCheltuieli->capacitate, repoCheltuieli->lungime);
    if (copieLista) {
        for (unsigned int i = 0; i < repoCheltuieli->lungime; i++)
            copieLista->cheltuieli[i] = copieCheltuiala(repoCheltuieli->cheltuieli[i]);
        return copieLista;
    }
    return NULL;
}