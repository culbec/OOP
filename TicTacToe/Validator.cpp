//
// Created by profi on 6/18/2023.
//

#include "Validator.h"

string Validator::validateAdd(int dim, const std::string &sequence, const std::string &player) {
    string errors;

    if (dim < 3 || dim > 5) {
        errors += "Dimensiunea trebuie sa fie 3, 4 sau 5!\n";
    }

    if (player != "X" && player != "O") {
        errors += "Jucatorul poate fi doar X sau O!\n";
    }

    if (sequence.size() != dim * dim) {
        errors += "Tabla de joc nu corespunde dimensiunilor!\n";
    }

    for (const auto &ch: sequence) {
        if (ch != 'X' && ch != '-' && ch != 'O') {
            errors += "Tabla de joc trebuie sa aiba doar caracterele X, - sau O!\n";
            break;
        }
    }

    return errors;
}

string Validator::validateModif(int dim, const std::string &sequence, const std::string &player,
                                const std::string &stare) {
    string errors;

    if (dim < 3 || dim > 5) {
        errors += "Dimensiunea poate fi doar 3, 4 sau 5!\n";
    }

    if (sequence.size() != dim * dim) {
        errors += "Tabla de joc nu corespunde dimensiunilor!\n";
    }

    if (player != "X" && player != "O") {
        errors += "Jucatorul poate fi doar X sau O!\n";
    }

    if (stare != "Neinceput" && stare != "In derulare" && stare != "Terminat") {
        errors += "Stare neconforma!\n";
    }

    for (const auto &ch: sequence) {
        if (ch != 'X' && ch != '-' && ch != 'O') {
            errors += "Tabla de joc trebuie sa aiba doar caracterele X, - sau O!\n";
            break;
        }
    }

    return errors;
}
