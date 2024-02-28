//
// Created by culbec on 3/12/23.
//
#pragma once

#include <stdio.h>
#include "service.h"

typedef struct {
	ServiceCheltuieli* serviceCheltuieli;
}UI;


	/*
	 * Creeaza un UI
	 * @pre: -
	 * @post: se initialiaza un UI
	*/

UI* creeazaUi();

	/*
     * Distruge UI-ul
	 * @pre: UI* indica spre un UI valid
	 * @post: UI-ul este distrus cu totul (service + repo)
	*/

void distrugeUi(UI*);

	/*
	 * Afiseaza cheltuielile intr-un anumit state.
	 * @pre: UI* indica spre un UI valid
	 * @post: sunt afisate cheltuielile sau un mesaj de atentionare ca nu exista
	*/

void uiAfiseazaCheltuieli(ListaCheltuieli*);

	/*
	 * Adauga o cheltuiala in lista de cheltuieli - prompt de la utilizator
	 * @pre: UI* indica spre un UI valid
	 * @post: se adauga cheltuiala sau se afiseaza un mesaj de eroare in caz ca
	 *		  nu s-a putut efectua operatia
	*/

void uiAdaugareCheltuiala(UI*);

	/*
	 * Modifica o cheltuiala din lista de cheltuieli - prompt de la utilizator
	 * @pre: UI* indica spre un UI valid
	 * @post: se modifica cheltuiala sau se afiseaza un mesaj de eroare in caz ca
	 *		  nu s-a putut efectua operatia
	*/

void uiModificareCheltuiala(UI*);

	/*
	 * Sterge o cheltuiala din lista de cheltuieli - prompt de la utilizator
	 * @pre: UI* indica spre un UI valid
	 * @post: se sterge cheltuiala sau se afiseaza un mesaj de eroare in caz ca
	 *		  nu s-a putut efectua operatia
	*/

void uiStergeCheltuiala(UI*);


	/*
	 * Filtreaza lista de cheltuieli in functie de un parametru
	 * @pre: UI* indica un UI valid
	 * @post: lista filtrata dupa un parametru
	*/

void uiFiltrare(UI*);

	/*
	 * Ordoneaza (crescator/descrescator) lista de cheltuieli in functie de un parametru
	 * @pre: UI* indica un UI valid
	 * @post: lista ordonata dupa un parametru
	*/

void uiOrdonare(UI*);

	/*
	 * Ruleaza aplicatia
	 * @pre: -
	 * @post: -
	*/

void showUi();