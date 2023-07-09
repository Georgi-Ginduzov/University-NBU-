#pragma once
#include <iostream>
#include <string>

class Employee
{
private:
	std::string name;
	int salary;

public:
	Employee();
	~Employee();
	
	std::string getEmployerName();
	int getEmployerSalary();

	void setEmployerName(std::string name);
	void setEmployerSalary(int salary);

	void saySomething(std::string name);
};

