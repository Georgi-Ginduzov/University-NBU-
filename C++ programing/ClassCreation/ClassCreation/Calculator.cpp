#include "Calculator.h"

Calculator::Calculator() {

}
Calculator::Calculator(float number1, float number2) {
	number1 = 0;
	number2 = 0;
}

void Calculator::setNumber1(float number1) {
	this->number1 = number1;
}
void Calculator::setNumber2(float number2) {
	this->number2 = number2;
}

float Calculator::getNumber1() {
	return this->number1;
}
float Calculator::getNumber2() {
	return this->number2;
}

float Calculator::addition(float number1, float number2) {
	return number1 + number2;
}
float Calculator::substraction(float number1, float number2) {
	return number1 - number2;
}
float Calculator::multiplication(float number1, float number2) {
	return number1 * number2;
}
float Calculator::division(float number1, float number2) {
	return number1 / number2;
}

Calculator::~Calculator() {

}