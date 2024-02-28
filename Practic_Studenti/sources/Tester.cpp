//
// Created by culbec on 19.06.2023.
//

#include "../headers/Tester.h"

void Tester::testStudent() {
    Student student{1, "Ion", 20, "info"};

    assert(student.getNrMatricol() == 1);
    assert(student.getNume() == "Ion");
    assert(student.getVarsta() == 20);
    assert(student.getFacultate() == "info");

    student.setVarsta(21);
    assert(student.getVarsta() == 21);
}

void Tester::testRepository() {
    string file = "testRepo.txt";
    ofstream(file, std::ios::trunc);

    Repository repository{file};
    assert(repository.getStudenti().empty());

    repository.add(Student{1, "Ion", 20, "info"});
    assert(repository.getStudenti().size() == 1);

    repository.modify(1, 21);
    assert(repository.getStudenti().at(0).getVarsta() == 21);

    auto student = repository.find(1);
    assert(student.getNume() == "Ion");

    try {
        repository.find(2);
        assert(false);
    } catch (runtime_error &) {
        assert(true);
    }

    repository.remove(1);
    assert(repository.getStudenti().empty());

    repository.add(Student{1, "Ion", 20, "info"});
    try {
        repository.modify(2, 21);
        assert(false);
    } catch (runtime_error &) {
        assert(true);
    }

    try {
        repository.remove(2);
        assert(false);
    } catch (runtime_error &) {
        assert(true);
    }

    try {
        Repository{"no.txt"};
        assert(false);
    } catch(runtime_error&) {
        assert(true);
    }

    Repository repository1{file};
    assert(repository1.getStudenti().size() == 1);
}

void Tester::testService() {
    string file = "testRepo.txt";
    ofstream(file, std::ios::trunc);

    Repository repository{file};
    Service service{repository};

    assert(service.getStudenti().empty());

    repository.add(Student{1, "Ion", 20, "info"});
    assert(service.getStudenti().size() == 1);

    service.remove(service.getStudenti().at(0));
    assert(service.getStudenti().empty());
    service.undo();
    assert(service.getStudenti().size() == 1);
    service.redo();
    assert(service.getStudenti().empty());

    repository.add(Student{1, "Ion", 20, "info"});

    service.modify(1, 21);
    assert(service.getStudenti().at(0).getVarsta() == 21);

    service.undo();
    assert(service.getStudenti().at(0).getVarsta() == 20);

    try{
        service.undo();
        assert(false);
    } catch (runtime_error&) {
        assert(true);
    }

    service.redo();
    assert(service.getStudenti().at(0).getVarsta() == 21);

    try {
        service.redo();
        assert(false);
    } catch (runtime_error&) {
        assert(true);
    }

    repository.add(Student{2, "Marian", 30, "info"});
    repository.add(Student{3, "Andrei", 22, "mate"});

    service.sortStudenti();

    assert(service.getStudenti().at(0).getVarsta() == 21);
    assert(service.getStudenti().back().getVarsta() == 30);

    try {
        service.modify(1, 91);
        assert(false);
    } catch(runtime_error&) {
        assert(true);
    }
}

void Tester::testAll() {
    Tester::testStudent();
    Tester::testRepository();
    Tester::testService();
}