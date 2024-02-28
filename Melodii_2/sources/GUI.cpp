//
// Created by culbec on 17.06.2023.
//

#include "../headers/GUI.h"

GUI::GUI(Service &serv) : service{serv} {
    this->service.sortMelodii();
    this->model = new Model{this->service};
    this->initGUI();
    this->connectSigs();
    this->repaint();
}

void GUI::initGUI() {
    this->setLayout(this->mainLay);
    this->setFixedSize(1000, 500);

    // table section
    this->mainLay->addWidget(this->tableView);
    this->tableView->setFixedSize(500, 300);
    this->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->tableView->setModel(this->model);
    this->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // actions
    this->mainLay->addWidget(this->actions);
    this->actions->setLayout(this->actionsLay);
    this->actions->setFixedSize(400, 300);

    // adder
    this->actionsLay->addWidget(this->adder);
    this->adder->setLayout(this->adderLay);

    this->adderLay->addRow(new QLabel{"Titlu"}, this->titluLine);
    this->adderLay->addRow(new QLabel{"Artist"}, this->artistLine);
    this->adderLay->addRow(new QLabel{"Gen"}, this->genLine);
    this->adderLay->addWidget(this->btnAdd);

    // eraser
    this->actionsLay->addWidget(this->eraser);
    this->eraser->setLayout(this->eraserLay);

    this->eraserLay->addWidget(this->btnErase);
}

void GUI::connectSigs() {
    QObject::connect(this->btnAdd, &QPushButton::clicked, [this]() {
        auto _titlu = this->titluLine->text().toStdString();
        auto _artist = this->artistLine->text().toStdString();
        auto _gen = this->genLine->text().toStdString();

        if (!_titlu.empty() && !_artist.empty()) {
            if (_gen == "Pop" || _gen == "Rock" || _gen == "Folk" || _gen == "Disco") {
                this->service.add(_titlu, _artist, _gen);
                this->model->notify();
                this->repaint();
            }
        }
    });

    QObject::connect(this->btnErase, &QPushButton::clicked, [this]() {
        auto currentIndex = this->tableView->currentIndex();
        if (currentIndex.isValid()) {
            this->service.sterge(this->service.getMelodii().at(currentIndex.row()));
            this->service.sortMelodii();
            this->model->notify();
            this->repaint();
        }
    });
}

void GUI::paintEvent(QPaintEvent *event) {
    QPainter painter{this};

    QPointF pop(30, 30);
    QPointF rock(30, this->height() - 30);
    QPointF folk(this->width() - 30, 30);
    QPointF disco(this->width() - 30, this->height() - 30);

    for (const auto &gen: this->service.getGenuri()) {
        if (gen.first == "Pop") {
            painter.setPen(Qt::red);

            int rad = 4;

            for (int i = 0; i < gen.second; i++) {
                painter.drawEllipse(pop, rad, rad);
                rad += 2;

            }
        } else if (gen.first == "Rock") {
            painter.setPen(Qt::green);

            int rad = 4;

            for (int i = 0; i < gen.second; i++) {
                painter.drawEllipse(rock, rad, rad);
                rad += 2;
            }
        } else if (gen.first == "Folk") {
            painter.setPen(Qt::cyan);

            int rad = 4;

            for (int i = 0; i < gen.second; i++) {
                painter.drawEllipse(folk, rad, rad);
                rad += 2;
            }
        } else if (gen.first == "Disco") {
            painter.setPen(Qt::yellow);

            int rad = 4;

            for (int i = 0; i < gen.second; i++) {
                painter.drawEllipse(disco, rad, rad);
                rad += 2;
            }
        }
    }
}
