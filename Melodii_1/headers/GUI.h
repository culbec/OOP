//
// Created by culbec on 16.06.2023.
//

#ifndef MELODII_1_GUI_H
#define MELODII_1_GUI_H

#include "Observer.h"
#include "Observable.h"
#include "TableModel.h"
#include "service.h"

#include <QWidget>
#include <QLayout>
#include <QGroupBox>

#include <QTableView>
#include <QSlider>
#include <QLabel>
#include <QPushButton>

#include <QHeaderView>
#include <QPainter>
#include <QBrush>

class RanksWindow : public Observer, public QWidget {
private:
    Service& service;
    QLayout *ranksLay = new QHBoxLayout;
public:
    RanksWindow(Service& serv): service{serv} {}

    void paintEvent(QPaintEvent *event) override {
        QPainter painter{this};
        painter.setBrush(QBrush{Qt::red});

        int currentW = 10;

        for(int i = 1; i <= 10; i++) {
            if(this->service.getRanks()[i] == 0) {
                painter.drawRect(currentW, this->height(), 30, -1);
            } else {
                painter.drawRect(currentW, this->height(), 30, -5 * this->service.getRanks()[i]);
            }
            currentW+=50;
        }
    }

    void update() override {
        this->repaint();
    }

};

class GUI : public Observable, public QWidget {
private:
    Service& service;

    QLayout *mainLay = new QHBoxLayout;

    // table section + ranks widget
    QGroupBox *tableGb = new QGroupBox{"Table + Ranks"};
    QLayout *tableLay = new QVBoxLayout;

    TableModel *tableModel;
    QTableView *tableView = new QTableView;

    RanksWindow *ranksWindow;

    // actions section
    QGroupBox *actionGb = new QGroupBox{"Actions"};
    QLayout *actionLay = new QVBoxLayout;

    // rank update section
    QGroupBox *rankGb = new QGroupBox{"Ranks update"};
    QLayout *rankLay = new QVBoxLayout;

    QLabel *rankLabel = new QLabel;

    QLabel *sldMin = new QLabel{"Rank minim: 1"};
    QLabel *sldMax = new QLabel{"Rank maxim: 10"};
    QLabel *sldCurr = new QLabel{"Rank selectat: "};
    QSlider *sld = new QSlider;

    // delete section
    QGroupBox *deleteGb = new QGroupBox{"Delete section"};
    QLayout *deleteLay = new QVBoxLayout;
    QPushButton *deleteBtn = new QPushButton{"&Delete"};

    void initGUI();
    void connectSigs();

public:
    GUI(Service& serv);

    ~GUI() override {
        delete tableModel;
        delete ranksWindow;
    }

};


#endif //MELODII_1_GUI_H
