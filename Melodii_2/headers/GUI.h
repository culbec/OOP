//
// Created by culbec on 17.06.2023.
//

#ifndef MELODII_2_GUI_H
#define MELODII_2_GUI_H

#include <QWidget>
#include <QLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTableView>
#include <QHeaderView>
#include <QPainter>
#include <QBrush>

#include "service.h"
#include "model.h"

class GUI : public QWidget {
private:
    Service &service;

    QLayout *mainLay = new QHBoxLayout;

    // table section
    Model *model;
    QTableView *tableView = new QTableView;

    // action sections
    QGroupBox *actions = new QGroupBox{"Actions"};
    QLayout *actionsLay = new QVBoxLayout;

    // adder
    QGroupBox *adder = new QGroupBox{"Adder"};
    QFormLayout *adderLay = new QFormLayout;

    QLineEdit *titluLine = new QLineEdit;
    QLineEdit *artistLine = new QLineEdit;
    QLineEdit *genLine = new QLineEdit;

    QPushButton *btnAdd = new QPushButton{"&Add"};

    // eraser
    QGroupBox *eraser = new QGroupBox{"Eraser"};
    QLayout *eraserLay = new QVBoxLayout;

    QPushButton *btnErase = new QPushButton{"&Erase"};

    // internal methods

    void initGUI();

    void connectSigs();

public:
    GUI(Service& serv);

    void paintEvent(QPaintEvent *event) override;

    ~GUI() {
        delete this->model;
    }
};

#endif //MELODII_2_GUI_H
