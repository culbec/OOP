//
// Created by culbec on 16.06.2023.
//

#ifndef MELODII_1_TABLEMODEL_H
#define MELODII_1_TABLEMODEL_H

#include "service.h"
#include <QAbstractTableModel>
#include <vector>

using std::vector;

class TableModel : public QAbstractTableModel {
private:
    Service& service;

public:
    TableModel(Service& serv): service{serv} {}

    int rowCount(const QModelIndex& parent) const override {
        return this->service.getMelodii().size();
    }

    int columnCount(const QModelIndex& parent) const override {
        return 5;
    }

    QVariant data(const QModelIndex& index, int role) const override {
        if(role == Qt::DisplayRole) {
            auto mel = this->service.getMelodii().at(index.row());

            switch(index.column()) {
                case 0:
                    return QString::fromStdString(std::to_string(mel.getId()));
                case 1:
                    return QString::fromStdString(mel.getTitlu());
                case 2:
                    return QString::fromStdString(mel.getArtist());
                case 3:
                    return QString::fromStdString(to_string(mel.getRank()));
                case 4:
                    return QString::fromStdString(std::to_string(this->service.getRanks()[mel.getRank()]));
                default:
                    return {};
            }
        }

        return {};
    }

    QVariant headerData(int section, Qt::Orientation orientation, int role) const override {
        if(role != Qt::DisplayRole) {
            return {};
        }

        if(orientation == Qt::Horizontal) {
            switch(section) {
                case 0:
                    return "Id";
                case 1:
                    return "Titlu";
                case 2:
                    return "Artist";
                case 3:
                    return "Rank";
                case 4:
                    return "#Same rank";
                default:
                    return {};
            }
        }

        return QAbstractTableModel::headerData(section, orientation, role);
    }

    void notify() {
        emit layoutChanged();
    }
};

#endif //MELODII_1_TABLEMODEL_H
