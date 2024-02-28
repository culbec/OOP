//
// Created by culbec on 17.06.2023.
//

#ifndef TRACTOARE_MODEL_H
#define TRACTOARE_MODEL_H

#include <QAbstractTableModel>
#include <QBrush>
#include "Tractor.h"
#include <vector>
#include <string>
#include <unordered_map>

using std::vector;
using std::unordered_map;
using std::string;

class Model : public QAbstractTableModel {
private:
    vector<Tractor> &tractoare;
    unordered_map<string, int> &tipuri;
    string checkBoxValue;
public:
    Model(vector<Tractor> &_tractoare, unordered_map<string, int>& _tipuri, const string &_checkVal);

    int rowCount(const QModelIndex &parent) const override;

    int columnCount(const QModelIndex &parent) const override;

    QVariant data(const QModelIndex &index, int role) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    void notify(const string &_checkVal);
};


#endif //TRACTOARE_MODEL_H
