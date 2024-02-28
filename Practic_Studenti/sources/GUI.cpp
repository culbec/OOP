//
// Created by culbec on 19.06.2023.
//

#include "../headers/GUI.h"

GUI::GUI(Service &serv) : service{serv} {
    this->service.sortStudenti();

    this->model = new Model{this->service};
    this->initGUI();
    this->connectSigs();
    this->toErase.clear();
}

void GUI::initGUI() {
    this->setLayout(this->mainLay);

    // table section
    this->mainLay->addWidget(this->tableView);

    this->tableView->setModel(this->model);
    this->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    this->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    // actions
    this->mainLay->addWidget(this->actions);
    this->actions->setLayout(this->actionsLay);

    // modifiers
    this->actionsLay->addWidget(this->modify);
    this->modify->setLayout(this->modifyLay);

    this->modifyLay->addWidget(this->intinerire);
    this->modifyLay->addWidget(this->imbatranire);
    this->modifyLay->addWidget(this->sterge);

    // undo & redo
    this->actionsLay->addWidget(this->undoRedo);
    this->undoRedo->setLayout(this->undoRedoLay);

    this->undoRedoLay->addWidget(this->undo);
    this->undoRedoLay->addWidget(this->redo);
}

void GUI::connectSigs() {
    QObject::connect(this->tableView->selectionModel(), &QItemSelectionModel::selectionChanged, [this]() {
        this->toErase.clear();
        for(auto& item : this->tableView->selectionModel()->selectedRows()) {
            this->toErase.push_back(this->service.getStudenti().at(item.row()));
        }
    });

    QObject::connect(this->intinerire, &QPushButton::clicked, [this]() {
        if (this->tableView->selectionModel()->isSelected(this->tableView->currentIndex())) {
            auto &stud = this->service.getStudenti().at(this->tableView->currentIndex().row());

            try {
                this->service.modify(stud.getNrMatricol(), stud.getVarsta() - 1);
                this->service.sortStudenti();
                this->model->layoutChanged();
            } catch (runtime_error &rE) {
                QMessageBox::warning(this, "Warning", QString::fromStdString(string{rE.what()}));
            }
        }
    });

    QObject::connect(this->imbatranire, &QPushButton::clicked, [this]() {
        if (this->tableView->selectionModel()->isSelected(this->tableView->currentIndex())) {
            auto &stud = this->service.getStudenti().at(this->tableView->currentIndex().row());

            try {
                this->service.modify(stud.getNrMatricol(), stud.getVarsta() + 1);
                this->service.sortStudenti();
                this->model->layoutChanged();
            } catch (runtime_error &rE) {
                QMessageBox::warning(this, "Warning", QString::fromStdString(string{rE.what()}));
            }
        }
    });

    QObject::connect(this->sterge, &QPushButton::clicked, [this]() {
        if (this->toErase.empty()) {
            QMessageBox::warning(this, "Warning", "Lista de studenti pentru sters este goala!");
            return;
        }

        for(auto& student: this->toErase) {
            try {
                this->service.remove(student);
                this->tableView->clearSelection();
                this->toErase.clear();
                this->service.sortStudenti();
                this->model->layoutChanged();
            } catch (runtime_error &rE) {
                QMessageBox::warning(this, "Warning", QString::fromStdString(string{rE.what()}));
            }
        }
    });

    QObject::connect(this->undo, &QPushButton::clicked, [this]() {
        try {
            this->service.undo();
            this->service.sortStudenti();
            this->model->layoutChanged();
        } catch (runtime_error &rE) {
            QMessageBox::warning(this, "Warning", QString::fromStdString(string{rE.what()}));
        }

    });

    QObject::connect(this->redo, &QPushButton::clicked, [this]() {
        try {
            this->service.redo();
            this->service.sortStudenti();
            this->model->layoutChanged();
        } catch (runtime_error &rE) {
            QMessageBox::warning(this, "Warning", QString::fromStdString(string{rE.what()}));
        }
    });
}

GUI::~GUI() {
    delete this->model;
}