//
// Created by profi on 6/18/2023.
//

#include "GUI.h"

GUI::GUI(Service &serv) : service{serv} {
    this->service.sortGames();
    this->model = new Model{this->service};

    this->initGUI();
    this->connectSigs();
}

void GUI::initGUI() {
    this->setLayout(this->mainLay);
    this->setFixedSize(1400, 600);

    // tabla curenta de joc
    this->mainLay->addWidget(this->gameTable);
    this->gameTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // actiunile
    this->mainLay->addWidget(this->actions);
    this->actions->setLayout(this->actionsLay);

    // adder
    this->actionsLay->addWidget(this->adder);
    this->adder->setLayout(this->adderLay);

    this->adderLay->addRow(new QLabel{"Dimensiune"}, this->dimLine);
    this->adderLay->addRow(new QLabel{"Tabla de joc"}, this->seqLine);
    this->adderLay->addRow(new QLabel{"Jucatorul curent"}, this->playerLine);
    this->adderLay->addWidget(this->addBtn);

    // modifier
    this->actionsLay->addWidget(this->modifier);
    this->modifier->setLayout(this->modifierLay);

    this->modifierLay->addRow(new QLabel{"Dimensiune"}, this->modifDim);
    this->modifierLay->addRow(new QLabel{"Tabla de joc"}, this->modifSeq);
    this->modifierLay->addRow(new QLabel{"Jucatorul curent"}, this->modifPlayer);
    this->modifierLay->addRow(new QLabel{"Stare"}, this->modifStare);
    this->modifierLay->addWidget(this->modifBtn);

    // table view
    this->actionsLay->addWidget(this->tableView);
    this->tableView->setModel(this->model);

    this->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    this->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
}

void GUI::reloadTable(Game &game) {
    this->gameTable->clearContents();

    QStringList lst;
    for (auto i = 0; i < game.getDim(); i++) {
        lst.push_back(QString::fromStdString(std::to_string(i)));
    }

    this->gameTable->setHorizontalHeaderLabels(lst);
    this->gameTable->setRowCount(game.getDim());
    this->gameTable->setColumnCount(game.getDim());

    int lineNumber = 0, col = 0;
    for (const auto &ch: game.getSequence()) {
        auto *btn = new QPushButton{QString::fromStdString(string{ch})};

        QObject::connect(btn, &QPushButton::clicked, [this, &game, btn]() {
            string newPlayer;

            if (game.getPlayer() == "X") {
                newPlayer = "O";
            } else {
                newPlayer = "X";
            }
            btn->setText(QString::fromStdString(game.getPlayer()));

            string currentSeq;
            for (auto i = 0; i < game.getDim(); i++) {
                for (auto j = 0; j < game.getDim(); j++) {
                    auto item = (QPushButton *) this->gameTable->cellWidget(i, j);
                    currentSeq.append(item->text().toStdString());
                }
            }

            if (this->service.checkEnded(game)) {
                this->service.modify(game.getId(), game.getDim(), currentSeq, newPlayer, "Terminat");
            } else {
                this->service.modify(game.getId(), game.getDim(), currentSeq, newPlayer, "In derulare");
            }

        });

        this->gameTable->setCellWidget(lineNumber, col++, btn);
        if (col == game.getDim()) {
            col = 0;
            ++lineNumber;
        }
    }
}

void GUI::connectSigs() {
    QObject::connect(this->addBtn, &QPushButton::clicked, [this]() {
        auto dim = this->dimLine->text().toInt();
        auto seq = this->seqLine->text().toStdString();
        auto player = this->playerLine->text().toStdString();

        try {
            this->service.add(dim, seq, player);
            this->model->layoutChanged();
        } catch (runtime_error &rE) {
            QMessageBox::warning(this, "Warning", QString::fromStdString(rE.what()));
        }
    });

    QObject::connect(this->modifBtn, &QPushButton::clicked, [this]() {
        auto currentGame = this->tableView->currentIndex();
        if (currentGame.row() >= 0 && currentGame.row() < this->service.getGames().size()) {

            auto id = this->service.getGames().at(currentGame.row()).getId();
            auto dim = this->modifDim->text().toInt();
            auto seq = this->modifSeq->text().toStdString();
            auto player = this->modifPlayer->text().toStdString();
            auto stare = this->modifStare->text().toStdString();

            try {
                this->service.modify(id, dim, seq, player, stare);
                this->model->layoutChanged();
            } catch (runtime_error &rE) {
                QMessageBox::warning(this, "Warning", QString::fromStdString(rE.what()));
            }
        }
    });

    QObject::connect(this->tableView->selectionModel(), &QItemSelectionModel::selectionChanged, [this]() {
        auto currentIndex = this->tableView->currentIndex();
        if (currentIndex.row() >= 0 && currentIndex.row() < this->service.getGames().size()) {
            if (this->service.getGames().at(currentIndex.row()).getStatus() != "Terminat") {
                this->reloadTable(this->service.getGames().at(currentIndex.row()));
                this->service.sortGames();
                this->model->layoutChanged();
            } else {
                this->gameTable->clearContents();
            }
        }
    });
}
