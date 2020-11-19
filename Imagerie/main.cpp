/*
 * main.cpp
 *
 *  Created on: 18 nov. 2020
 *      Author: Matthias
 */


#include <iostream>
#include <iomanip>
#include <vector>
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
	// testDetection();
	testDetectionSubstitution();
	//waitForUser();
}




