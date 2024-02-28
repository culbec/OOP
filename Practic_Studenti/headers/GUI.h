//
// Created by culbec on 19.06.2023.
//

#ifndef PRACTIC_GUI_H
#define PRACTIC_GUI_H

#include "Service.h"
#include "Model.h"

#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QTableView>
#include <QHeaderView>
#include <QItemSelectionModel>
#include <QMessageBox>

class GUI : public QWidget {
private:
    Service& service; // service-ul de care este dependent

    /*
     * Studentii curenti selectati pentru stergere
     */
    vector<Student> toErase;

    // layout principal
    QLayout *mainLay = new QHBoxLayout;

    // partea de vizualizare studenti
    Model* model;
    QTableView *tableView = new QTableView;

    // grupare a actiunilor
    QGroupBox *actions = new QGroupBox{"Actions"};
    QLayout *actionsLay = new QVBoxLayout;

    // actiuni ce modifica studentii si lista de studenti
    QGroupBox *modify = new QGroupBox{"Modifiers"};
    QLayout *modifyLay = new QHBoxLayout;

    QPushButton *intinerire = new QPushButton{"Intinerire"};
    QPushButton *imbatranire = new QPushButton{"Imbatranire"};
    QPushButton *sterge = new QPushButton{"Sterge"};

    // actiunile de undo & redo
    QGroupBox *undoRedo = new QGroupBox{"Undo & Redo"};
    QLayout *undoRedoLay = new QHBoxLayout;

    QPushButton *undo = new QPushButton{"Undo"};
    QPushButton *redo = new QPushButton{"Redo"};

    /*
     * Initializeaza fereastra principala
     */
    void initGUI();

    /*
     * Conecteaza semnalele
     */
    void connectSigs();

public:
    /*
     * Creeaza un obiect de tip GUI (o noua fereastra)
     * @param: serv -> Service
     * @post: se contruieste un nou QWidget
     */
    GUI(Service& serv);

    ~GUI() override;
};

#endif //PRACTIC_GUI_H
