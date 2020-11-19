/*
 * Detection.h
 *
 *  Created on: 19 nov. 2020
 *      Author: Matthias
 */

#ifndef DETECTION_H_
#define DETECTION_H_

#include <string>
#include "Pixel.h"

class Detection: public Pixel {
private:
	bool insideOrgan;
public:
	Detection();
	Detection(uint8_t greyScale, uint16_t x, uint16_t y);
	Detection(uint8_t greyScale, uint16_t x, uint16_t y, bool insideOrgan);
	virtual ~Detection();

	virtual std::string toString() const override;

	bool isInsideOrgan() const;
	void setInsideOrgan(bool insideOrgan);

	void computeInside(const Pixel &centre, uint16_t radius);
};

// std::ostream& operator<<(std::ostream &out, const Detection &pixel);

#endif /* DETECTION_H_ */
