//
// Created by culbec on 17.06.2023.
//

#ifndef MELODII_2_MODEL_H
#define MELODII_2_MODEL_H

#include <QAbstractTableModel>
#include <vector>
#include "service.h"

using std::vector;

class Model : public QAbstractTableModel {
private:
    Service& service;
public:
    Model(Service& _service): service{_service} {}

    int rowCount(const QModelIndex& parent) const override {
        return this->service.getMelodii().size();
    }

    int columnCount(const QModelIndex& parent) const override {
        return 6;
    }

    QVariant data(const QModelIndex& index, int role) const override {
        if(role == Qt::DisplayRole) {
            auto& melodie = this->service.getMelodii().at(index.row());

            switch(index.column()) {
                case 0:
                    return QString::fromStdString(std::to_string(melodie.getId()));
                case 1:
                    return QString::fromStdString(melodie.getTitlu());
                case 2:
                    return QString::fromStdString(melodie.getArtist());
                case 3:
                    return QString::fromStdString(melodie.getGen());
                case 4:
                    return QString::fromStdString(std::to_string(this->service.getArtisti()[melodie.getArtist()]));
                case 5:
                    return QString::fromStdString(std::to_string(this->service.getGenuri()[melodie.getGen()]));
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
                    return "Gen";
                case 4:
                    return "#Artisti";
                case 5:
                    return "#Gen";
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

#endif //MELODII_2_MODEL_H
