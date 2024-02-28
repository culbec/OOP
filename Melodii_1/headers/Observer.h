//
// Created by culbec on 16.06.2023.
//

#ifndef MELODII_1_OBSERVER_H
#define MELODII_1_OBSERVER_H

class Observer {
public:
    virtual void update() = 0;
    virtual ~Observer() = default;
};

#endif //MELODII_1_OBSERVER_H
