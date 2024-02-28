//
// Created by profi on 6/18/2023.
//

#include "Tester.h"

void Tester::testGame() {
    Game game{1, 3, "XXX-XOXOO", "X"};

    assert(game.getId() == 1);
    assert(game.getDim() == 3);
    assert(game.getPlayer() == "X");

    assert(game.getSequence() == "XXX-XOXOO");
    assert(game.getStatus() == "Neinceput");
    assert(game.getTable().size() == 3);

    game.setDim(4);
    assert(game.getDim() == 4);
    assert(game.getTable().size() == 4);

    game.setPlayer("O");
    assert(game.getPlayer() == "O");

    game.setSequence("X-OXO-XOO");
    assert(game.getSequence() == "X-OXO-XOO");

    game.setStatus("In derulare");
    assert(game.getStatus() == "In derulare");
}

void Tester::testRepo() {
    string file = "testRepo.txt";
    ofstream(file, std::ios::trunc);

    Repository repository{file};

    assert(repository.getGames().empty());

    repository.add(Game{1, 3, "XXX-OOXXX", "X"});
    assert(repository.getGames().size() == 1);
    assert(repository.getGames().at(0).getId() == 1);

    assert(repository.find(1).getDim() == 3);

    try {
        repository.find(2);
        assert(false);
    } catch (runtime_error &) {
        assert(true);
    }

    repository.modify(repository.getGames().at(0), 4, "XXXXOOOOXXXXOOOO", "O", "Neinceput");
    assert(repository.getGames().at(0).getSequence() == "XXXXOOOOXXXXOOOO");

    try {
        Repository{"no.txt"};
        assert(false);
    } catch (runtime_error &) {
        assert(true);
    }

    Repository repository1{file};
    assert(repository1.getGames().size() == 1);
}

void Tester::testValidator() {
    assert(Validator::validateAdd(3, "X-OXOOXOX", "X").empty());
    assert(!Validator::validateAdd(3, "XOX", "X").empty());
    assert(!Validator::validateModif(6, "XOX", "/", "ADA").empty());
}

void Tester::testService() {
    string file = "testRepo.txt";
    ofstream(file, std::ios::trunc);

    Repository repository{file};
    Service service{repository};

    assert(service.getGames().empty());

    service.add(3, "XXXOOOXXX", "X");
    assert(service.getGames().size() == 1);

    try {
        service.add(6, "", "/");
        assert(false);
    } catch (runtime_error) {
        assert(true);
    }

    service.modify(1, 4, "XOXOOXOXXOXOOXOX", "O", "Terminat");
    assert(service.getGames().at(0).getDim() == 4);

    try {
        service.modify(2, 4, "XOXOOXOXXOXOOXOX", "O", "Terminat");
        assert(false);
    } catch (runtime_error &) {
        assert(true);
    }

    try {
        service.modify(1, 6, "XOXOOXOXXOXOOXOX", "/", "fin");
        assert(false);
    } catch (runtime_error &) {
        assert(true);
    }

    assert(service.checkEnded(service.getGames().at(0)) == true);
}

void Tester::testAll() {
    Tester::testGame();
    Tester::testRepo();
    Tester::testValidator();
    Tester::testService();
}
