#pragma once

#include "service.h"
#include "TableModel.h"
#include "Observable.h"
#include "Observer.h"

#include <QWidget>
#include <QPushButton>
#include <QLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <QSlider>
#include <QGroupBox>
#include <QTableView>
#include <QHeaderView>
#include <QMessageBox>

class GUI: public Observable, public QWidget {
private:
    Service& service;

    QLayout *mainLay = new QHBoxLayout;

    // table section
    QTableView *tblVi = new QTableView;
    TableModel *tableModel;

    // action section
    QGroupBox *actionGB = new QGroupBox{"Actions"};
    QLayout* actionLay = new QVBoxLayout;

    // add section
    QGroupBox *addGB = new QGroupBox{"Adder"};
    QFormLayout *addLay = new QFormLayout;

    QLineEdit *idLine = new QLineEdit;
    QLineEdit *numeLine = new QLineEdit;
    QLineEdit *tipLine = new QLineEdit;
    QLineEdit *pretLine = new QLineEdit;

    QPushButton *addBtn = new QPushButton{"&Add"};

    // filter section
    QGroupBox *filterGB = new QGroupBox{"Filter"};
    QVBoxLayout *filterLay = new QVBoxLayout;

    QSlider *sld = new QSlider{Qt::Horizontal};
    QLabel *sldMin = new QLabel{"Pret minim: 1"};
    QLabel *sldMax = new QLabel{"Pret maxim: 100"};
    QLabel *sldCurr = new QLabel{"Pret curent selectat: "};

    /*
     * Functie de initializare a GUI-ulu
     */
    void initGUI();

    /*
     * Conecteaza semnale la actiuni pe ferestre
     */
    void connectSigs();

public:
    /*
     * Contruieste un obiect de tip GUI
     * @param: serv -> Service
     * @details: construieste GUI-ului si conecteaza semnalele
     */
    GUI(Service& serv);

    /*
     * notifica observerii dependenti
     */
    virtual void notify() const override;

};

// clasa de fereastra pentru fiecare tip de produs in parte
class ProductWindow : public Observer, public QWidget {
private:
    QLayout *prodLay = new QHBoxLayout;
    QLabel *prodLbl = new QLabel;

public:
    // constructie fereastra
    ProductWindow(const string& tip, int num): Observer{tip, num} {
        this->setLayout(prodLay);
        this->prodLay->addWidget(this->prodLbl);

        this->setWindowTitle(QString::fromStdString(this->tipAgregat));
        this->prodLbl->setText(QString::fromStdString("Numarul de produse de tipul " + this->tipAgregat + " este: " + std::to_string(this->numberOf)));
    }

    // actualizare tip
    void update(int num) override {
        this->numberOf = num;
        this->prodLbl->setText(QString::fromStdString("Numarul de produse de tipul " + this->tipAgregat + " este: " + std::to_string(this->numberOf)));
    }
};