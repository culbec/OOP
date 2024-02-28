#pragma once

#include <QAbstractTableModel>
#include <QBrush>
#include <vector>

using std::vector;

class TableModel : public QAbstractTableModel {
private:
    vector<Produs> produse;
    int sldValue = 0;

public:
    /*
     * Contruieste un table model
     * @param prod: lista de produse de care este dependent
     * @param sldVal: valoare de pe slider de care este dependent
     */
    TableModel(vector<Produs>& prod, int sldVal): produse{prod}, sldValue{sldVal} {}

    /*
     * Returneaza numarul de linii ale tabelului
     */
    int rowCount(const QModelIndex &parent) const override {
        return this->produse.size();
    }

    /*
     * Returneaza numarul de coloane ale tabelului
     */
    int columnCount(const QModelIndex &parent) const override {
        return 5;
    }

    /*
     * Returneaza informatia relevanta ce trebuie actualizata in tabel
     */
    QVariant data(const QModelIndex &index, int role) const override {
        if(role == Qt::DisplayRole) {
            auto produs = this->produse.at(index.row());

            switch(index.column()) {
                case 0:
                    return QString::fromStdString(std::to_string(produs.getId()));
                case 1:
                    return QString::fromStdString(produs.getNume());
                case 2:
                    return QString::fromStdString(produs.getTip());
                case 3:
                    return QString::fromStdString(std::to_string(produs.getPret()));
                case 4:
                    return QString::fromStdString(std::to_string(produs.getVowels()));
                default:
                    return {};
            }
        }

        if(role == Qt::BackgroundRole) {
            if(sldValue == 50) {
                auto prod = this->produse.at(index.row());
                if(prod.getPret() <= 50.0) {
                    return QBrush{Qt::red};
                }
            }
            return QBrush{Qt::transparent};
        }
        return {};
    }


    /*
     * Actualizeaza header-ul tabelului
     */
    QVariant headerData(int section, Qt::Orientation orientation, int role) const {
        if(role != Qt::DisplayRole) {
            return {};
        }

        if(orientation == Qt::Horizontal) {
            switch (section) {
                case 0:
                    return "Id";
                case 1:
                    return "Nume";
                case 2:
                    return "Tip";
                case 3:
                    return "Pret";
                case 4:
                    return "Numar vocale";
                default:
                    return {};

            }
        }


        return QAbstractTableModel::headerData(section, orientation, role);
    }

    /*
     * Notifica tabelul de schimbari
     */
    void notify(vector<Produs>& _produse, int _sldVal) {
        this->produse = _produse;
        this->sldValue = _sldVal;

        emit layoutChanged();
    }
};