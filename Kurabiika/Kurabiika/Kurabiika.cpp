#include "Kurabiika.h"
#include <iostream>
#include <cstring>

Kurabiika::Kurabiika() {
	sugarDailyIntake = 0;
	surova = true;
	strcpy(tipBrashno, "");
}
Kurabiika::~Kurabiika() {

}
Kurabiika::Kurabiika(int sugarDailyIntake, bool surova, const char* tipBrashno[]) {
	this->sugarDailyIntake = sugarDailyIntake;
	this->surova = surova;
	strcpy(this->tipBrashno, *tipBrashno);
}

void Kurabiika::setSugarDailyIntake(int sugarDailyIntake) {
	this->sugarDailyIntake = sugarDailyIntake;
}
void Kurabiika::setSurova(bool surova) {
	this->surova = surova;
}
void Kurabiika::setTipBrashno(char tipBrashno[]) {
	strcpy(this->tipBrashno, tipBrashno);
}

int Kurabiika::getSugarDailyIntake() const{
	return this->sugarDailyIntake;
}
bool Kurabiika::getSurova() {
	return this->surova;
}
const char* Kurabiika::getTipBrashno() const{
	return tipBrashno;
}

void Kurabiika::print() {
	std::cout << "Procenten dql zahar ot dnevniq priem v kurabiikata: " << sugarDailyIntake
		<< "\n Kurabiikata e ";
	if (surova == true)
	{
		std::cout << "surova\n";
	}
	else
	{
		std::cout << "izpechena\n";
	}
	std::cout << "Tipa brashno na kurabiikata e " << tipBrashno;
	/*for (int i = 0; i < sizeof(tipBrashno) / sizeof(tipBrashno[0]); i++)
	{
		std::cout << tipBrashno[i];
	}*/
}

Kurabiika& Kurabiika::operator++() {
	setSugarDailyIntake(getSugarDailyIntake() + 1);
	return *this;
}
Kurabiika Kurabiika::operator++(int) {
	Kurabiika k = *this;
	setSugarDailyIntake(getSugarDailyIntake() + 1);
	return k;
}

Kurabiika Kurabiika::operator+(const Kurabiika& k) const{
	Kurabiika result;
	result.sugarDailyIntake = (this->sugarDailyIntake + k.sugarDailyIntake);
}
