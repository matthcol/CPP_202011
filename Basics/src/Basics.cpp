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
#include <cstdint>
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
	ville[0] = 'Z';  // 'Z' est de type char
	std::cout << "I'm in " << ville << std::endl;
	// affichage des adresses mémoires
	std::cout << "adresse variable ville: " << &ville << std::endl;
	std::cout << "adresse 1ere lettre de la variable ville: " << (void *) &ville[0] << std::endl;
//	char villeC[] = "Bordeaux";  // tableau de char i.e le type "string" de C
//	std::cout << "adresse tableau/1ere lettre: " << &villeC << ", " << (void *) &villeC[0] << std::endl;
    std::cout << "Taille: " << ville.size() << std::endl;
    ville.append(" ville rose");
    std::cout << "Ville qualifiée : " << ville << " # " << ville.size() << std::endl;
    std::string ville3; // chaine vide à l'aide du constructeur par défaut
    std::cout << "Ville vide #" << ville3 << "# " <<  ville3.size() << std::endl;
    ville3 += "Pau"; // equivalent append
    ville3 += " dans le 64";
    std::cout << "Ville plus vide #" << ville3 << "# " <<  ville3.size() << std::endl;

    // opérateurs en C++
    temperature = 9;
    double result = (temperature + pression) * price / 10 - 5.0;
    int result2 = temperature % 4; // modulo ou reste de la division entière (Euclide)
    int result3 = temperature / 4; // quotient au sens d'Euclide
    std::cout << "division: Q=" << result3 << ", R=" << result2 << std::endl;
    std::cout << (temperature / 4.0) << std::endl;
    temperature = temperature + 2;
    temperature += 2;
    std::cout << "ça chauffe: " << temperature << std::endl;
    temperature /= 2;
    std::cout << "coup de froid: " << temperature << std::endl;
    // other:  -=  *=  %=
    temperature++;
    std::cout << "+1: " << temperature << std::endl;
    ++temperature;
    std::cout << "+1: " << temperature << std::endl;
    std::cout << "pleins de +1: "
    		<< (++temperature) << ", "
			<< (temperature++) << ", "
			<< temperature << std::endl;
    // comparaison de contenu: ==  !=
    bool cmp = (temperature == 15);
    std::cout << "== : " << std::boolalpha << cmp << std::endl;
    cmp = false; // true
    // comparaison d'ordre: <  <=  > >=
    // combinaison logique: ! (not)   && (and)   || (or)
    cmp = ! ((temperature > 18) || (temperature <= 5));
    std::cout << "predicat : " << std::boolalpha << cmp << std::endl;
    // operator bitwise:  & (and)   | (or)    ^ (xor)    ~ (not)
    uint8_t data = 5; // unsigned int 8 bits: 00000101
    data = data | 12;  // 00000101 | 00001100 =>  00001101
    std::cout << "Operation bitwise: #" << (int) data  << "#" <<  std::endl;

	return 0;
}




