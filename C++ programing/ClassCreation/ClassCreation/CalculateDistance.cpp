#include "CalculateDistance.h"

CalculateDistance::CalculateDistance() {

}

CalculateDistance::CalculateDistance(int x, int y, int z) {
	x = 0;
	y = 0;
}

void CalculateDistance::setX(int x) {
	this->x = x;
}
void CalculateDistance::setY(int y) {
	this->y = y;
}
void CalculateDistance::setZ(int z) {
	this->z = z;
}


int CalculateDistance::getX() {
	return this->x;
}
int CalculateDistance::getY() {
	return this->y;
}
int CalculateDistance::getZ() {
	return this->z;
}

void CalculateDistance::magnify() {
	this->x *= -2;
	this->y *= 0.5;
	this->z *= 5;
}

void CalculateDistance::scalingZ() {
	this->z += 4;
}

CalculateDistance::~CalculateDistance() {

}