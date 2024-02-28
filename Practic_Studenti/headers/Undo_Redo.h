//
// Created by culbec on 19.06.2023.
//

#ifndef PRACTIC_UNDO_REDO_H
#define PRACTIC_UNDO_REDO_H

#include "Student.h"
#include "Repository.h"
#include <vector>

using std::vector;

// clasa abstracta -> de aici mostenesc toate actiunile
class Undo {
public:
    Undo() = default;

    /*
     * Metoda pur virtuala implementata de fiecare actiune in parte
     */
    virtual void undo() = 0;

    virtual ~Undo() = default;
};

class UndoImbatranire : public Undo {
private:
    Student& student;
public:
    /*
     * Construieste o actiune undo care va intineri studentul
     * @param: stud -> Student
     */
    UndoImbatranire(Student& stud);

    /*
     * Se intinereste studentul asignat
     * @pre: studentul imbatranit
     * @post: student.varsta = student.varsta - 1
     */
    void undo() override;
};

class UndoIntinerire : public Undo {
private:
    Student& student;
public:
    /*
     * Construieste o actiune undo care va imbatrani studentul
     * @param: stud -> Student
     */
    UndoIntinerire(Student& stud);

    /*
     * Se imbatraneste studentul asignat
     * @pre: studentul intinerit
     * @post: student.varsta = student.varsta + 1
     */
    void undo() override;
};

class UndoStergere : public Undo {
private:
    Student student;
    Repository& repository;
public:
    /*
     * Contruieste o actiune undo care poate readauga un student in lista de studenti
     * @param: stud -> Student
     * @param: repo -> Repository
     * @post: se contruieste studentul
     */
    UndoStergere(const Student& stud, Repository& repo);

    /*
     * Se readauga studentul asignat
     * @pre: -
     * @post: studentul este readaugat in lista de studenti
     */
    void undo() override;
};

// clasa abstracta -> de aici mostenesc toate actiunile
class Redo {
public:
    Redo() = default;

    /*
     * Metoda pur virtuala implementata de fiecare actiune in parte
     */
    virtual void redo() = 0;

    virtual ~Redo() = default;
};

class RedoImbatranire : public Redo {
private:
    Student& student;
public:
    /*
     * Contruieste o actiune care poate reintineri un student
     * @param: stud -> Student
     * @post: se contruieste un obiect de acest tip cu stud asignat
     */
    RedoImbatranire(Student& stud);

    /*
     * Reimbatraneste studentul
     * @pre: student imbatranit
     * @post: student.varsta = student.varsta - 1;
     */
    void redo() override;
};

class RedoIntinerire : public Redo {
private:
    Student& student;
public:
    /*
     * Contruieste o actiune care poate reimbatrani un student
     * @param: stud -> Student
     * @post: se contruieste un obiect de acest tip cu stud asignat
     */
    RedoIntinerire(Student& stud);

    /*
     * Reintinereste studentul
     * @pre: student intinerit
     * @post: student.varsta = student.varsta + 1;
     */
    void redo() override;
};

class RedoStergere : public Redo {
private:
    Student student;
    Repository& repository;
public:
    /*
     * Contruieste o actiune care poate readauga un student
     * @param: stud -> Student
     * @param: repo -> Repository
     * @post: se contruieste un obiect de acest tip cu stud si repo asignate
     */
    RedoStergere(const Student& stud, Repository& repo);

    /*
     * Resterge un student din lista
     * @pre: studentul este sters
     * @post: studentul este readaugat in lista
     */
    void redo() override;
};

#endif //PRACTIC_UNDO_REDO_H
