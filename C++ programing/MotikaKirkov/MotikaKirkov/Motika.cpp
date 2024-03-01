#include "Motika.h"
#include <iostream>

Motika::Motika() {
	gornaDrujka = "|>";
	setDulginaNaDrujkata(1); //duljinaDrujka = 1;
	drujka = '=';
	ostrie = "/ )";
}

Motika::~Motika() {

	std::cout << "Destructor called.." << std::endl;
}
void Motika::setDulginaNaDrujkata(int duljina) {
	if (duljinaDrujka > 0)
	{
		this->duljinaDrujka = duljina;
	}
	else
	{
		try {
			this->duljinaDrujka = 0;
			std::logic_error description("illegal parameter");
		}
		catch (std::logic_error& le) {
			std::cout << "Invalid data input";

		}
		catch (std::exception& e) {
			std::cout << "Invalid data input";

		}
		/*this->duljinaDrujka = 0;
		std::logic_error description("illegal parameter");
		throw description;*/

	}
}

int Motika::getDulginaNaDrujkata() {
	return this->duljinaDrujka;
}

void Motika::printMotika() {

	std::cout << gornaDrujka;
	for (int i = 0; i < duljinaDrujka; i++)
	{
		std::cout << drujka;
	}
	std::cout << ostrie;
}

Motika::Motika(int duljinaNaDrujkata):gornaDrujka("|>"), ostrie("/ )"), drujka('=') {
	this->duljinaDrujka = duljinaNaDrujkata;
}

Motika& Motika::operator++() {
	setDulginaNaDrujkata(getDulginaNaDrujkata() + 1);
	return *this;
}

Motika Motika::operator++(int) {
	Motika m = *this;
	setDulginaNaDrujkata(getDulginaNaDrujkata() + 1);
	//++ *this; Alternative
	return m;
}

//std::ostream& operator<<(std::ostream& out, const Motika& m) {
//	std::cout << m.;
//	for (int i = 0; i < m.duljinaDrujka; i++)
//	{
//		std::cout << drujka;
//	}
//	std::cout << ostream;
//}