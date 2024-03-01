#include <iostream>
#include "Square.h"
#include "StudentMarks.h"
#include "Calculator.h"
#include "CalculateDistance.h"

	using std::cout;
	using std::endl;

		int main() {
			// Find area and perimeter of the sqare	(rectangle)
			Square a;
			a.setLength(2);
			a.setHeight(3);

			std::cout << "Parameter: " << a.perimeter(a.getLength(), a.getHeight()) << std::endl;
			std::cout << "Area: " << a.area(a.getLength(), a.getHeight()) << "\n\n";

			// Calculate student's total marks
			StudentMarks b;
			b.setName("John");
			b.setMark1(4.5);
			b.setMark2(5);

			std::cout << "Student: " << b.getName() << "\t Grades: " << b.getMark1() <<
				" & " << b.getMark2() << "\t Sum: " << b.sumMarks() << "\n\n";

			// Calculation operations with two numbers
			Calculator c;
			c.setNumber1(30);
			c.setNumber2(2);

			cout << "Addition: " << c.addition(c.getNumber1(), c.getNumber2()) << endl;
			cout << "Substraction: " << c.substraction(c.getNumber1(), c.getNumber2()) << endl;
			cout << "Multiplication: " << c.multiplication(c.getNumber1(), c.getNumber2()) << endl;
			cout << "Division: " << c.division(c.getNumber1(), c.getNumber2()) << endl << endl;
				
			// Calculate distances in 3d
			CalculateDistance point;
			point.setX(1);
			point.setY(2);
			point.setZ(3);

			point.magnify();
			cout << "x: " << point.getX() << " y: " << point.getY() << " z: " << point.getZ() << "\n";
			point.scalingZ();
			cout << "x: " << point.getX() << " y: " << point.getY() << " z: " << point.getZ() << "\n";
		}