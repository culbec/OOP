//
// Created by culbec on 17.06.2023.
//

#include "Tester.h"

void Tester::testTractor() {
    Tractor tractor{1, "John Deere", "Combina", 4};

    assert(tractor.getId() == 1);
    assert(tractor.getDenumire() == "John Deere");
    assert(tractor.getTip() == "Combina");
    assert(tractor.getNumarRoti() == 4);

    tractor.setNumarRoti(2);
    assert(tractor.getNumarRoti() == 2);
}

void Tester::testRepo() {
    string file = "testRepo.txt";
    ofstream(file, std::ios::trunc);

    Repository repository{file};

    assert(repository.getTractoare().empty() && repository.getTipuri().empty());

    repository.add(Tractor{1, "John Deere", "Combina", 4});
    assert(repository.getTractoare().size() == 1 && repository.getTipuri()["Combina"] == 1);
    repository.update(1, 6);
    assert(repository.getTractoare().at(0).getNumarRoti() == 6);

    try {
        Repository{"no.txt"};
        assert(false);
    } catch (runtime_error &) {
        assert(true);
    }

    Repository repository1{file};
    assert(repository1.getTractoare().size() == 1);
}

void Tester::testService() {
    string file = "testRepo.txt";
    ofstream(file, std::ios::trunc);

    Repository repository{file};
    Service service{repository};

    service.add(1, "John Deere", "Combina", 2);
    assert(service.getTractoare().size() == 1 && service.getTipuri()["Combina"] == 1);

    try {
        service.add(1, "", "", 3);
        assert(false);
    } catch (runtime_error &) {
        assert(true);
    }

    service.add(2, "A", "B", 4);
    service.sortTractoare();
    assert(service.getTractoare().at(0).getId() == 2 && service.getTractoare().at(1).getDenumire() == "John Deere");
    service.update(2, 3);
    assert(service.getTractoare().at(0).getNumarRoti() == 3);
}

void Tester::testAll() {
    Tester::testTractor();
    Tester::testRepo();
    Tester::testService();
}