#include <iostream>
#include <string>

using std::string;

struct Student {
	string facultyNumber;
	string name;
	float averageGrade;
};

void printExcelentStudents(Student* student, int n) {
	for (int i = 0; i < n; i++)
	{
		if (student->averageGrade > 5.49)
		{
			std::cout << student->name << " is excellent!\n";
		}
	}
}
void printPoorStudents(Student* student, int n) {
	for (int i = 0; i < n; i++)
	{
		if (student->averageGrade < 3)
		{
			std::cout << student->name << " is poor of knowledge :(\n";
		}
	}
}

float averageGrade(Student* student, int n) {
	int sum;
	for (int i = 0; i < n; i++)
	{
		sum += student->averageGrade;
	}
	return (sum / n);
}

void printStudents(Student* student, int n) {
	for (int i = 0; i < n; i++)
	{
		std::cout << "\n" << student->facultyNumber << " " << student->name << " average grade " << student->averageGrade << "\n";
	}
}
void printStudentInfo(Student* student, int n) {
	std::cout << "\n" << student[n].facultyNumber << " " << student[n].name << " average grade " << student[n].averageGrade << "\n";
}

int main() {
	int n;
	std::cout << "Enter students number: ";
	std::cin >> n;

	Student* students = new Student[n];

	printExcelentStudents(students, n);
	printPoorStudents(students, n);

	float average = averageGrade(students, n);

	

	return 0;
}