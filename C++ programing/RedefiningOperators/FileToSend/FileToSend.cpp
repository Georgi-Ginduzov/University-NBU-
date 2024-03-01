#pragma once
#include <iostream>

using std::ostream;
using std::istream;

class Money
{
public:
	Money();
	Money(int lev, int stotinki, int percentage);
	~Money();

	int getLev() const;
	int getStotinki() const;
	int getPercentage() const;

	void setLev(int lev);
	void setStotinki(int stotinki);
	void setPercentage(int percentage);

	friend ostream& operator<<(ostream& cout, Money& money) {
		cout << money.lev << " levs and " << money.stotinki << " stotinki" << std::endl;
		return cout;
	}
	friend istream& operator>>(istream& in, Money& money) {
		in >> money.lev >> money.stotinki;
		return in;
	}

	void stotinkiToLev(int stotinki, int lev);
	void levToStotinki(int stotinki, int lev);

	//overload arithmetic operators
	Money& operator++();
	Money operator++(int);

	Money operator+(const Money&) const;
	Money operator-(const Money&) const;
	Money operator*(const Money&) const;
	Money operator/(const Money&) const;

	//overload comparison operators
	bool operator>(const Money& a);
	bool operator<(const Money& a);
	bool operator==(const Money& a);

	//overload % customely
	friend Money operator%(const float& n, Money& a);

private:
	int lev;
	int stotinki;
	int percentage;
};
#include <iostream>

Money::Money() {
	lev = 0;
	stotinki = 0;
	percentage = 0;
}

Money::Money(int lev, int stotinki, int percentage) {
	setLev(lev);
	setStotinki(stotinki);
	setPercentage(percentage);
}

Money::~Money() {

}

void Money::setLev(int lev) {
	this->lev = lev;
}
void Money::setStotinki(int stotinki) {
	this->stotinki = stotinki;
}
void Money::setPercentage(int percentage) {
	this->percentage = percentage;
}

int Money::getLev() const {
	return this->lev;
}
int Money::getStotinki() const {
	return this->stotinki;
}
int Money::getPercentage() const {
	return this->percentage;
}

void Money::stotinkiToLev(int stotinki1, int lev1) {

	while (stotinki > 100)
	{
		this->lev++;
		this->stotinki -= 100;
	}
}
void Money::levToStotinki(int lev, int stotinki) {

}

Money& Money::operator++() {
	setLev(getLev() + 1);
	return *this;
}
Money Money::operator++(int) {
	Money m = *this;
	setLev(getLev() + 1);
	return m;
}

// overload arithmetic operators
Money Money::operator+(const Money& a) const {
	Money result;
	result.lev = (this->lev + a.lev);
	result.stotinki = (this->stotinki + a.stotinki);
	return result;
}
Money Money::operator-(const Money& a) const {
	Money result;
	result.lev = (this->lev - a.lev);
	result.stotinki = (this->stotinki - a.stotinki);
	return result;
}
Money Money::operator*(const Money& a) const {
	Money result;
	result.lev = (this->lev * a.lev);
	result.stotinki = (this->stotinki * a.lev);
	return result;
}
Money Money::operator/(const Money& a) const {
	Money result;
	result.lev = (this->lev / a.lev);
	result.stotinki = (this->stotinki / a.stotinki);
	return result;
}

// overload comparison
bool Money::operator>(const Money& a) {
	if (lev > a.lev) {
		return true;
	}
	if (lev == a.lev && stotinki > a.stotinki)
	{
		return true;
	}
	return false;
}
bool Money::operator<(const Money& a) {
	if (lev < a.lev) {
		return true;
	}
	if (lev == a.lev && stotinki < a.stotinki)
	{
		return true;
	}
	return false;
}
bool Money::operator==(const Money& a) {
	if (lev == a.lev && stotinki == a.stotinki) {
		return true;
	}
	return false;
}

Money operator%(const float& n, Money& a) {
	Money result;
	float percentage = n / 100.0;
	int total_stotinki = a.lev * 100 + a.stotinki;
	int discount = 0;
	if (std::fmod(n, 1.0) != 0) {
		discount = static_cast<int>(total_stotinki * percentage);
	}
	total_stotinki -= discount;
	result.lev = total_stotinki / 100;
	result.stotinki = total_stotinki % 100;
	return result;
}
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main() {
	Money m;
	Money p;
	float n;

	cout << "Object m: \n";
	cin >> m;

	cout << "p: \n";
	cin >> p;

	Money o = p + m;

	cout << o;
	return 0;
}

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
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
	BigInteger m("10");
	BigInteger p("");

	cin >> p;

	cout << m + p;
	cout << m - p;
	cout << m * p;

	return 0;
}
