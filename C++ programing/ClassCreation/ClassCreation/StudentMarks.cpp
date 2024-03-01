#include "StudentMarks.h"

StudentMarks::StudentMarks() {

}

void StudentMarks::setName(string name) {
	this->name = name;
}
void StudentMarks::setMark1(float mark1) {
	this->mark1 = mark1;
}
void StudentMarks::setMark2(float mark2) {
	this->mark2 = mark2;
}

string StudentMarks::getName() {
	return this->name;
}
float StudentMarks::getMark1() {
	return this->mark1;
}
float StudentMarks::getMark2() {
	return this->mark2;
}

float StudentMarks::getMarks(int markNumber) {
	if (markNumber == 1)
	{
		return this->mark1;
	}
	else {
		return this->mark2;
	}
}

float StudentMarks::sumMarks() {
	return this->mark1 + this->mark2;
}

StudentMarks::~StudentMarks() {

}