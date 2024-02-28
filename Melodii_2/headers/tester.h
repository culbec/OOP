//
// Created by culbec on 17.06.2023.
//

#ifndef MELODII_2_TESTER_H
#define MELODII_2_TESTER_H

#include <cassert>
#include "melodie.h"
#include "repo.h"
#include "service.h"

class Tester {
public:
    static void testMelodie();

    static void testRepo();

    static void testService();

    static void testAll();
};

#endif //MELODII_2_TESTER_H
