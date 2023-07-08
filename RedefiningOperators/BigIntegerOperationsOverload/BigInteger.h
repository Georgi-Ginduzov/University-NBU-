#pragma once
#include <iostream>
#include <climits>
#include <string>

using std::string;

class BigInteger
{
public:
	BigInteger();
	BigInteger(string textNum);
	~BigInteger();

	string getTextNumber();
	long long int getNumber();

	void setTextNumber(string number);
	void setNumber(long long int number);

	friend std::ostream& operator<<(std::ostream& out, const BigInteger& bigInt);
	friend std::istream& operator>>(std::istream& in, BigInteger& bigInt);

	BigInteger operator+(const BigInteger& a) const;
	BigInteger operator-(const BigInteger& a) const;
	BigInteger operator*(const BigInteger& a) const;

private:
	string textNumber;
	long long int number;
};

