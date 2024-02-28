//
// Created by profi on 6/18/2023.
//

#ifndef TICTACTOE_GUI_H
#define TICTACTOE_GUI_H

#include "Service.h"
#include "Model.h"

#include <QWidget>
#include <QLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QTableView>
#include <QItemSelectionModel>
#include <QGroupBox>
#include <QTableWidget>
#include <QLabel>
#include <QHeaderView>
#include <QMessageBox>

class GUI : public QWidget {
private:
    Service &service;

    QLayout *mainLay = new QHBoxLayout;

    // tabla de joc
    QTableWidget *gameTable = new QTableWidget;

    // actions
    QGroupBox *actions = new QGroupBox{"Actions"};
    QLayout *actionsLay = new QVBoxLayout;

    // adder
    QGroupBox *adder = new QGroupBox{"Adder"};
    QFormLayout *adderLay = new QFormLayout;

    QLineEdit *dimLine = new QLineEdit;
    QLineEdit *seqLine = new QLineEdit;
    QLineEdit *playerLine = new QLineEdit;
    QPushButton *addBtn = new QPushButton{"&Add"};

    // modifier
    QGroupBox *modifier = new QGroupBox{"Modifier"};
    QFormLayout *modifierLay = new QFormLayout;

    QLineEdit *modifDim = new QLineEdit;
    QLineEdit *modifSeq = new QLineEdit;
    QLineEdit *modifPlayer = new QLineEdit;
    QLineEdit *modifStare = new QLineEdit;
    QPushButton *modifBtn = new QPushButton{"&Modify"};

    // table view cu toate jocurile
    Model *model;
    QTableView *tableView = new QTableView;

    void initGUI();

    void connectSigs();

    void reloadTable(Game &game);

public:
    GUI(Service &serv);

    ~GUI() {
        delete this->model;
    }
};


#endif //TICTACTOE_GUI_H
