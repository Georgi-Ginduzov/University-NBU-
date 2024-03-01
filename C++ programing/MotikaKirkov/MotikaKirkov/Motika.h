#pragma once
#include <iostream>
#include <string>
using std::string;

class Motika
{
public:
	Motika();
	Motika(int duljinaNaDrujkata);
	~Motika();
	void printMotika();
	
	int getDulginaNaDrujkata();
	void setDulginaNaDrujkata(int duljina);

	Motika& operator++();

	Motika operator++(int);
	
protected:

private:
	string gornaDrujka;
	char drujka;
	int duljinaDrujka;	
	string ostrie;
};

std::ostream& operator<<(std::ostream& out, const Motika& m);