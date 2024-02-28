//
// Created by profi on 6/18/2023.
//

#ifndef TICTACTOE_MODEL_H
#define TICTACTOE_MODEL_H

#include <QAbstractTableModel>
#include "Service.h"

class Model : public QAbstractTableModel {
private:
    Service &service;
public:
    Model(Service &serv) : service{serv} {}

    int rowCount(const QModelIndex &parent) const override {
        return this->service.getGames().size();
    }

    int columnCount(const QModelIndex &parent) const override {
        return 5;
    }

    QVariant data(const QModelIndex &index, int role) const override {
        if (role == Qt::DisplayRole) {
            auto game = this->service.getGames().at(index.row());

            switch (index.column()) {
                case 0:
                    return QString::fromStdString(std::to_string(game.getId()));
                case 1:
                    return QString::fromStdString(std::to_string(game.getDim()));
                case 2:
                    return QString::fromStdString(game.getSequence());
                case 3:
                    return QString::fromStdString(game.getPlayer());
                case 4:
                    return QString::fromStdString(game.getStatus());
                default:
                    return {};
            }
        }
        return {};
    }

    QVariant headerData(int section, Qt::Orientation orientation, int role) const override {
        if (role != Qt::DisplayRole) {
            return {};
        }

        if (orientation == Qt::Horizontal) {
            switch (section) {
                case 0:
                    return "Id";
                case 1:
                    return "Dimensiune";
                case 2:
                    return "Tabla de joc";
                case 3:
                    return "Urmatorul jucator";
                case 4:
                    return "Status";
            }
        }
        return QAbstractTableModel::headerData(section, orientation, role);
    }
};


#endif //TICTACTOE_MODEL_H
