//
// Created by culbec on 16.06.2023.
//

#include "../headers/GUI.h"

GUI::GUI(Service &serv): service{serv} {
    this->service.sortMelodii();
    this->initGUI();
    this->connectSigs();
    this->notify();
}

void GUI::initGUI() {
    this->setLayout(this->mainLay);

    // table section
    this->mainLay->addWidget(this->tableGb);
    this->tableGb->setLayout(this->tableLay);

    this->tableModel = new TableModel{this->service};
    this->tableView->setModel(this->tableModel);
    this->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    this->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    this->tableLay->addWidget(this->tableView);

    this->ranksWindow = new RanksWindow{this->service};
    this->addObserver(this->ranksWindow);
    this->tableLay->addWidget(this->ranksWindow);

    // actions section
    this->mainLay->addWidget(this->actionGb);
    this->actionGb->setLayout(this->actionLay);

    // update rank section
    this->actionLay->addWidget(this->rankGb);
    this->rankGb->setLayout(this->rankLay);

    this->rankGb->setBaseSize(200, 200);
    this->rankLay->addWidget(this->rankLabel);

    this->sld->setMinimum(1);
    this->sld->setMaximum(10);
    this->sld->setTickInterval(1);
    this->sld->setOrientation(Qt::Horizontal);

    this->rankLay->addWidget(this->sldMin);
    this->rankLay->addWidget(this->sldMax);
    this->rankLay->addWidget(this->sldCurr);
    this->rankLay->addWidget(this->sld);

    // delete section
    this->actionLay->addWidget(this->deleteGb);
    this->deleteGb->setLayout(this->deleteLay);

    this->deleteLay->addWidget(this->deleteBtn);

    this->setBaseSize(1200, 800);
    this->ranksWindow->setFixedSize(500, 200);
}

void GUI::connectSigs() {
    QObject::connect(this->deleteBtn, &QPushButton::clicked, [this](){
        auto index = this->tableView->currentIndex().row();
        if(0 <= index && index < this->service.getMelodii().size()) {
            this->service.sterge(this->service.getMelodii().at(index).getId());

            // sortare
            this->service.sortMelodii();

            // update tabel
            this->tableModel->notify();

            // update linii
            this->notify();
        }
    });

    QObject::connect(this->sld, &QSlider::valueChanged, [this](){
        auto ind = this->tableView->currentIndex().row();
        if(0 <= ind && ind < this->service.getMelodii().size()) {
            this->service.updateRank(this->service.getMelodii().at(ind).getId(), this->sld->value());
            this->service.sortMelodii();
            this->tableModel->notify();
            this->notify();
            this->tableView->clearSelection();
        }
    });

    QObject::connect(this->tableView, &QTableView::clicked, [this](){
        auto ind = this->tableView->currentIndex().row();
        if(0 <= ind && ind < this->service.getMelodii().size()) {
            auto name = this->service.getMelodii().at(ind).getTitlu();
            this->rankLabel->setText(QString::fromStdString(name));
        }
    });
}
