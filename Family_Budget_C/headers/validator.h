//
// Created by culbec on 3/12/23.
//
#pragma once

#include "domain.h"
#include "repo.h"
#include "utils.h"


    /*
     * Valideaza o cheltuiala.
     * @ptr_cheltuiala: pointer spre o Cheltuiala
     * @ptr_repo_cheltuieli: pointer spre repo-ul de cheltuieli
     * @pre: - ptr_cheltuiala -> pointer spre o cheltuiala
     *       - ptr_repo_cheltuieli -> pointer spre un RepoCheltuieli
     * @post: - 0: obiect invalid;
     *        - 1: obiect valid;
     *        - 2: obiect se afla deja in lista de cheltuieli
     */
int validareObiect(Cheltuiala*, ListaCheltuieli*);
