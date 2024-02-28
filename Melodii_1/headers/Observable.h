//
// Created by culbec on 16.06.2023.
//

#ifndef MELODII_1_OBSERVABLE_H
#define MELODII_1_OBSERVABLE_H

#include "Observer.h"
#include <vector>

using std::vector;

class Observable {
private:
    vector<Observer*> observers;

public:

    virtual void addObserver(Observer* obs) {
        this->observers.push_back(obs);
    }

    virtual void notify() const {
        for(auto& obs: this->observers) {
            obs->update();
        }
    }

};

#endif //MELODII_1_OBSERVABLE_H
