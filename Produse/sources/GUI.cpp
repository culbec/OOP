#include "../headers/GUI.h"

GUI::GUI(Service &serv): service{serv} {
    this->tableModel = new TableModel{serv.getProduse(), 1};
    this->initGUI();
    this->connectSigs();
}

void GUI::initGUI() {
    this->setLayout(this->mainLay);

    // table section
    this->tblVi->setModel(this->tableModel);
    this->mainLay->addWidget(this->tblVi);
    this->tblVi->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // commands section
    this->actionGB->setLayout(this->actionLay);
    this->mainLay->addWidget(this->actionGB);

    // add section
    this->actionLay->addWidget(this->addGB);
    this->addGB->setLayout(this->addLay);

    this->addLay->addRow(new QLabel{"Id"}, this->idLine);
    this->addLay->addRow(new QLabel{"Nume"}, this->numeLine);
    this->addLay->addRow(new QLabel{"Tip"}, this->tipLine);
    this->addLay->addRow(new QLabel{"Pret"}, this->pretLine);
    this->addLay->addWidget(this->addBtn);

    // filter section
    this->actionLay->addWidget(this->filterGB);
    this->filterGB->setLayout(this->filterLay);

    this->filterLay->addWidget(this->sldMin);
    this->filterLay->addWidget(this->sldMax);
    this->filterLay->addWidget(this->sldCurr);

    this->sld->setMinimum(1);
    this->sld->setMaximum(100);
    this->sld->setTickInterval(1);
    this->filterLay->addWidget(this->sld);

    // creating new windows for every type of product
    for(const auto& elem: this->service.getTipuri()) {
        auto productWindow = new ProductWindow{elem.first, elem.second};
        productWindow->show();
        this->addObserver(productWindow);
    }
}

void GUI::connectSigs() {
    QObject::connect(this->addBtn, &QPushButton::clicked, [this](){
        auto id = this->idLine->text().toInt();
        auto nume = this->numeLine->text().toStdString();
        auto tip = this->tipLine->text().toStdString();
        auto pret = this->pretLine->text().toDouble();

        try {
            this->service.add(id, nume, tip, pret);
            this->tableModel->notify(this->service.getProduse(), this->sld->value());
            this->notify();
        } catch (runtime_error& rE) {
            QMessageBox::warning(this, "Warning", QString::fromStdString(string{rE.what()}));
        }
    });

    QObject::connect(this->sld, &QSlider::valueChanged, [this](){
        vector<Produs> filtered = this->service.filter(this->sld->value());
        this->tableModel->notify(filtered, this->sld->value());

        this->sldCurr->setText(QString::fromStdString("Pret curent selectat: " + std::to_string(this->sld->value())));
    });
}

void GUI::notify() const {
    for(const auto& obs: this->observers) {
        obs->update(this->service.getTipuri()[obs->getTip()]);
    }
}