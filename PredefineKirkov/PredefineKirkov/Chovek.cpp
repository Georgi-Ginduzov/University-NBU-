#include "Chovek.h"
#include <iostream>
#include <string>

Chovek::Chovek() {
	setMalkoIme("");
}

Chovek::Chovek(string malkoIme, string familnoIme, char pol) {
	setMalkoIme(malkoIme);
	setFamilnoIme(familnoIme);
	setPol(pol);
}

Chovek::~Chovek() {

}

void Chovek::setMalkoIme(string malkoIme) {
	this->malkoIme = malkoIme;
}

void Chovek::setFamilnoIme(string familnoIme) {
	this->familnoIme = familnoIme;
}
void Chovek::setPol(char pol) {
	this->pol = pol;
}

string Chovek::getMalkoIme() const{
	return this->malkoIme;
}
string Chovek::getFamilnoIme() const {
	return this->familnoIme;
}
char Chovek::getPol() const {

}

void Chovek::print() const{
	std::cout << malkoIme << " " << familnoIme << " s pol " << pol;
}