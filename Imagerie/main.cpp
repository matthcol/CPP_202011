/*
 * main.cpp
 *
 *  Created on: 18 nov. 2020
 *      Author: Matthias
 */


#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <list>
#include <set>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <functional>
#include <random>

#include "Pixel.h"
#include "Detection.h"

void displayPixel(const Pixel &pixel) {
	std::cout << "("
			<< pixel.getX() << ","
			<< pixel.getY() << ")#"
			<< (uint16_t) pixel.getGreyScale();
}

void testPixel(){
	// 2 instances in the stack
	Pixel pixel1(255, 3, 10); // complete constructor
	Pixel pixel2; // default constructor
//	pixel1.setX(3);
//	pixel1.setY(10);
//	pixel1.greyScale = 255;
	pixel2.setGreyScale(128);
	std::cout << &pixel1 <<  " " << &pixel2 <<std::endl;
	displayPixel(pixel1);
	displayPixel(pixel2);
	// 1 instance in he heap
	Pixel *pixel3_ptr = new Pixel(65,5,7); // complete constructor
//	pixel3_ptr->x = 5;
//	pixel3_ptr->y = 7;
//	pixel3_ptr->greyScale = 65;
	std::cout << pixel3_ptr << " " << &pixel3_ptr << std::endl;
	displayPixel(*pixel3_ptr);
	// methode de smoothing
	pixel1.smoothing(130);
	pixel2.smoothing(130);
	pixel3_ptr->smoothing(50);
	std::cout << "After smooting:" << std::endl;
	displayPixel(pixel1);
	displayPixel(pixel2);
	displayPixel(*pixel3_ptr);
	// méthode de calcul de distance
	// (1E-308)^2 = 1E-616 => 0
	double d = pixel1.distance(pixel2);
	std::cout << "distance p1-p2: " << d << std::endl;
	// Autre distance
	const Pixel pixel4(66, 6,6);
	// pixel4.smoothing(50); // impossible
	std::cout << "distance p1-p4: " << pixel1.distance(pixel4) << std::endl;
	std::cout << "distance p4-p1: " << pixel4.distance(pixel1) << std::endl;
	// constructor/operateurs cadeaux
	// Pixel pixel5 = pixel1; 	// constructor by copy
	Pixel pixel5(pixel1); 	// constructor by copy
	displayPixel(pixel5);
	pixel5 = pixel2;		// operator assignment by copy
	displayPixel(pixel5);
	// comparaison  : <=>
	std::cout << "P1==P2: " << std::boolalpha << (pixel1 == pixel2) << std::endl;
	std::cout << "P1==P1: " << std::boolalpha << (pixel1 == pixel1) << std::endl;
	std::cout << "P5==P2: " << std::boolalpha << (pixel5 == pixel2) << std::endl;
	// std::cout << (pixel1 + pixel2) << std::endl;
	// std::cout << (pixel1 + 3) << std::endl;
	std::cout << "P1: " << pixel1 << std::endl;
	// libérer la mémoire
	delete pixel3_ptr; // call the destructor (do nothing)
} // les 4 pixels dans le stack sont supprimés and call the destructor (do nothing)

void waitForUser() {
	std::cout << "Program waiting, write something to continue ..."  << std::endl;
	std::string buffer;
	std::cin >> buffer;
}

void testContainerPixels(int size) {
	std::vector<Pixel> image;  // object vector stack with its elements in the heap
	// fill the vector
	for (int i = 0; i<size; i++ ) {
		Pixel pixel_in(128, i,i);
		image.push_back(pixel_in); // copy pixel in the vector (increase heap)
	}
	// display the vector
	if (size < 20) {
		for (auto &pixel_out: image) { // reference
			std::cout << pixel_out << std::endl;
		}
	}
	waitForUser();
}  // vector image est dépilé (supprimé du stack) => call vector destructor
   // deallocate all the memory in the heap for its elements

template<class InputIterator>
void displayIterable(InputIterator first, InputIterator last) {
	for ( ; first != last; ++first) {
		std::cout << *first << " ";
	}
	std::cout << std::endl;
}

bool compReverse(double d1, double d2) {
	return d1 > d2;
}

bool lessThan32(double d) {
	return d < 0.32;
}

void testContainersIterators() {
	// vector: dynamic array, consecutive elements in memory
	//	- random access en O(1)
	// list: des chainons liés les uns aux autres
	// list + vector :
	//	- find in O(n)
	// set: pas de doublons, rangés suivant un ordre (<)
	//  - find in O(log(n))
	std::vector<double> pressionVector = { 0.3, 0.35, 0.32 };
	std::list<double> pressionList = { 0.4, 0.45, 0.42 };
	std::set<double> pressionSet = { 0.5, 0.55, 0.52 };

	// InputIterator = std::vector<double>::iterator
	displayIterable(pressionVector.begin(), pressionVector.end());

	// InputIterator = std::list<double>::iterator
	displayIterable(pressionList.begin(), pressionList.end());

	// InputIterator = std::set<double>::iterator
	displayIterable(pressionSet.begin(), pressionSet.end());
	// InputIterator = std::set<double>::reverse_iterator
	displayIterable(pressionSet.rbegin(), pressionSet.rend());

	// InputIterator = bool  => error compilation on *first
	// displayIterable(false, true);

	// parcours partiel
	displayIterable(pressionVector.begin() + 1, pressionVector.end());
	auto it = pressionList.begin();
	//++(++it);
	std::advance(it,2);
	displayIterable(it, pressionList.end());
	displayIterable(pressionVector.begin(), pressionVector.end()-1);
	auto last = pressionSet.end();
	std::advance(last,-2);
	displayIterable(pressionSet.begin(), last);

	// ajout aux extremités
	pressionVector.push_back(0.315);
	displayIterable(pressionVector.begin(), pressionVector.end());
	pressionList.push_back(0.415);
	pressionList.push_front(0.425);
	displayIterable(pressionList.begin(), pressionList.end());

	// insert 1 value
	// set : coût O(log(n))
	auto res1 = pressionSet.insert(0.525);
	auto res2 = pressionSet.insert(0.525); // no doubles
	displayIterable(pressionSet.begin(), pressionSet.end());
	std::cout << "\t - insert 1: " << std::boolalpha << res1.second << " / " << *(res1.first) << std::endl;
	std::cout << "\t - insert 2: " << std::boolalpha << res2.second << " / " << *(res2.first) << std::endl;
	// vector: coût : recherche O(1) + WARNING: deplacement elements à droite
	pressionVector.insert(pressionVector.begin()+2, 0.325);
	displayIterable(pressionVector.begin(), pressionVector.end());
	// list: coût : advance + insert chainon kdo
	auto pos = pressionList.begin();
	std::advance(pos, 2);
	pressionList.insert(pos, 0.475);
	displayIterable(pressionList.begin(), pressionList.end());

	// insert par lot
	pressionSet.insert(pressionVector.begin(), pressionVector.end());
	displayIterable(pressionSet.begin(), pressionSet.end());
	auto pos2 =  pressionList.begin();
	std::advance(pos2, 3);
	pressionList.insert(pos, pressionVector.begin(), pressionVector.end());
	displayIterable(pressionList.begin(), pressionList.end());

	// assign
	pressionVector.assign(pressionList.begin(), pressionList.end());
	displayIterable(pressionVector.begin(), pressionVector.end());

	// algo
	double pressionTotal = std::accumulate(pressionVector.begin(), pressionVector.end(), 0.0);
	std::cout << "Total: " << pressionTotal << std::endl;
	double pressionPartTotal = std::accumulate(pressionVector.begin()+2, pressionVector.end()-3, 0.0);
	std::cout << "Total partiel: " << pressionPartTotal << std::endl;
	// sort by default
	std::sort(pressionVector.begin(), pressionVector.end()); // cout O(n*log(n))
	displayIterable(pressionVector.begin(), pressionVector.end());
	// sort custom
	// std::sort(pressionVector.begin(), pressionVector.end(), compReverse);
	// std::sort(pressionVector.begin(), pressionVector.end(), &compReverse);
	std::sort(pressionVector.begin(), pressionVector.end(), std::greater<double>());
	displayIterable(pressionVector.begin(), pressionVector.end());

	// algo with predicate
	auto nb = std::count_if(pressionVector.begin(), pressionVector.end(), lessThan32);
	std::cout << "Nb elements < 0.32: " << nb << std::endl;
	// same thing with anonymous function
	auto nb2 = std::count_if(pressionVector.begin(), pressionVector.end(),
			[](auto d){return d < 0.32;} );
	std::cout << "Nb elements < 0.32: " << nb2 << std::endl;
	double thresholdMax = 0.34;
	auto nb3 = std::count_if(pressionVector.begin(), pressionVector.end(),
				[thresholdMax](auto d){return d < thresholdMax;} ); // avec capture de thresholdMax
	std::cout << "Nb elements < " << thresholdMax << ": " << nb3 << std::endl;

	// vecteur result de la taille du vecteur source
	std::vector<double> pressionResult(pressionVector.size());
	// appliquer p -> 0.9*p + 0.001 à tous les éléments de pressionVector
	// et ranger les résultats dans le vecteur pressionResult
	std::transform(pressionVector.begin(), pressionVector.end(), pressionResult.begin(),
			[](auto p){return 0.9*p + 0.001;});
	displayIterable(pressionResult.begin(), pressionResult.end());

//	for (const double &element: pressionSet) {
//		std::cout << element << " ";
//	}
//	std::cout << std::endl;
//	for (auto it = pressionSet.begin(); it != pressionSet.end(); ++it) {
//		std::cout << *it << " ";
//	}
//	std::cout << std::endl;


}

void testContainersIteratorsPixels() {
	// element du vector en mode direct (attention aux copies)
	Pixel p1(128,0,0);
	Pixel p2(128,0,1);
//	std::vector<Pixel> image = { p1, p2 };
//	std::vector<Pixel> image;
//	image.push_back(p1);
//	image.push_back(p2);
////	displayIterable(image.begin(), image.end());
//	std::vector<std::vector<Pixel>> imageCollection;

	// element du vector en mode reference
	// std::vector<Pixel&> image2;
	// impossible car en interne le vecteur utilise des pointeurs sur les éléments
	// Regle du C++: un pointeur sur une référence c'est impossible

	// element du vector en mode pointeur
	std::vector<Pixel*> image2 = { &p1, &p2};
	std::cout << "Adresses of pixel: " << (void *) &p1 << ", " << (void *) &p2 << std::endl;
	displayIterable(image2.begin(), image2.end());
}

std::vector<Pixel*>* createImage(size_t width, size_t height) {
	//std::vector<Pixel*> res(width*height);
	std::vector<Pixel*> *res = new std::vector<Pixel*>(width*height);
	// fill vector with random data
	std::default_random_engine generator;
	std::normal_distribution<double> distribution(150.0,100.0);
	for (size_t i=0; i < height; i++) {
		for (size_t j=0; j < width; j++) {
			Pixel *pixel_ptr = new Pixel((uint8_t) distribution(generator), i, j);
			(*res)[i*width + j] = pixel_ptr;
		}
	}
	return res;
}

void deleteImage(std::vector<Pixel*>* image_ptr) {
	for (auto pixel_ptr: *image_ptr) {
		delete pixel_ptr;
	}
	delete image_ptr;
}

void saveImageTxt(const std::vector<Pixel*>* image_ptr, const std::string &filename) {
	std::ofstream out;
	out.open(filename, std::ofstream::out);  // output stream en mode écrase
	for (auto pixel_ptr : *image_ptr) {
		out << pixel_ptr << std::endl;
	}
	out.close();
}

void saveImagePbm(const std::vector<Pixel*>* image_ptr, const std::string &filename) {
	std::ofstream out;
	out.open(filename, std::ofstream::out); // | std::ofstream::binary);  // output stream en mode écrase
	out << "P1" << std::endl;
	out << "800 800" << std::endl;
	for (auto pixel_ptr : *image_ptr) {
		out << pixel_ptr->getGreyScale() << std::endl;
	}
	out.close();
}

void trueLifeCycleContainer() {
	// 1. create data
	std::vector<Pixel*> *image_ptr = createImage(800, 800);
	// 2. manipuler la data: smoothintg sur toute l'image
	// displayIterable(image_ptr->begin(), image_ptr->end());
	uint8_t threshold = 150;
	auto nbUnderThreshold = std::count_if(image_ptr->begin(), image_ptr->end(),
			[threshold](auto pixel_ptr){return  pixel_ptr->getGreyScale() <= threshold;});
	std::cout << "Nb under threshold " << (uint16_t) threshold
			<< ": " << nbUnderThreshold << std::endl;
	for (auto pixel_ptr: *image_ptr) {
		pixel_ptr-> smoothing(threshold);
	}
	nbUnderThreshold = std::count_if(image_ptr->begin(), image_ptr->end(),
				[threshold](auto pixel_ptr){return  pixel_ptr->getGreyScale() <= threshold;});
	std::cout << "Nb under threshold " << (uint16_t) threshold
				<< ": " << nbUnderThreshold << std::endl;
	auto nbEqualsThreshold = std::count_if(image_ptr->begin(), image_ptr->end(),
			[threshold](auto pixel_ptr){return  pixel_ptr->getGreyScale() == threshold;});
	std::cout << "Nb equals threshold " << (uint16_t) threshold
					<< ": " << nbEqualsThreshold << std::endl;
	// 3. sauvegarde
	saveImageTxt(image_ptr, "image.txt");
	saveImagePbm(image_ptr, "image.pbm");
	// 4. supprimer la data
	deleteImage(image_ptr);
}

void testDetection() {
	Detection detect1;
	Detection detect2(128, 3,4);
	Detection detect3(58, 5, 6, true);
	Pixel pixel(0, 5,5);
	detect1.computeInside(pixel, 3);
	detect2.computeInside(pixel, 3);
}
// 3 Detection et 1 Pixel sont détruits
//   . object Detection: call destructor Detection  then destructor Pixel
//   . object Pixel: call destructor Pixel

void processPixelAsDetectionIfPossible(const Pixel *pixel_ptr) {
	if (typeid(*pixel_ptr) == typeid(Detection)) {
		std::cout << "pixel is a Detection object: " << *pixel_ptr << std::endl;
		const Detection *detect_ptr = dynamic_cast<const Detection*>(pixel_ptr);
		std::cout << "\t - isOrgan: " << std::boolalpha
				<< detect_ptr->isInsideOrgan() << std::endl;
	} else {
		std::cout << "pixel is not a Detection object: " << *pixel_ptr << std::endl;
	}
}

// 2nd solution: best one
void processPixelAsDetectionIfPossible2(const Pixel *pixel_ptr) {
	const Detection *detect_ptr = dynamic_cast<const Detection*>(pixel_ptr);
	if (detect_ptr) { // ptr non null
		std::cout << "pixel is a Detection object: " << *pixel_ptr << std::endl;
		std::cout << "\t - isOrgan: " << std::boolalpha
				<< detect_ptr->isInsideOrgan() << std::endl;
	} else {
		std::cout << "pixel is not a Detection object: " << *pixel_ptr << std::endl;
	}
}

// en mode reference (attention ref nulle n'existe pas en C++)
void processPixelAsDetectionIfPossible3(const Pixel &pixel_ref) {
	if (typeid(pixel_ref) == typeid(Detection)) {
		const Detection &detect_ref = dynamic_cast<const Detection&>(pixel_ref);
		//std::cout << "pixel is a Detection object: " << pixel_ref << std::endl;
		std::cout << "pixel is a Detection object: " << detect_ref << std::endl;
		std::cout << "\t - isOrgan: " << std::boolalpha
				<< detect_ref.isInsideOrgan() << std::endl;
	} else {
		std::cout << "pixel is not a Detection object: " << pixel_ref << std::endl;
	}
}

void testDetectionSubstitution() {
	Pixel *pixel1_ptr = new Pixel(0,1,1);
	Pixel *pixel2_ptr = new Detection(255,2,2);
	Detection *pixel3_ptr = new Detection(128,3,3);
	std::cout << "P1: " << *pixel1_ptr << std::endl;
	std::cout << "P2: " << *pixel2_ptr << std::endl;
	std::cout << "P2 gs: " << pixel2_ptr->getGreyScale() << std::endl;
	// std::cout << "P1 insideOrgan: " << pixel1_ptr->isInsideOrgan() << std::endl;
	// std::cout << "P2 insideOrgan: " << pixel2_ptr->isInsideOrgan() << std::endl;
	std::cout << "P3 insideOrgan: " << pixel3_ptr->isInsideOrgan() << std::endl;

//	processPixelAsDetectionIfPossible(pixel1_ptr);
//	processPixelAsDetectionIfPossible(pixel2_ptr);
//	processPixelAsDetectionIfPossible2(pixel1_ptr);
//	processPixelAsDetectionIfPossible2(pixel2_ptr);
	processPixelAsDetectionIfPossible3(*pixel1_ptr);
	processPixelAsDetectionIfPossible3(*pixel2_ptr);

	// no substitution here => only copy
	Pixel pixel_direct = *pixel2_ptr; // constructor by copy de Pixel
	pixel_direct = *pixel3_ptr; // copy by assignment

	// toString
	std::cout << "P1 toString: " << pixel1_ptr->toString() << std::endl;
	std::cout << "P2 toString: " << pixel2_ptr->toString() << std::endl;
	std::cout << "P3 toString: " << pixel3_ptr->toString() << std::endl;

	delete pixel1_ptr;
	delete pixel2_ptr;
	delete pixel3_ptr;
}



int main(){
	// testPixel();
	// testContainerPixels(10);
	// testContainerPixels(300000000);
	// testContainersIterators();
	// testContainersIteratorsPixels();
	trueLifeCycleContainer();
	// testDetection();
	// testDetectionSubstitution();
	waitForUser();
}




