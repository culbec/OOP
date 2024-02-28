//
// Created by culbec on 16.06.2023.
//

#include "../headers/tester.h"

void Tester::testMelodie() {
    Melodie melodie{1, "Wrecking Ball", "Miley Cirus", 10};

    assert(melodie.getId() == 1);
    assert(melodie.getTitlu() == "Wrecking Ball");
    assert(melodie.getArtist() == "Miley Cirus");
    assert(melodie.getRank() == 10);

    melodie.setRank(2);
    assert(melodie.getRank() == 2);
}

void Tester::testRepo() {
    string file = "testRepo.txt";
    ofstream(file, ios::trunc);

    Repository repository{file};

    assert(repository.getMelodii().empty());
    repository.add(Melodie{1, "Aansa", "velea", 9});
    assert(repository.getMelodii().size() == 1);

    repository.add(Melodie{2, "adja", "connectr", 2});
    assert(repository.getMelodii().size() == 2);

    assert(repository.find(1).getId() == repository.getMelodii()[0].getId());
    repository.sterge(repository.getMelodii()[0].getId());

    try {
        repository.find(1);
        assert(false);
    } catch (runtime_error&) {
        assert(true);
    }

    Repository repository1{file};
    assert(repository1.getMelodii().size() == 1);
}

void Tester::testService() {
    string file = "testRepo.txt";
    ofstream(file, ios::trunc);

    Repository repository{file};
    Service service{repository};

    repository.add(Melodie{1, "XXX", "Puya", 10});
    repository.add(Melodie{2, "Yamasha", "Alex Velea", 1});
    repository.add(Melodie{3, "Baws", "Bruja", 2});
    repository.add(Melodie{4, "XZY", "Ian", 3});

    assert(service.getRanks()[1] == 1);

    assert(service.getMelodii().size() == 4);
    service.updateRank(4, 1);
    assert(service.getMelodii()[3].getRank() == 1);
    assert(service.getRanks()[1] == 2);

    service.sterge(4);
    assert(service.getMelodii().size() == 3);
    assert(service.getRanks()[1] == 1);

    service.sortMelodii();
    assert(service.getMelodii()[0].getId() == 2 && service.getMelodii()[0].getTitlu() == "Yamasha");
}

void Tester::testAll() {
    this->testMelodie();
    this->testRepo();
    this->testService();
}
