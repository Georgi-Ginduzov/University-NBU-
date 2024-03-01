#include "BigInteger.h"
#include <iostream>
#include <string>

BigInteger::BigInteger() {
	textNumber = "";
	number = 0;
}
BigInteger::BigInteger(string textNum) {
	setTextNumber(textNum);
}
BigInteger::~BigInteger() {

}

//set methods
void BigInteger::setTextNumber(string textNumber) {
	this->textNumber = textNumber;
	number = std::stoll(textNumber);
}
void BigInteger::setNumber(long long int number) {
	this->number = number;
	textNumber = std::to_string(number);
}

//get methods
string BigInteger::getTextNumber() {
	//return this->textNumber;
	return textNumber;
}
long long int BigInteger::getNumber() {
	//return this->number;
	return number;
}
//overload cout & cin
std::ostream& operator<<(std::ostream& out, const BigInteger& bigInt) {
	out << "Text number: " << bigInt.textNumber;
	return out;
}
std::istream& operator>>(std::istream& in, BigInteger& bigInt) {
	string str;
	in >> str;
	bigInt.setTextNumber(str);
	return in;
}

//overloading operators
	BigInteger BigInteger::operator+(const BigInteger& a) const {
		long long int sum = this->number + a.number;
		BigInteger result;
		result.setTextNumber(std::to_string(sum));
		return result;
	}
	BigInteger BigInteger::operator-(const BigInteger& a) const {
		long long int substarction = this->number - a.number;
		BigInteger result;
		result.setTextNumber(std::to_string(substarction));
		return result;
	}
	BigInteger BigInteger::operator*(const BigInteger& a) const {
		long long int multiplication = this->number * a.number;
		BigInteger result;
		result.setTextNumber(std::to_string(multiplication));
		return result;
	}

