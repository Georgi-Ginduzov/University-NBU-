#include "Square.h"
#include <iostream>

 Square::Square() {

}

void Square::read() {
	std::cout << "Length: ";
	std::cin >> length;
	std::cout << "Height: ";
	std::cin >> height;
}

void Square::setLength(float length) {
	this->length = length;
}
void Square::setHeight(float height) {
	this->height = height;
}

float Square::getLength() {
	return this->length;
}
float Square::getHeight() {
	return this->height;
}

//float Square::perimeter(float length, float height) {
//	return 2 * (length + height);
//}

float Square::perimeter(float length, float height) {
	return 2 * (length + height);
}
float Square::area(float length, float height) {
	return length * height;
}

Square::~Square() {

}