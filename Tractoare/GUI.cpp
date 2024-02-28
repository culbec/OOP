//
// Created by culbec on 17.06.2023.
//

#include "GUI.h"

GUI::GUI(Service &serv) : service{serv} {
    this->service.sortTractoare();
    this->model = new Model{this->service.getTractoare(), this->service.getTipuri(), ""};

    this->initGUI();
    this->connectSigs();
}

void GUI::initGUI() {
    this->setLayout(this->mainLay);
    this->setFixedSize(1200, 600);
    this->setMouseTracking(true);

    // tabel si roti section
    this->mainLay->addWidget(this->tblGb);

    this->tblGb->setLayout(this->tblLay);
    this->tblLay->addWidget(this->tableview);

    this->tableview->setModel(this->model);
    this->tableview->setFixedSize(600, 300);
    this->tableview->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->tableview->setSelectionMode(QAbstractItemView::SingleSelection);
    this->tableview->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // actions section
    this->mainLay->addWidget(this->actions);
    this->actions->setLayout(this->actionsLay);

    // adder section
    this->actionsLay->addWidget(this->adder);

    this->adder->setLayout(this->adderLay);

    this->adderLay->addRow(new QLabel{"Id"}, this->idLine);
    this->adderLay->addRow(new QLabel{"Denumire"}, this->denumireLine);
    this->adderLay->addRow(new QLabel{"Tip"}, this->tipLine);
    this->adderLay->addRow(new QLabel{"Numar roti"}, this->numarRotiLine);
    this->adderLay->addWidget(this->btnAdd);

    // combo section
    this->actionsLay->addWidget(this->combo);
    this->combo->setLayout(this->comboLay);

    this->comboLay->addWidget(this->comboBox);

    for (const auto &tip: this->service.getTipuri()) {
        this->comboBox->addItem(QString::fromStdString(tip.first));
    }
}

void GUI::connectSigs() {
    QObject::connect(this->btnAdd, &QPushButton::clicked, [this]() {
        auto id = this->idLine->text().toInt();
        auto denumire = this->denumireLine->text().toStdString();
        auto tip = this->tipLine->text().toStdString();
        auto numarRoti = this->numarRotiLine->text().toInt();

        try {
            this->service.add(id, denumire, tip, numarRoti);
            this->service.sortTractoare();
            this->model->notify("");
        } catch (runtime_error &rE) {
            QMessageBox::warning(this, "Warning", QString::fromStdString(string{rE.what()}));
        }
    });

    QObject::connect(this->comboBox, &QComboBox::currentTextChanged, [this]() {
        this->model->notify(this->comboBox->currentText().toStdString());
    });

    QObject::connect(this->tableview, &QTableView::pressed, [this]() {
        auto index = this->tableview->currentIndex().row();

        if (0 <= index && index < this->service.getTractoare().size()) {
            this->repaint();
        }
    });
}

void GUI::paintEvent(QPaintEvent *event) {
    if (this->tableview->currentIndex().row() < 0 ||
        this->tableview->currentIndex().row() >= this->service.getTractoare().size()) {
        return;
    }

    QPainter painter{this};
    int currW = 40;
    this->right = currW;
    auto tractorModif = this->service.getTractoare().at(this->tableview->currentIndex().row());

    this->tractorId = tractorModif.getId();
    this->tractorRoti = tractorModif.getNumarRoti();

    for (int i = 0; i < tractorModif.getNumarRoti(); i++) {

        painter.drawEllipse(QPointF(currW, this->tblGb->height() - 40), 10, 10);

        currW += 30;
        this->right = currW;
    }
}

void GUI::mousePressEvent(QMouseEvent *event) {
    int xPos = event->pos().x();
    int yPos = event->pos().y();

    if (left <= xPos && xPos <= right && this->height() - 80 <= yPos - 10 && yPos + 10 <= this->height()) {
        this->service.update(tractorId, tractorRoti - 2);
        this->model->notify("");
        this->repaint();
    }

}

