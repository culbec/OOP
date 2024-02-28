//
// Created by culbec on 19.06.2023.
//

#ifndef PRACTIC_REPOSITORY_H
#define PRACTIC_REPOSITORY_H

#include "Student.h"
#include <vector>
#include <fstream>
#include <exception>
#include <algorithm>

using std::vector;
using std::ifstream;
using std::ofstream;
using std::runtime_error;
using std::getline;
using std::stoi;
using std::find_if;

class Repository {
private:
    string file;
    vector<Student> studenti;

    /*
     * Incarca continutul din fisierul file
     * @pre: fisierul cu numele file sa existe
     * @post: se populeaza lista de studenti cu continutul fisierului file
     */
    void loadFromFile();

    /*
     * Se repopuleaza fisierul cu continutul listei de studenti
     * @post: se repopuleaza fisierul cu continutul listei de studenti
     */
    void writeToFile();

public:
    /*
     * Construieste un repository
     * @param: _file -> string
     * @pre: fisierul cu numele _file sa existe
     * @post: se construieste Repository-ul cu fisierul care are numele _file
     */
    Repository(const string& _file);

    /*
     * Getter pentru lista de studenti
     * @return: lista de studenti
     */
    vector<Student>& getStudenti();

    /*
     * Functie de adaugare a unui student
     * @param: _student -> Student
     * @post: se adauga studentul in lista de studenti
     */
    void add(const Student& _student);

    /*
     * Functie de stergere a unui student
     * @param: _id -> int
     * @pre: sa existe studentul cu id-ul primit ca parametru
     * @post: studentul cu id-ul '_id' se sterge
     * @exceptions: daca studentul cu id-ul specificat nu exista
     */
    void remove(int _id);

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
     * Functie de cautare a unui student
     * @param: _id ->int
     * @pre : sa existe studentul in lista de studenti
     * @return: studentul cu id-ul specificat
     * @exceptions: daca nu exista studentul cu id-ul specificat
     */
    Student& find(int _id);

};

#endif //PRACTIC_REPOSITORY_H
