/*
 * Detection.cpp
 *
 *  Created on: 19 nov. 2020
 *      Author: Matthias
 */

#include <iostream>
#include <sstream>
#include "Detection.h"

Detection::Detection():
	Detection(0,0,0)
{
}

Detection::Detection(uint8_t greyScale, uint16_t x, uint16_t y):
		Detection(greyScale,x,y,false)
{
}

Detection::Detection(uint8_t greyScale, uint16_t x, uint16_t y,	bool insideOrgan):
		Pixel(greyScale,x,y),  // delegation au constructeur parent
		insideOrgan(insideOrgan)
{
}

Detection::~Detection() {
	std::clog << "Detection destroyed: " << *this << std::endl;
}

bool Detection::isInsideOrgan() const {
	return insideOrgan;
}

void Detection::setInsideOrgan(bool insideOrgan) {
	this->insideOrgan = insideOrgan;
}


void Detection::computeInside(const Pixel &centre, uint16_t radius) {
	// this : Detection*
	// *this: Detection
	// this->insideOrgan = centre.distance(*this) <= radius;
	this->insideOrgan = this->distance(centre) <= radius;
}

std::string Detection::toString() const {
	std::stringstream res;
	res	<< "("
		<< this->getX() << ","
		<< this->getY() << ")#"
		<< (uint16_t) this->getGreyScale()
		<< "/" << std::boolalpha << this->isInsideOrgan();
	return res.str();
}

//std::ostream& operator <<(std::ostream &out, const Detection &pixel) {
//	return out << "("
//			<< pixel.getX() << ","
//			<< pixel.getY() << ")#"
//			<< (uint16_t) pixel.getGreyScale()
//			<< "/" << std::boolalpha << pixel.isInsideOrgan();
//
//}


