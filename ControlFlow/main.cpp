/*
 * main.cpp
 *
 *  Created on: 16 nov. 2020
 *      Author: Matthias
 */
#include <iostream>

int main() {
	int temperature = 18;
	if (temperature > 40) {
		std::cout << "Canicule" << std::endl;
		std::cout << "Je vais à la piscine" << std::endl;
	} else if (temperature > 20) { // <= 40
		std::cout << "Je fais du vélo" << std::endl;
	} else {  // <= 20 et <= 40
		std::cout << "Je reste au chaud" << std::endl;
	}
	std::cout << std::endl;
	// swith case sur les valeurs simples: entiers, flottants, char
	temperature = 19;
	switch (temperature) {
	case 20:
		std::cout << "Vingt sur vingt" << std::endl;
		break;
	case 19:
	case 18:
		std::cout << "18 ou 19 sur vingt" << std::endl;
		break;
	case 17:
		std::cout << "17 sur vingt" << std::endl;
		break;
	default:
		std::cout << "en dessous" << std::endl;
	}
	std::cout << std::endl;

	// loops
	int cpt = 10;
	while (cpt > 0) {
		std::cout << --cpt << " ";
	}
	std::cout << std::endl;
	do {
		std::cout << ++cpt << " ";
	} while (cpt <10);
	std::cout << std::endl;

	// old loop for
	for (int i=1; i<=10; i++) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	// compter tous les 2
	for (int i=1; i<=10; i += 2) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	// compter à l'envers
	for (int i=10; i>=1; i--) {
		std::cout << i << " ";
	}
//	std::cout << std::endl;
//	for (;;) {  // claue du milieu vaut true par défaut
//		std::cout << "In infinite loop" << std::endl;
//	}
	std::cout << std::endl;
	for (int i=1, j=10 ; i<=10; i++, --j) {
		std::cout << i << "/" << j << " ";
	}

	return 0;
}

