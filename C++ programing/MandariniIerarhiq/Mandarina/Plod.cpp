#include "Plod.h"
#include <iostream>

Fruit::Fruit(bool hasSeedsOrPits, bool isPoisonous,
	double sugarPercentage) :hasSeedsOrPits(hasSeedsOrPits),
	isPoisonous(isPoisonous), sugarPercentage(sugarPercentage) {
	std::cout << "Fruit ocnstructor called..." << std::endl;
}

void Fruit::eat() const {
	std::cout << "Mmmmm :)" << std::endl;
	if (this->isPoisonous) {
		std::cout << "R.I.P. <3" << std::endl;
	}
}