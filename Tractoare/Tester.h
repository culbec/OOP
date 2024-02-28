//
// Created by culbec on 17.06.2023.
//

#ifndef TRACTOARE_TESTER_H
#define TRACTOARE_TESTER_H

#include <cassert>
#include "Tractor.h"
#include "Repository.h"
#include "Service.h"

class Tester {
public:
    static void testTractor();
    static void testRepo();
    static void testService();
    static void testAll();
};


#endif //TRACTOARE_TESTER_H
