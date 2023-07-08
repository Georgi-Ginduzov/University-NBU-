#include <iostream>
#include <cmath>

	using std::cout;
	using std::cin;
	using std::endl;

		bool checkIfPowerOfTwo(double num)
		{		
			do
			{
				if (num == 2)
				{
					return true;
				}

				num = num / 2;

				if (num < 2)
				{
					return false;
				}
			} while (num > 0);
		}

		int main()
		{
			double number;

			do
			{
				cout << "Enter number to check if its power of 2: ";
				cin >> number;

				bool isPowerOfTwo = checkIfPowerOfTwo(number);
				if (isPowerOfTwo == true)
				{
					cout << "\nThe number " << number << " is a power of 2\n\n";
				}
				else if (isPowerOfTwo == false)
				{
					cout << "\nThe number " << number << " is not a power of 2\n\n";
				}
			} while (number != 0);
			

			return 0;
		}