#include "Money.h"
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

int Money::getLev() const{
	return this->lev;
}
int Money::getStotinki() const{
	return this->stotinki;
}
int Money::getPercentage() const{
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
Money Money::operator+(const Money& a) const{
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
	if (lev > a.lev){
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

