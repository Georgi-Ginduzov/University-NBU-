#include "Tangerine.h"
#include <iostream>
Tangerine::Tangerine(double radius, bool hasSeedsOrPits, bool isPoisonous,
	double sugarPercentage) :Ball(radius), Fruit(hasSeedsOrPits, isPoisonous, sugarPercentage) {

}

double Tangerine::getRadius() const {
	std::cout << "approx. ";
	Ball::getRadius();
	return 0;
}