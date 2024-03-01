#include "DevilManatarka.h"

DevilManatarka::DevilManatarka(std::string ingredient) {
	ingredient = ingredient;
}

void DevilManatarka::setInggredient(std::string ingredient) {
	this->ingredient = ingredient;
}

std::string DevilManatarka::getIngredient() {
	return this->ingredient;
}

void DevilManatarka::cook() {
	std::cout << "This type of mushroom(Devil) is poisonous so it will be cooked with your favourite food";
}

DevilManatarka::~DevilManatarka() {

}