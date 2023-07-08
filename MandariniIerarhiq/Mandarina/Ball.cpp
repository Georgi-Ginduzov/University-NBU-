#include "Ball.h"
#include <iostream>

double Ball::getRadius() const {
	std::cout << this->radius << std::endl;
	return this->radius;
}


void Ball::setRadius(double radius) {
	if (radius >= 0) {
		this->radius = radius;
	}
	else {
		this->radius = 0;
	}
}

Ball::Ball(double radius) {
	setRadius(radius);
}