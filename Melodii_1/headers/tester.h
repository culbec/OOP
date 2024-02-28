//
// Created by culbec on 16.06.2023.
//

#ifndef MELODII_1_TESTER_H
#define MELODII_1_TESTER_H

#include <cassert>
#include "melodie.h"
#include "repository.h"
#include "service.h"

class Tester {
public:
    void testMelodie();
    void testRepo();
    void testService();
    void testAll();
};

#endif //MELODII_1_TESTER_H
