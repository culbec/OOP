#pragma once

#include <stdbool.h>
#include "./domain.h"
#include "./repo.h"



typedef int(*compareMethod)(Cheltuiala*, Cheltuiala*); // pointer catre functie de comparare
typedef ListaCheltuieli* (*filterMethod)(ListaCheltuieli*, void*); // pointer catre functie de filtrare

	/*
	 * Interschimba doua cheltuieli
	 * @pre: Cheltuiala* indica spre o cheltuiala valida
	 * @post: cheltuielile se vor interschimba
	*/
void swap(Cheltuiala**, Cheltuiala**);

	/*
	 * Functi de comparare.
	 * @pre: Cheltuiala* indica spre cheltuieli valida
	 * @post: - 1: prima cheltuiala este mai mare
	 *		  - 0: cheltuieli egale
	 *		  - -1: a doua cheltuiala este mai mare
	*/

int compareZi(Cheltuiala*, Cheltuiala*);

int compareTip(Cheltuiala*, Cheltuiala*);

int compareSuma(Cheltuiala*, Cheltuiala*);

	/*
	 * Functie de sortare prin selectie directa
	 * @pre: ListaCheltuieli* indica o lista de cheltuieli
	 *		 bool indica sensul de ordonare
	 *		 compareMethod reprezinta functia de comparare
	 * @post: lista de cheltuieli sortata in functie de sensul de ordonare
	*/
void selectionSort(ListaCheltuieli*, bool, compareMethod);

//ListaCheltuieli* filtrareZi(ListaCheltuieli*, int);
//
//ListaCheltuieli* filtrareSuma(ListaCheltuieli*, double);
//
//ListaCheltuieli* filtrareTip(ListaCheltuieli*, char*);