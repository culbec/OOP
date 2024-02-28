//
// Created by culbec on 3/12/23.
//

#include "../headers/domain.h"

// implementarile functiilor ce apartin domeniului

Cheltuiala* creeazaCheltuiala(int ziua, double suma, char* tip) {
    Cheltuiala* cheltuiala = (Cheltuiala*)malloc(sizeof(Cheltuiala));
    if (cheltuiala) {

        cheltuiala->ziua = ziua;
        cheltuiala->suma = suma;

        cheltuiala->tip = (char*)malloc((strlen(tip) + 1) * sizeof(char));
        if (cheltuiala->tip)
            strcpy_s(cheltuiala->tip, strlen(tip) + 1, tip);
    }
      
    return cheltuiala;
}

void distrugeCheltuiala(Cheltuiala* cheltuiala) {
    free(cheltuiala->tip);
    free(cheltuiala);
}

int getZiua(Cheltuiala* cheltuiala) {
    return cheltuiala->ziua;
}

void setZiua(Cheltuiala* cheltuiala, int new_ziua) {
    cheltuiala->ziua = new_ziua;
}

double getSuma(Cheltuiala* cheltuiala) {
    return cheltuiala->suma;
}

void setSuma(Cheltuiala* cheltuiala, double new_suma) {
    cheltuiala->suma = new_suma;
}

char* getTip(Cheltuiala* cheltuiala) {
    return cheltuiala->tip;
}

void setTip(Cheltuiala* cheltuiala, char* new_tip) {
    free(cheltuiala->tip);
    cheltuiala->tip = (char*)malloc((strlen(new_tip) + 1) * sizeof(char));
    if (cheltuiala->tip)
        strcpy_s(cheltuiala->tip, strlen(new_tip) + 1, new_tip);
}

int eqCheltuieli(Cheltuiala* this, Cheltuiala* other) {
    if (this->ziua != other->ziua)
        return 0;
    if (abs(this->suma - other->suma) > EPSILON)
        return 0;
    if (strcmp(this->tip, other->tip) != 0)
        return 0;
    return 1;
}

Cheltuiala* copieCheltuiala(Cheltuiala* cheltuiala) {
    return creeazaCheltuiala(cheltuiala->ziua, cheltuiala->suma, cheltuiala->tip);
}