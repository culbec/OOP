//
// Created by culbec on 19.06.2023.
//

#ifndef PRACTIC_STUDENT_H
#define PRACTIC_STUDENT_H

#include <string>

using std::string;

class Student {
private:
    int nrMatricol;
    string nume;
    int varsta;
    string facultate;
public:
    /*
     * Initializeaza un student
     * @param : _nrMatricol -> int
     * @param : _nume -> string
     * @param : _varsta -> int
     * @param : _facultate ->string
     * @post: se contruieste studentul cu parametrii specificati
     */
    Student(int _nrMatricol, const string& _nume, int _varsta, const string& _facultate);

    /*
     * Getter pentru numarul matricol
     * @return: numarul matricol al studentului
     */
    int getNrMatricol() const;

    /*
     * Getter pentru varsta
     * @return: varsta studentului
     */
    int getVarsta() const;

    /*
     * Setter pentru varsta
     * @param: _varsta -> int
     * @post: varsta studentului = _varsta
     */
    void setVarsta(int _varsta);

    /*
     * Getter pentru nume
     * @return: numele studentului
     */
    const string& getNume() const;

    /*
     * Getter pentru facultate
     * @return: facultatea studentului
     */
    const string& getFacultate() const;
};

#endif //PRACTIC_STUDENT_H
