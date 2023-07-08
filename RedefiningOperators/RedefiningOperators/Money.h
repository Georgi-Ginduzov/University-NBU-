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

