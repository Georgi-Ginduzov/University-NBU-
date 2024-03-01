#include "Employee.h"

Employee::Employee() {

}

Employee::~Employee() {

}

int Employee::getEmployerSalary() {
	return salary;
}
std::string Employee::getEmployerName() {
	return name;
}

void Employee::setEmployerSalary(int salary) {
	this->salary = salary;
}
void Employee::setEmployerName(std::string name) {
	this->name = name;
}

void Employee::saySomething(std::string name) {
	std::cout << name << ". Hi there!\n";
}