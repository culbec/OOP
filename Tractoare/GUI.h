//
// Created by culbec on 17.06.2023.
//

#ifndef TRACTOARE_GUI_H
#define TRACTOARE_GUI_H

#include <QWidget>
#include <QLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTableView>
#include <QHeaderView>
#include <QMessageBox>
#include <QPainter>
#include <QMouseEvent>

#include "Model.h"
#include "Service.h"
#include <utility>

using std::pair;

class GUI : public QWidget{
private:
    Service& service;
    int left = 0;
    int right = 0;

    int tractorId = 0, tractorRoti = 0;

    QLayout* mainLay = new QHBoxLayout;

    // tabel + roti
    QLayout* tblLay = new QVBoxLayout;
    QGroupBox *tblGb = new QGroupBox{"Tabel + Roti"};

    QTableView *tableview = new QTableView;
    Model *model;

    // actions
    QLayout* actionsLay = new QVBoxLayout;
    QGroupBox *actions = new QGroupBox{"Actions"};

    // adder
    QFormLayout* adderLay = new QFormLayout;
    QGroupBox *adder = new QGroupBox{"Adder"};

    QLineEdit *idLine = new QLineEdit;
    QLineEdit *denumireLine = new QLineEdit;
    QLineEdit *tipLine = new QLineEdit;
    QLineEdit *numarRotiLine = new QLineEdit;

    QPushButton *btnAdd = new QPushButton{"&Add"};

    // combo box
    QLayout *comboLay = new QVBoxLayout;
    QGroupBox *combo = new QGroupBox{"Tipuri tractoare"};
    QComboBox *comboBox = new QComboBox;

    // internal functions

    void initGUI();

    void connectSigs();

public:
    GUI(Service& serv);

    void paintEvent(QPaintEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;

    ~GUI() override {
        delete this->model;
    }

};


#endif //TRACTOARE_GUI_H
