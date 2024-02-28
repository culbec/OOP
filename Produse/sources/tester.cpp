#include "../headers/tester.h"

void Tester::testProdus() {
    Produs produs1{1, "Lapte", "Aliment", 99.1};
    Produs produs2{2, "Pantaloni", "Imbracaminte", 10.3};

    assert(produs1.getId() == 1);
    assert(produs1.getNume() == "Lapte");
    assert(produs1.getTip() == "Aliment");

    assert(produs1.getVowels() == 2);
    assert(produs2.getVowels() == 4);
}

void Tester::testRepo() {
    string file = "testRepo.txt";
    ofstream(file, std::ios::trunc);

    Repository repository{file};

    repository.add(Produs{1, "Lapte", "Aliment", 99.3});
    assert(repository.getProduse().size() == 1);
    assert(repository.getProduse().at(0).getId() == 1);

    repository.add(Produs{2, "Paine", "Aliment", 10.3});

    Repository repository1{file};
    assert(repository1.getProduse().size() == 2);
}

void Tester::testService() {
    string file = "testRepo.txt";
    ofstream(file, std::ios::trunc);

    Repository repository{file};
    Service service{repository};

    service.add(1, "Lapte", "Aliment", 99.3);
    assert(service.getProduse().size() == 1);

    try{
        service.add(1, "", "", 100.4);
        assert(false);
    } catch(runtime_error& rE) {
        assert(string{rE.what()} == "Un produs cu acest id exista deja!\nNumele produsului nu poate fi vid!\nPretul produsului trebuie sa fie intre 1.0 si 100.0!\n");
    }

    service.add(2, "Paine", "Aliment", 10.3);
    service.add(3, "Pantaloni", "Haine", 30.0);

    assert(service.filter(50.0).size() == 2);
    assert(service.getTipuri()["Aliment"] == 2);

    Service service1{repository};
    assert(service1.getTipuri().size() == 2 && service.getTipuri()["Haine"] == 1);
}

void Tester::testAll() {
    this->testProdus();
    this->testRepo();
    this->testService();
}