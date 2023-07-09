#include <iostream>
#include <vector>
#include "Mushroom.h"
#include "Manatarka.h"
#include "NormalManatarka.h"
#include "DevilManatarka.h"

class Mushroom
{
public:
	Mushroom() {

	}
	~Mushroom() {

	}
	virtual void cook() = 0;

private:

};

class Manatarka : public Mushroom
{
private:
	bool overBloomed;
	bool blue;

public:
	Manatarka(bool overBloomed, bool blue) {
		overBloomed = overBloomed;
		blue = blue;
	}
	~Manatarka();

	void setIsOverBloomed(bool isOverBloomed) 	{
		this->overBloomed = isOverBloomed;
	}
	void setIsBlue(bool isBlue) {
		this->blue = isBlue;
	}

	bool getIsOverBloomed() {
		return this->overBloomed;
	}
	bool getIsBlue() {
		return this->blue;
	}
	void cook();
};

class NormalManatarka : public Mushroom
{// it gets blue when it is despised
public:
	NormalManatarka() {

	}
	void cook() {
		std::cout << "Cooking normal manatarka with rice\n";
	}
	~NormalManatarka() {

	}
};

class DevilManatarka : public Mushroom
{
private:
	std::string ingredient;

public:
	DevilManatarka(std::string ingredient);
	~DevilManatarka();

	void setInggredient(std::string ingredient);
	std::string getIngredient();

	void cook() { 
		std::cout << "This type of mushroom(Devil) is poisonous so it will be cooked with " << ingredient; 
	}
};



int main() {
	

	return 0;
}