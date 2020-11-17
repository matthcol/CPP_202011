/*
 * main.cpp
 *
 *  Created on: 17 nov. 2020
 *      Author: Matthias
 */

#include <iostream>
#include <vector>
#include <string>

void testArrays() {
	int dummy = 25;
	int dummy2[] = { 33, 44, 55 };
	// arrays
	int n=5;
	int temperatures[n]; // array of 5 integers (random content)
	temperatures[0] = 14;
	temperatures[1] = 16;
	temperatures[2] = 23;
	temperatures[3] = 18;
	temperatures[4] = 22;
	double pressions[] = {0.3, 0.31, 0.34, 0.32}; // static initialization
	// attention au debordement de tableau sur les variables voisines
	// et eventuellement segmentation fault
	for (int i = 0; i < n; i++) {
		std::cout << temperatures[i] << " " ;
	}
	std::cout << std::endl;
}

void testContainersIterators() {
	// containers of stdlibc++
	std::vector<double> pressionVector0;
	std::cout << "Size v0: " << pressionVector0.size() << std::endl; // => size 0
	std::vector<double> pressionVector = {0.3, 0.31, 0.34, 0.32};
	std::cout << "Size v: "  << pressionVector.size() << std::endl;
	for (unsigned int i=0; i < pressionVector.size(); i++) {
		std::cout << pressionVector[i] << " ";
	}  // signedness
	pressionVector.push_back(0.33);
	std::cout << std::endl;
	// foreach loop, implicit iteration
	// type vector is iterable overs its elements
	// one simple value is not iterable
	//	double onePression = 0.3;
	//	for (auto particule: onePression) {
	//
	//	}
	//for (double pression: pressionVector) {
	for (auto pression: pressionVector) {
		std::cout << pression << " ";
	}
	std::cout << std::endl;
	// type string is iterable over its letters
	std::string ville = "Toulouse";
	//for (char letter: ville) {
	for (auto letter: ville) {
		std::cout << letter << " ";
	}
	std::cout << std::endl;
	// retraduction du foreach avec  iterators explicites:
	//	begin => position de départ/début
	//  end => position de fin de parcours (juste après)
	//  ++it => déplacer l'iterateur/curseur de 1 position
	// for (std::vector<double>::iterator it = pressionVector.begin() ;
	for (auto it = pressionVector.begin() ;
			it != pressionVector.end();
			++it)
	{
		double pression = *it; // current element
		std::cout << pression << " ";
	}
	std::cout << std::endl;
}

int main() {
	testArrays();
	testContainersIterators();
	std::cout << "That's all Folks !!" << std::endl;
	return 0;
}


