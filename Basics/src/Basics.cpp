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
	std::cout << "!!!Hello World!!!" << std::endl; // prints !!!Hello World!!!
	std::cerr << "Hello on error output" << std::endl;
	std::clog << "Hello on log output" << std::endl;
	return 0;
}




