#pragma once
#include <iostream>
	using std::string;

	class StudentMarks
	{
	public:
		StudentMarks();

		void setName(string name);
		void setMark1(float mark1);
		void setMark2(float mark2);

		string getName();
		float getMark1();
		float getMark2();

		float getMarks(int markNumber);
		float sumMarks();

		~StudentMarks();
	private:
		string name;
		float mark1;
		float mark2;
	};

