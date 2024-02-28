//
// Created by culbec on 3/12/23.
//
#include "../headers/ui.h"

UI* creeazaUi() {
    UI* ui = (UI*)malloc(sizeof(UI));
    if (ui)
        ui->serviceCheltuieli = creeazaServiceCheltuieli();
    return ui;
}

void distrugeUi(UI* ui) {
    distrugeServiceCheltuieli(ui->serviceCheltuieli);
    free(ui);
}

void uiAfiseazaCheltuieli(ListaCheltuieli* listaCheltuieli) {
    // afiseaza cheltuielile curente
    if (getLungime(listaCheltuieli) == 0) {
        printf("\nNu exista cheltuieli!\n");
        return;
    }
    else {
        Cheltuiala** cheltuieli = getCheltuieli(listaCheltuieli);
        printf("\nCheltuielile sunt: \n");
        for (unsigned int i = 0; i < getLungime(listaCheltuieli); i++)
            printf("Ziua: %d | Suma: %lf | Tipul: %s\n", 
                cheltuieli[i]->ziua, cheltuieli[i]->suma, cheltuieli[i]->tip);
    }
}

void uiAdaugareCheltuiala(UI* ui) {
    // incearca sa adauge o cheltuiala la lista de cheltuieli
    int ziua; double suma; char tip[51];

    printf("\nZiua cheltuielii: ");
    scanf_s("%d", &ziua);

    printf("Suma cheltuielii: ");
    scanf_s("%lf", &suma);

    printf("Tipul cheltuielii: ");
    scanf_s("%s", tip, 51);

    int result = serviceAdaugaCheltuiala(ui->serviceCheltuieli, ziua, suma, tip);
    if (result == 0)
        printf("\nParametrii invalizi!\n");
    else if (result == 2) 
        printf("\nCheltuiala deja exista!\n");
    else
        printf("\nCheltuiala adaugata cu succes!\n");
}

void uiModificareCheltuiala(UI* ui) {
    if (getLungime(ui->serviceCheltuieli->repoCheltuieli) == 0) {
        printf("\nNu exista cheltuieli de modificat!\n");
        return;
    }
    uiAfiseazaCheltuieli(ui->serviceCheltuieli->repoCheltuieli);
    // incearca sa modifice o cheltuiala;
    int ziua; double suma; char tip[51];
    int new_ziua; double new_suma; char new_tip[51];

    printf("\nZiua cheltuielii de modificat: ");
    scanf_s("%d", &ziua);

    printf("Suma cheltuielii de modificat: ");
    scanf_s("%lf", &suma);

    printf("Tipul cheltuielii de modificat: ");
    scanf_s("%s", tip, 51);

    printf("\nZiua noua: ");
    scanf_s("%d", &new_ziua);

    printf("Suma noua: ");
    scanf_s("%lf", &new_suma);

    printf("Tipul nou: ");
    scanf_s("%s", new_tip, 51);

    int result = serviceModificaCheltuiala(ui->serviceCheltuieli, ziua, suma, tip, new_ziua, new_suma, new_tip);
    if (result == 0)
        printf("\nCheltuiala nu exista sau parametrii de modificare invalizi!\n");
    else
        printf("\nCheltuiala modificata cu succes!\n");
}

void uiStergeCheltuiala(UI* ui) {
    if (getLungime(ui->serviceCheltuieli->repoCheltuieli) == 0) {
        printf("\nNu exista cheltuieli de sters!\n");
        return;
    }
    // sterge o cheltuiala
    int ziua; double suma; char tip[51];

    printf("\nZiua cheltuielii: ");
    scanf_s("%d", &ziua);

    printf("Suma cheltuielii: ");
    scanf_s("%lf", &suma);

    printf("Tipul cheltuielii: ");
    scanf_s("%s", tip, 50);

    int result = serviceStergeCheltuiala(ui->serviceCheltuieli, ziua, suma, tip);
    if (result == 0)
        printf("\nNu exista cheltuiala!\n");
    else
        printf("\nStergere cu succes!\n");
}

void uiFiltrare(UI* ui) {
    ListaCheltuieli* listaCheltuieli = NULL;
    char whatFilter[6];
    printf("\nDupa ce doriti sa filtrati? Tastati 'zi', 'suma' sau 'tip': ");
    scanf_s("%s", whatFilter, 5);
    whatFilter[strlen(whatFilter)] = '\0';
    if (strcmp(whatFilter, "zi") == 0) {
        int ziua;
        printf("\nZiua dupa care se filtreaza: ");
        scanf_s("%u", &ziua);
        listaCheltuieli = filtrare(ui->serviceCheltuieli->repoCheltuieli, &ziua, whatFilter, compareZi);
        if (getLungime(listaCheltuieli) == 0) {
            printf("\nNu exista cheltuieli cu ziua specificata!\n");
            return;
        }
        else
            uiAfiseazaCheltuieli(listaCheltuieli);
        distrugeRepo(listaCheltuieli);
    }
    else if (strcmp(whatFilter, "suma") == 0) {
        double suma;
        printf("\nSuma dupa care se filtreaza: ");
        scanf_s("%lf", &suma);
        listaCheltuieli = filtrare(ui->serviceCheltuieli->repoCheltuieli, &suma, whatFilter, compareSuma);
        if (getLungime(listaCheltuieli) == 0) {
            printf("\nNu exista cheltuieli cu suma specificata!\n");
            return;
        }
        else
            uiAfiseazaCheltuieli(listaCheltuieli);
        distrugeRepo(listaCheltuieli);
    }
    else if (strcmp(whatFilter, "tip") == 0) {
        char tip[51];
        printf("\nTipul dupa ce se filtreaza: ");
        scanf_s("%s", tip, 50);
        tip[strlen(tip)] = '\0';
        listaCheltuieli = filtrare(ui->serviceCheltuieli->repoCheltuieli, tip, whatFilter, compareTip);
        if (getLungime(listaCheltuieli) == 0) {
            printf("\nNu exista cheltuieli cu tipul specificat!\n");
            return;
        }
        else
            uiAfiseazaCheltuieli(listaCheltuieli);
        distrugeRepo(listaCheltuieli);
    }
    else
        printf("Parametru invalid!");
}

void uiOrdonare(UI* ui) {
    ListaCheltuieli* listaCheltuieli = copieListaCheltuieli(ui->serviceCheltuieli->repoCheltuieli);
    char whatSort[5];
    printf("\nDupa ce doriti sa sortati? Tastati 'zi' sau 'tip': ");
    scanf_s("%s", whatSort, 4);
    
    int reversed;
    printf("\nTastati 1 pentru crescator si 2 pentru descrescator: ");
    scanf_s("%d", &reversed);
    if (reversed == 1)
        sortare(listaCheltuieli, whatSort, false);
    else if (reversed == 2)
        sortare(listaCheltuieli, whatSort, true);
    else {
        printf("\nNu s-a introdus o valoare corecta pentru sensul de sortare!\n");
        return;
    }
    uiAfiseazaCheltuieli(listaCheltuieli);
    distrugeRepo(listaCheltuieli);
}

void showUi() {
    UI* ui = creeazaUi();
    printf("###################################################\n\n");
    printf("\t\t BUGET DE FAMILIE \t\t");
    printf("\n\n###################################################\n");
    while (1) {
        printf("\nOptiuni: \n 0. Afiseaza cheltuieli \n 1. Adauga cheltuiala \n 2. Modifica cheltuiala \n 3. Sterge cheltuiala \n "
                             "4. Filtrare cheltuiala \n 5. Sortare cheltuieli \n 6. Iesire");
        
        int optiune;
        printf("\nOptiune: ");
        scanf_s("%d", &optiune);
        
        if (optiune == 6) {
            printf("Bye!");
            distrugeUi(ui);
            return;
        }
        else if (optiune == 0)
            uiAfiseazaCheltuieli(ui->serviceCheltuieli->repoCheltuieli);
        else if (optiune == 1)
            uiAdaugareCheltuiala(ui);
        else if (optiune == 2)
            uiModificareCheltuiala(ui);
        else if (optiune == 3)
            uiStergeCheltuiala(ui);
        else if (optiune == 4)
            uiFiltrare(ui);
        else if (optiune == 5)
            uiOrdonare(ui);
        else
            printf("Optiune invalida!\n");
    }
}
