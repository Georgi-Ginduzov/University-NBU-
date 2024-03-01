#pragma once
#include <string>

using std::string;

class Chovek
{
public:
	Chovek();
	Chovek(string malkoIme, string familnoIme, char pol);
	~Chovek();
	string getMalkoIme() const;
	string getFamilnoIme() const;
	char getPol() const;

	void setMalkoIme(string malkoIme);
	void setFamilnoIme(string familnoIme);
	void setPol(char pol);

	void print() const;

private:
	string malkoIme;
	string familnoIme;
	char pol;
};

