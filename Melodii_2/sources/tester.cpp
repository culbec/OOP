//
// Created by culbec on 17.06.2023.
//

#include "../headers/tester.h"

void Tester::testMelodie() {
    Melodie melodie{1, "Yamasha", "Alex Velea", "Pop"};

    assert(melodie.getId() == 1);
    assert(melodie.getTitlu() == "Yamasha");
    assert(melodie.getArtist() == "Alex Velea");
    assert(melodie.getGen() == "Pop");

    melodie.setId(2);
    assert(melodie.getId() == 2);
}

void Tester::testRepo() {
    string file = "testRepo.txt";
    ofstream(file, std::ios::trunc);

    Repository repository{file};

    assert(repository.getMelodii().empty() && repository.getArtisti().empty() && repository.getGenuri().empty());

    repository.add(Melodie{1, "Yamasha", "Alex Velea", "Pop"});
    assert(repository.getMelodii().size() == 1);
    assert(repository.getArtisti()["Alex Velea"] == 1);
    assert(repository.getGenuri()["Pop"] == 1);

    repository.sterge(1);
    assert(repository.getMelodii().empty());
    assert(repository.getArtisti()["Alex Velea"] == 0);
    assert(repository.getGenuri()["Pop"] == 0);

    repository.add(Melodie{1, "Yamasha", "Alex Velea", "Pop"});

    try {
        Repository{"no.txt"};
        assert(false);
    } catch (runtime_error&) {
        assert(true);
    }

    Repository repository1{file};
    assert(repository1.getMelodii().size() == 1);
}

void Tester::testService() {
    string file = "testRepo.txt";
    ofstream(file, std::ios::trunc);

    Repository repository{file};
    Service service{repository};

    service.add("Yamasha", "Alex Velea", "Pop");
    assert(service.getMelodii().size() == 1);
    assert(service.getArtisti()["Alex Velea"] == 1);
    assert(service.getGenuri()["Pop"] == 1);

    service.add("Bubble", "Adda", "Pop");
    assert(service.getMelodii().at(0).getArtist() == "Adda");

    service.sterge(service.getMelodii().at(1));
    assert(service.getMelodii().size() == 1);
}

void Tester::testAll() {
    Tester::testMelodie();
    Tester::testRepo();
    Tester::testService();
}
