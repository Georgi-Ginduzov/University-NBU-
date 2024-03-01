#include <iostream>

	using std::cout;
	using std::cin;
	using std::endl;

	int main() {

		std::string number;

		cout << "Enter number: ";
		cin >> number;

		int sum = 0;

		for (size_t i = 0; i < number.size(); i++)
		{
			if ((int)number[i] >= 48 && (int)number[i] <= 57)
			{
				sum += (int)number[i] - 48;
			}
		}

		int astralNum = sum % 9;

		cout << "The astral number is: " << astralNum;

		return 0;
	}