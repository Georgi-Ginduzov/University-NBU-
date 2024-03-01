#include "Ball.h"
#include "Plod.h"
#include "Colour.h"
#include <string>

class Tangerine : public Ball, public Fruit, public Color {

public:
	Tangerine(double radius, bool hasSeedsOrPits, bool isPoisonous, double sugarPercentage);
	double getRadius() const;

private:
	std::string countryOfOrigin;
};

