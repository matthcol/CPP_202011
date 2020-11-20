/*
 * Pixel.h
 *
 *  Created on: 18 nov. 2020
 *      Author: Matthias
 */

#ifndef PIXEL_H_
#define PIXEL_H_

#include <cstdint>
#include <ostream>
#include <string>

class Pixel {
private:
	uint8_t greyScale;
	uint16_t x;
	uint16_t y;

public:
	Pixel();
	Pixel(uint8_t greyScale, uint16_t x, uint16_t y);
	virtual ~Pixel();

	bool operator==(const Pixel &other);

	uint8_t getGreyScale() const;
	void setGreyScale(uint8_t greyScale);
	uint16_t getX() const;
	void setX(uint16_t x);
	uint16_t getY() const;
	void setY(uint16_t y);

	virtual std::string toString() const;

	void smoothing(uint8_t greyScaleThreshold); // no const: modification
	double distance(const Pixel &other) const; // no modification

};

std::ostream& operator<<(std::ostream &out, const Pixel &pixel);
std::ostream& operator<<(std::ostream &out, const Pixel *pixel_ptr);

#endif /* PIXEL_H_ */
