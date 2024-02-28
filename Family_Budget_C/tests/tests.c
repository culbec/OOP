//
// Created by culbec on 3/12/23.
//

#include "tests.h"
#include "../headers/domain.h"
#include "../headers/repo.h"
#include "../headers/validator.h"
#include "../headers/service.h"
#include <string.h>
#include <assert.h>

void test_domain() {
    // cheltuiala pe care vom lucra
    Cheltuiala* cheltuiala = creeazaCheltuiala(13, 123.4, "mancare");

    // testam gettere pt aceasta cheltuiala
    assert(getZiua(cheltuiala) == 13);
    assert(getSuma(cheltuiala) == 123.4);
    assert(strcmp(getTip(cheltuiala), "mancare") == 0);

    // setam parametrii la alte valori si dupa verificam cu gettere daca s-au setat
    setZiua(cheltuiala, 14);
    setSuma(cheltuiala, 13.1);
    setTip(cheltuiala, "altele");

    assert(getZiua(cheltuiala) == 14);
    assert(getSuma(cheltuiala) == 13.1);
    assert(strcmp(getTip(cheltuiala), "altele") == 0);

    // verificam daca 2 cheltuieli sunt echivalente
    Cheltuiala* cheltuiala_echiv = creeazaCheltuiala(14, 13.1, "altele");
    assert(eqCheltuieli(cheltuiala, cheltuiala_echiv) == 1);

    // verificam si ca acest lucru nu este adevarat pentru o cheltuiala neechivalenta
    Cheltuiala* cheltuiala_neechiv1 = creeazaCheltuiala(13, 13.1, "altele");
    Cheltuiala* cheltuiala_neechiv2 = creeazaCheltuiala(14, 13.1, "mancare");
    Cheltuiala* cheltuiala_neechiv3 = creeazaCheltuiala(2, 0.5, "imbracaminte");

    assert(eqCheltuieli(cheltuiala, cheltuiala_neechiv1) == 0);
    assert(eqCheltuieli(cheltuiala, cheltuiala_neechiv2) == 0);
    assert(eqCheltuieli(cheltuiala, cheltuiala_neechiv3) == 0);

    // copiem cheltuiala si verificam daca e aceeasi
    Cheltuiala* cheltuiala_copie = copieCheltuiala(cheltuiala);
    assert(eqCheltuieli(cheltuiala, cheltuiala_copie) == 1);
    
    // distrugem cheltuiala si verificam daca e distrusa
    distrugeCheltuiala(cheltuiala);
    //assert(cheltuiala->tip == NULL);

    // distrugem si restul cheltuielilor
    distrugeCheltuiala(cheltuiala_echiv);
    distrugeCheltuiala(cheltuiala_neechiv1);
    distrugeCheltuiala(cheltuiala_neechiv2);
    distrugeCheltuiala(cheltuiala_neechiv3);
    distrugeCheltuiala(cheltuiala_copie);
}

void test_repo() {
    // repo-ul de cheltuieli
    ListaCheltuieli* repoCheltuieli = creeazaRepo(1, 0);

    // verificam daca s-a creat cum trebuie
    assert(repoCheltuieli->capacitate == 1);
    assert(repoCheltuieli->lungime == 0);
    assert(repoCheltuieli->cheltuieli != NULL);

    // verificam daca functioneaza redimensionarea
    unsigned int capacitateOld = repoCheltuieli->capacitate;

    repoRedimensionare(repoCheltuieli);

    assert(repoCheltuieli->capacitate == capacitateOld * 2);

    // initializam cateva cheltuieli
    Cheltuiala* cheltuiala1 = creeazaCheltuiala(16, 23.5, "mancare");
    Cheltuiala* cheltuiala2 = creeazaCheltuiala(2, 167.8, "altele");
    Cheltuiala* cheltuiala3 = creeazaCheltuiala(31, 123.2, "imbracaminte");

    // adaugam cheltuielile pe parcurs si  verificam daca se actualizeaza lungimea
    repoAdaugareCheltuiala(repoCheltuieli, cheltuiala1);
    assert(getLungime(repoCheltuieli) == 1);

    repoAdaugareCheltuiala(repoCheltuieli, cheltuiala2);
    repoAdaugareCheltuiala(repoCheltuieli, cheltuiala3);
    assert(getLungime(repoCheltuieli) == 3);

    // cautam o cheltuiala
    cheltuiala1 = repoCheltuieli->cheltuieli[0];
    cheltuiala2 = repoCheltuieli->cheltuieli[1];
    assert(repoCautaCheltuiala(repoCheltuieli, cheltuiala1) == 0);
    assert(repoCautaCheltuiala(repoCheltuieli, cheltuiala2) == 1);

    // verificam cautarea si pentru o cheltuiala neexistenta in lista de cheltuieli
    Cheltuiala* cheltuialaNeexistenta = creeazaCheltuiala(11, 0.5, "mancare");
    assert(repoCautaCheltuiala(repoCheltuieli, cheltuialaNeexistenta) == -1);
    distrugeCheltuiala(cheltuialaNeexistenta);

    // cream o cheltuiala de modificat
    Cheltuiala* cheltuialaModif = creeazaCheltuiala(6, 56.78, "transport");
    repoModificaCheltuiala(repoCheltuieli, 0, cheltuialaModif);
    assert(eqCheltuieli(repoCheltuieli->cheltuieli[0], cheltuialaModif) == 1);
    distrugeCheltuiala(cheltuialaModif);

    // verificam getter-ul pentru lista de cheltuieli
    assert(getCheltuieli(repoCheltuieli) == repoCheltuieli->cheltuieli);

    // stergem o cheltuiala
    unsigned int lungime = getLungime(repoCheltuieli);
    repoStergeCheltuiala(repoCheltuieli, 1);
    assert(lungime == getLungime(repoCheltuieli) + 1);

    // testam copierea
    ListaCheltuieli* copieCheltuieli = copieListaCheltuieli(repoCheltuieli);
    assert(copieCheltuieli->lungime == repoCheltuieli->lungime);
    assert(copieCheltuieli->capacitate == repoCheltuieli->capacitate);
    for (unsigned int i = 0; i < repoCheltuieli->lungime; i++)
        assert(eqCheltuieli(copieCheltuieli->cheltuieli[i], repoCheltuieli->cheltuieli[i]));

    // distrugem copia
    distrugeRepo(copieCheltuieli);

    // distrugem repo-ul
    distrugeRepo(repoCheltuieli);
}

void test_validator() {
    // cream niste cheltuieli pentru a le putea valida
    Cheltuiala* cheltuialaValida    = creeazaCheltuiala(13, 15.6, "mancare");
    Cheltuiala* cheltuialaInvalida1 = creeazaCheltuiala(-1, 15.4, "altele");
    Cheltuiala* cheltuialaInvalida2 = creeazaCheltuiala(32, 16.7, "imbracaminte");
    Cheltuiala* cheltuialaInvalida3 = creeazaCheltuiala(16, -1.35, "int");
    Cheltuiala* cheltuialaInvalida4 = creeazaCheltuiala(27, 27.1, "telf");

    // initializem un repo de cheltuieli
    ListaCheltuieli* repoCheltuieli = creeazaRepo(1, 0);

    // validam cheltuielile
    assert(validareObiect(cheltuialaValida, repoCheltuieli) == 1);
    assert(validareObiect(cheltuialaInvalida1, repoCheltuieli) == 0);
    assert(validareObiect(cheltuialaInvalida2, repoCheltuieli) == 0);
    assert(validareObiect(cheltuialaInvalida3, repoCheltuieli) == 0);
    assert(validareObiect(cheltuialaInvalida4, repoCheltuieli) == 0);

    // adaugam cheltuiala valida pentru a valida si cautarea
    repoAdaugareCheltuiala(repoCheltuieli, cheltuialaValida);
    // verificam daca functioneaza cautarea
    assert(validareObiect(cheltuialaValida, repoCheltuieli) == 2);

    // distrugem repo-ul si cheltuielile;
    distrugeRepo(repoCheltuieli);
    //distrugeCheltuiala(cheltuialaValida);
    distrugeCheltuiala(cheltuialaInvalida1);
    distrugeCheltuiala(cheltuialaInvalida2);
    distrugeCheltuiala(cheltuialaInvalida3);
    distrugeCheltuiala(cheltuialaInvalida4);
}

void test_service() {
    // initializam un service si testam daca s-a initializat cum trebuie
    ServiceCheltuieli* serviceCheltuieli = creeazaServiceCheltuieli();
    assert(serviceCheltuieli->repoCheltuieli->capacitate == 1);
    assert(serviceCheltuieli->repoCheltuieli->lungime == 0);

    // adaugam o cheltuiala
    // verificam si cu cheltuieli valide, invalide si existente
    assert(serviceAdaugaCheltuiala(serviceCheltuieli, 13, 12.4, "mancare") == 1);
    assert(serviceAdaugaCheltuiala(serviceCheltuieli, 13, 12.4, "mancare") == 2);
    assert(serviceAdaugaCheltuiala(serviceCheltuieli, -1, 16, "altele") == 0);

    // verificam modificarea pentru o cheltuiala
    // incercam si cu parametrii valizi si cu cei invalizi
    assert(serviceModificaCheltuiala(serviceCheltuieli, 13, 12.4, "mancare", 11, 2000.1, "altele") == 1);
    assert(serviceModificaCheltuiala(serviceCheltuieli, 12, 11, "imbracaminte", 9, -11, "alt") == 0);
    assert(serviceModificaCheltuiala(serviceCheltuieli, -11, 16.8, "altele", 18, 10, "telefon&internet") == 0);
    assert(serviceModificaCheltuiala(serviceCheltuieli, 11, 2000.1, "altele", 19, -2, "altele") == 0);
    assert(serviceModificaCheltuiala(serviceCheltuieli, 11, 2000.1, "altele", 11, 2000.1, "altele") == 0);

    // stergem o cheltuiala
    // incercam si cu cea existenta si cu una neexistenta
    assert(serviceStergeCheltuiala(serviceCheltuieli, 11, 2000.1, "altele") == 1);
    assert(serviceStergeCheltuiala(serviceCheltuieli, 20, 19.3, "mancare") == 0);

    // adaugam cateva cheltuieli pentru filtrare si sortare
    serviceAdaugaCheltuiala(serviceCheltuieli, 17, 964, "mancare");
    serviceAdaugaCheltuiala(serviceCheltuieli, 11, 1084, "telefon&internet");
    serviceAdaugaCheltuiala(serviceCheltuieli, 11, 1946, "imbracaminte");
    serviceAdaugaCheltuiala(serviceCheltuieli, 16, 964, "mancare");
    serviceAdaugaCheltuiala(serviceCheltuieli, 22, 709, "telefon&internet");
    serviceAdaugaCheltuiala(serviceCheltuieli, 28, 488, "mancare");
    serviceAdaugaCheltuiala(serviceCheltuieli, 2, 1655, "transport");
    serviceAdaugaCheltuiala(serviceCheltuieli, 2, 975, "mancare");
    serviceAdaugaCheltuiala(serviceCheltuieli, 19, 922, "mancare");

    char tip[] = "mancare";
    ListaCheltuieli* filteredList = filtrare(serviceCheltuieli->repoCheltuieli, tip, "tip", compareTip);
    assert(filteredList->lungime == 5);
    distrugeRepo(filteredList);

    int ziua = 11;
    filteredList = filtrare(serviceCheltuieli->repoCheltuieli, &ziua, "zi", compareZi);
    assert(filteredList->lungime == 2);
    distrugeRepo(filteredList);

    double suma = 964;
    filteredList = filtrare(serviceCheltuieli->repoCheltuieli, &suma, "suma", compareSuma);
    assert(filteredList->lungime == 2);
    distrugeRepo(filteredList);

    // verificam si ordonarea - crescator si descrescator
    ListaCheltuieli* ordonareCrescatorZi = copieListaCheltuieli(serviceCheltuieli->repoCheltuieli);
    ListaCheltuieli* ordonareDescrescatorZi = copieListaCheltuieli(serviceCheltuieli->repoCheltuieli);
    ListaCheltuieli* ordonareCrescatorTip = copieListaCheltuieli(serviceCheltuieli->repoCheltuieli);
    ListaCheltuieli* ordonareDescrescatorTip = copieListaCheltuieli(serviceCheltuieli->repoCheltuieli);

    int pozitieUltim = getLungime(ordonareCrescatorZi) - 1;

    // sortam crescator dupa zi
    sortare(ordonareCrescatorZi, "zi", false);
    assert(eqCheltuieli(ordonareCrescatorZi->cheltuieli[0], serviceCheltuieli->repoCheltuieli->cheltuieli[6]) == 1);
    assert(eqCheltuieli(ordonareCrescatorZi->cheltuieli[pozitieUltim], serviceCheltuieli->repoCheltuieli->cheltuieli[5]) == 1);

    //sortam descrescator dupa zi
    sortare(ordonareDescrescatorZi, "zi", true);
    assert(eqCheltuieli(ordonareDescrescatorZi->cheltuieli[0], serviceCheltuieli->repoCheltuieli->cheltuieli[5]) == 1);
    assert(eqCheltuieli(ordonareDescrescatorZi->cheltuieli[pozitieUltim], serviceCheltuieli->repoCheltuieli->cheltuieli[6]) == 1);

    // sortam crescator dupa tip
    sortare(ordonareCrescatorTip, "tip", false);
    assert(eqCheltuieli(ordonareCrescatorTip->cheltuieli[0], serviceCheltuieli->repoCheltuieli->cheltuieli[2]) == 1);
    assert(eqCheltuieli(ordonareCrescatorTip->cheltuieli[pozitieUltim], serviceCheltuieli->repoCheltuieli->cheltuieli[6]) == 1);

    // sortam descrescator dupa tip
    sortare(ordonareDescrescatorTip, "tip", true);
    assert(eqCheltuieli(ordonareDescrescatorTip->cheltuieli[0], serviceCheltuieli->repoCheltuieli->cheltuieli[6]) == 1);
    assert(eqCheltuieli(ordonareDescrescatorTip->cheltuieli[pozitieUltim], serviceCheltuieli->repoCheltuieli->cheltuieli[2]) == 1);

    // distrugem toate listele create
    distrugeRepo(ordonareCrescatorZi);
    distrugeRepo(ordonareDescrescatorZi);
    distrugeRepo(ordonareCrescatorTip);
    distrugeRepo(ordonareDescrescatorTip);

    // distrugem si service-ul
    distrugeServiceCheltuieli(serviceCheltuieli);
}