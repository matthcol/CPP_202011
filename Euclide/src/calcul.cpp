/*
 * calcul.cpp
 *
 *  Created on: 17 nov. 2020
 *      Author: Matthias
 */

#include "calcul.h"

int gcd(int a, int b) {
	int r;
	do {
		r = a % b;
		a = b;
		b = r;
	} while (b !=0);
	return a;
}

uint64_t fibo(int n) {
	switch (n) {
	case 0:
		return 0;
	case 1:
		return 1;
	default:
		return fibo(n-2) + fibo(n-1);
	}
}



