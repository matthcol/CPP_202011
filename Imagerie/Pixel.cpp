/*
 * Pixel.cpp
 *
 *  Created on: 18 nov. 2020
 *      Author: Matthias
 */
#include <cmath>
#include <iostream>

#include "Pixel.h"


Pixel::Pixel(): Pixel(0,0,0)  // delegation constructor
{
}

Pixel::Pixel(uint8_t greyScale, uint16_t x, uint16_t y):
		greyScale(greyScale),
		x(x),
		y(y)
{
}

Pixel::~Pixel() {
	std::clog << "Pixel destroyed: " << *this << std::endl;
}

bool Pixel::operator==(const Pixel &other) {
	if (this == &other) { // compare addresses
		return true;
	}
	return (this->x == other.x)
			&& (this->y == other.y)
			&& (this->greyScale == other.greyScale);
}

void Pixel::smoothing(uint8_t greyScaleThreshold) {
	if (greyScale > greyScaleThreshold) {
		greyScale = greyScaleThreshold;
	}
}

uint8_t Pixel::getGreyScale() const {
	return greyScale;
}

void Pixel::setGreyScale(uint8_t greyScale) {
	this->greyScale = greyScale;
}

uint16_t Pixel::getX() const {
	return x;
}

void Pixel::setX(uint16_t x) {
	this->x = x;
}

uint16_t Pixel::getY() const {
	return y;
}

void Pixel::setY(uint16_t y) {
	this->y = y;
}

double Pixel::distance(const Pixel &other) const {
	return hypot(this->x - other.x , this->y - other.y);
}

std::ostream& operator<<(std::ostream &out, const Pixel &pixel) {
	return out << "("
			<< pixel.getX() << ","
			<< pixel.getY() << ")#"
			<< (uint16_t) pixel.getGreyScale();
}


