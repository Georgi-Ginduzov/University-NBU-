#pragma once
class Kurabiika
{
	Kurabiika();
	~Kurabiika();
	Kurabiika(int sugarDailyIntake, bool surova, const char* tipBrashno[]);

	int  getSugarDailyIntake() const;
	bool getSurova();
	const char* getTipBrashno() const;

	void setSugarDailyIntake(int sugarDailyIntake);
	void setSurova(bool surova);
	void setTipBrashno(char tipBrashno[]);

	void print();

	Kurabiika& operator++();
	Kurabiika operator++(int);

	Kurabiika operator+(const Kurabiika&) const;

private:
	int sugarDailyIntake;
	bool surova;
	char tipBrashno[];
};

