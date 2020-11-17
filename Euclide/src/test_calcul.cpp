/*
 * test_calcul.cpp
 *
 *  Created on: 17 nov. 2020
 *      Author: Matthias
 */
#include <iostream>

#include "test_calcul.h"
#include "calcul.h"

void testGcd() {
	int a = 21;
	int b = 15;
	int g;
	// appel de la fonction gcd avec
	// passage de paramètres par copie
	// et valeur par copie
	g = gcd(a, b);
	std::cout << "Gcd of " << a << " and " << b << " = " << g << std::endl;
}

void testFibonacci(){
	int n=6;
	uint64_t f = fibo(n);
	// fibo(6) => fibo(4) (=> fibo(2) et fibo(3) ...)
	//			et fibo(5) (=> fibo(3) et fibo(4))
	std::cout << "Fibo(" << n << ")=" << f << std::endl;
}


