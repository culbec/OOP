//
// Created by culbec on 17.06.2023.
//

#include "Model.h"

Model::Model(vector<Tractor> &_tractoare, unordered_map<string, int> &_tipuri, const std::string &_checkVal)
        : tractoare{_tractoare},
          tipuri{_tipuri},
          checkBoxValue{_checkVal} {}

int Model::rowCount(const QModelIndex &parent) const {
    return this->tractoare.size();
}

int Model::columnCount(const QModelIndex &parent) const {
    return 5;
}

QVariant Model::data(const QModelIndex &index, int role) const {
    auto &tractor = this->tractoare.at(index.row());

    if (role == Qt::DisplayRole) {
        switch (index.column()) {
            case 0:
                return QString::fromStdString(std::to_string(tractor.getId()));
            case 1:
                return QString::fromStdString(tractor.getDenumire());
            case 2:
                return QString::fromStdString(tractor.getTip());
            case 3:
                return QString::fromStdString(std::to_string(tractor.getNumarRoti()));
            case 4:
                return QString::fromStdString(std::to_string(this->tipuri[tractor.getTip()]));
            default:
                return {};
        }
    }

    if (role == Qt::BackgroundRole) {
        if (tractor.getTip() == this->checkBoxValue) {
            return QBrush{Qt::red};
        } else {
            return QBrush{Qt::transparent};
        }
    }

    return {};
}

QVariant Model::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole) {
        return {};
    }

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return "Id";
            case 1:
                return "Denumire";
            case 2:
                return "Tip";
            case 3:
                return "Numar roti";
            case 4:
                return "#Tip";
            default:
                return {};
        }
    }

    return QAbstractTableModel::headerData(section, orientation, role);
}

void Model::notify(const std::string &_checkVal) {
    this->checkBoxValue = _checkVal;
    emit layoutChanged();
}