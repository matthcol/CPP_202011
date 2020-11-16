//============================================================================
// Name        : Basics.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// 1ere étape de compilation: compilation séparéee (-c)
// g++ -c -o Basics.o Basics.cpp
// 2ème étape: édition des liens
// g++ -o Basics.exe Basics.o

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
//using namespace std;
//
//int main() {
//	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
//	cerr << "Hello on error output" << endl;
//	clog << "Hello on log output" << endl;
//	return 0;
//}

// without using namespace std

int main() {
	// unsigned int temperature; // de 0 à ~4 milliards
	int temperature; // declare  // de ~ -2milliards à 2 milliards
	temperature = 18; // assign
	// bar, oxygen dans les combinaisons
	double pression = 0.3; // declare with initialization
	float price = 0.1;
	std::string ville = "Toulouse";
	std::cout << "!!!Hello World!!!" << std::endl; // prints !!!Hello World!!!
	std::cerr << "Hello on error output" << std::endl;
	std::clog << "Hello on log output" << std::endl;
	std::cout << "temperature: " << temperature << "°C" << std::endl;
	std::cout << "pression: " << pression << " bar" << std::endl;
	std::cout << "bonbons: "  << std::setprecision(10)
			<< price   <<  ", "
			<< 2*price << ", "
			<< 3*price << std::endl;
	// limite des entiers
	temperature = temperature + 2000000000;
	std::cout << "temperature: " << temperature << "°C" << std::endl;
	temperature = temperature * 2;
	std::cout << "temperature: " << temperature << "°C" << std::endl;
	std::cout << "int limit: " << std::numeric_limits<int>::max() << std::endl;
	std::cout << "unsigned int limit: " << std::numeric_limits<unsigned int>::max() << std::endl;
	// limites des flottants
	double distanceUniverse = 1E308;  // E = 10^
	std::cout << "distance unviverse: " << distanceUniverse << std::endl;
	std::cout << "et vers l'infini: " << 2*distanceUniverse << std::endl;
	std::cout << (2*distanceUniverse) / (2*distanceUniverse) << std::endl;
	std::cout << 0.0 / 0.0 << std::endl;
	// de ville en ville
	std::cout << "I'm in " << ville << std::endl;
	return 0;
}




