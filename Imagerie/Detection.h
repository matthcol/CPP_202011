/*
 * Detection.h
 *
 *  Created on: 19 nov. 2020
 *      Author: Matthias
 */

#ifndef DETECTION_H_
#define DETECTION_H_

#include "Pixel.h"

class Detection: public Pixel {
private:
	bool insideOrgan;
public:
	Detection();
	Detection(uint8_t greyScale, uint16_t x, uint16_t y);
	Detection(uint8_t greyScale, uint16_t x, uint16_t y, bool insideOrgan);
	virtual ~Detection();

	bool isInsideOrgan() const;
	void setInsideOrgan(bool insideOrgan);

	void computeInside(const Pixel &centre, uint16_t radius);
};

#endif /* DETECTION_H_ */
