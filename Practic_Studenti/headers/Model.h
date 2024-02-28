//
// Created by culbec on 19.06.2023.
//

#ifndef PRACTIC_MODEL_H
#define PRACTIC_MODEL_H

#include <QAbstractTableModel>
#include <QBrush>
#include "Service.h"

class Model : public QAbstractTableModel {
private:
    Service &service; // service-ul de care este dependent
public:
    /*
     * Contruieste un model custom care mosteneste de la QAbstractTableModel
     * @param: serv -> Service
     * @post: se contruieste un model custom
     */
    Model(Service &serv) : service{serv} {}

    /*
     * Returneaza numarul de randuri pe care modelul trebuie sa le randeze
     */
    int rowCount(const QModelIndex &parent) const override {
        return this->service.getStudenti().size();
    }

    /*
     * Returneaza numarul de coloane pe care modelul trebuie sa le randeze
     */

    int columnCount(const QModelIndex &parent) const override {
        return 4;
    }

    /*
     * Returneaza data pentru fiecare element din tabel
     */
    QVariant data(const QModelIndex &index, int role) const override {
        if (role == Qt::DisplayRole) {
            const auto &stud = this->service.getStudenti().at(index.row());

            switch (index.column()) {
                case 0:
                    return QString::fromStdString(std::to_string(stud.getNrMatricol()));
                case 1:
                    return QString::fromStdString(stud.getNume());
                case 2:
                    return QString::fromStdString(std::to_string(stud.getVarsta()));
                case 3:
                    return QString::fromStdString(stud.getFacultate());
            }
        }

        if (role == Qt::BackgroundRole) {
            const auto &stud = this->service.getStudenti().at(index.row());

            if (stud.getFacultate() == "mate") {
                return QBrush{Qt::red};
            } else if (stud.getFacultate() == "info") {
                return QBrush{Qt::darkGreen};
            } else if (stud.getFacultate() == "mate-info") {
                return QBrush{Qt::blue};
            } else if (stud.getFacultate() == "ai") {
                return QBrush{Qt::black};
            }
        }

        return {};
    }

    /*
     * Determina datele pentru header
     */

    QVariant headerData(int section, Qt::Orientation orientation, int role) const override {
        if (role != Qt::DisplayRole) {
            return {};
        }

        if (orientation == Qt::Horizontal) {
            switch (section) {
                case 0:
                    return "Numar matricol";
                case 1:
                    return "Nume";
                case 2:
                    return "Varsta";
                case 3:
                    return "Facultate";
            }
        }

        return QAbstractTableModel::headerData(section, orientation, role);
    }
};

#endif //PRACTIC_MODEL_H
