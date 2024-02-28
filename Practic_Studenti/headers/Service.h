//
// Created by culbec on 19.06.2023.
//

#ifndef PRACTIC_SERVICE_H
#define PRACTIC_SERVICE_H

#include "Repository.h"
#include "Undo_Redo.h"

using std::sort;

class Service {
private:
    Repository& repository; // repo-ul de care este dependent
    vector<Undo*> undos; // lista de actiuni undo
    vector<Redo*> redos; // lista de actiuni redo

public:
    /*
     * Construieste un service
     * @param: repo -> Repository
     * @post: se contruieste repository-ul
     */
    Service(Repository& repo);

    /*
     * Getter pentru lista de studenti
     * @return: lista de studenti a repo-ului de care este dependent service-ul
     */
    vector<Student>& getStudenti();

    /*
     * Functie de modificare a varstei unui student
     * @param: _id -> int
     * @param: _newVarsta -> int
     * @pre: sa existe studentul cu id-ul specificat
     * @post: studentul cu id-ul specificat va avea ca varsta varsta data ca parametru
     * @exceptions: daca studentul cu id specificat nu exista
     */
    void modify(int _id, int _newVarsta);

    /*
     * Functie de stergere a unui student
     * @param: _id -> int
     * @pre: sa existe studentul cu id-ul primit ca parametru
     * @post: studentul cu id-ul '_id' se sterge
     * @exceptions: daca studentul cu id-ul specificat nu exista
     */
    void remove(Student& studenti);

    /*
     * Functie de undo
     * @pre: sa existe actiuni undo disponibile
     * @post: se reface ultima operatie efectuata
     * @exceptions: daca nu exista actiuni in lista de actiuni undo
     */
    void undo();

    /*
     * Functie de redo
     * @pre: sa existe actiuni redo disponibile
     * @post: se reface state-ul de la ultimul undo
     * @exceptions: nu exista actiuni redo disponibile
     */
    void redo();

    /*
     * Functie de sortare a listei de studenti
     * @pre: lista de studenti in state-ul ei
     * @post: se sorteaza lista de studenti
     */
    void sortStudenti();

};

#endif //PRACTIC_SERVICE_H
