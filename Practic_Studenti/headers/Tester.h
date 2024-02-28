//
// Created by culbec on 19.06.2023.
//

#ifndef PRACTIC_TESTER_H
#define PRACTIC_TESTER_H

#include <cassert>
#include "Student.h"
#include "Repository.h"
#include "Service.h"

class Tester {
public:
        /*
         * Functie de teste pentru entitate
         */
        static void testStudent();

        /*
         * Functie de teste pentru repository
         */
        static void testRepository();

        /*
         * Functie de teste pentru service
         */
        static void testService();

        /*
         * Functie de teste pentru toate testele
         */
        static void testAll();
};

#endif //PRACTIC_TESTER_H
