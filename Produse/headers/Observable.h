#pragma once

#include "Observer.h"
#include <vector>

using std::vector;

class Observable {
protected:
    vector<Observer*> observers;

public:
    // adauga un nou observer
    virtual void addObserver(Observer* obs) {
        this->observers.push_back(obs);
    }

    // notifica toti observerii
    virtual void notify() const = 0;

    virtual ~Observable() = default;
};