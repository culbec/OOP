#pragma once

#include "produs.h"
#include "repo.h"
#include "service.h"
#include <cassert>

// clasa de teste - se subintelege ce face
class Tester {
public:
    void testProdus();
    void testRepo();
    void testService();

    void testAll();
};