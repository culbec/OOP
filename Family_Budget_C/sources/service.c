//
// Created by culbec on 3/12/23.
//

#include "../headers/service.h"
#include "../headers/validator.h"
#include "../headers/utils.h"
#include <string.h>

ServiceCheltuieli* creeazaServiceCheltuieli() {
    
    ServiceCheltuieli* serviceCheltuieli = (ServiceCheltuieli*)malloc(sizeof(ServiceCheltuieli));
    if (serviceCheltuieli) {
        serviceCheltuieli->repoCheltuieli = creeazaRepo(1, 0);
        return serviceCheltuieli;
    }
    return NULL;
}

void distrugeServiceCheltuieli(ServiceCheltuieli* serviceCheltuieli) {
    distrugeRepo(serviceCheltuieli->repoCheltuieli);
    free(serviceCheltuieli);
}

int serviceAdaugaCheltuiala(ServiceCheltuieli* serviceCheltuieli, int ziua, double suma, char* tip) {
    Cheltuiala* cheltuiala = creeazaCheltuiala(ziua, suma, tip);
    int rez = 1;

    if (validareObiect(cheltuiala, serviceCheltuieli->repoCheltuieli) == 0) 
        rez =  0;
    if (validareObiect(cheltuiala, serviceCheltuieli->repoCheltuieli) == 2)
        rez = 2;
    
    if(rez == 1)
        repoAdaugareCheltuiala(serviceCheltuieli->repoCheltuieli, cheltuiala);
    else
        distrugeCheltuiala(cheltuiala);
    return rez;
}

int serviceModificaCheltuiala(ServiceCheltuieli* serviceCheltuieli, int ziua, double suma, char* tip,
                                                                    int newZiua, double newSuma, char* newTip) {
    Cheltuiala* cheltuiala = creeazaCheltuiala(ziua, suma, tip);
    int rez = 1;

    int index = repoCautaCheltuiala(serviceCheltuieli->repoCheltuieli, cheltuiala);
    if (index == -1)
        rez = 0; // nu exista cheltuiala in lista

    Cheltuiala* newCheltuiala = creeazaCheltuiala(newZiua, newSuma, newTip);

    if (rez) {
        int rezV = validareObiect(newCheltuiala, serviceCheltuieli->repoCheltuieli);
        if (rezV == 2 || rezV == 0)
            rez = 0;
    }
    if(rez)
        repoModificaCheltuiala(serviceCheltuieli->repoCheltuieli, index, newCheltuiala);
    
    distrugeCheltuiala(cheltuiala);
    distrugeCheltuiala(newCheltuiala);
    return rez;
}

int serviceStergeCheltuiala(ServiceCheltuieli* serviceCheltuieli, int ziua, double suma, char* tip) {
    Cheltuiala* cheltuiala = creeazaCheltuiala(ziua, suma, tip);
    int rez = 1;

    int index = repoCautaCheltuiala(serviceCheltuieli->repoCheltuieli, cheltuiala);
    if (index == -1)
        rez = 0; // nu exista cheltuiala in lista ==> nu se poate sterge
    
    if(rez)
        repoStergeCheltuiala(serviceCheltuieli->repoCheltuieli, index);
    distrugeCheltuiala(cheltuiala);
    return rez;
}


ListaCheltuieli* filtrare(ListaCheltuieli* listaCheltuieli, void* parametru, char* whatFilter, compareMethod compare) {
    ListaCheltuieli* filteredList = creeazaRepo(listaCheltuieli->lungime, 0);
    // whatFilter = 1 -> ziua; = 2 -> suma; = 3 -> tip
    Cheltuiala* cheltuialaCompare;
    if (strcmp(whatFilter, "zi") == 0)
        cheltuialaCompare = creeazaCheltuiala(*(int*)parametru, -1, "");
    else if (strcmp(whatFilter, "suma") == 0)
        cheltuialaCompare = creeazaCheltuiala(-1, *(double*)parametru, "");
    else
        cheltuialaCompare = creeazaCheltuiala(-1, -1, (char*)parametru);

    for (unsigned int i = 0; i < listaCheltuieli->lungime; i++)
        if (compare(listaCheltuieli->cheltuieli[i], cheltuialaCompare) == 0)
            repoAdaugareCheltuiala(filteredList, copieCheltuiala(listaCheltuieli->cheltuieli[i]));

    distrugeCheltuiala(cheltuialaCompare);
    return filteredList;
}

void sortare(ListaCheltuieli* listaCheltuieli, char* whatSort, bool reversed) {
    if (strcmp(whatSort, "zi") == 0)
        selectionSort(listaCheltuieli, reversed, compareZi);
    else if (strcmp(whatSort, "tip") == 0)
        selectionSort(listaCheltuieli, reversed, compareTip);
}