#include <iostream>

	using std::cin;
	using std::cout;
	using std::endl;

		bool id_FirstPart(int* number, int* dateOfBirth) { // Checks the date

			int shift = 6;

			for (int i = 0; i < 6; i++)
			{
				if (i + shift == 8)
				{
					shift = 0;
				}

				if (i == 4)
				{
					shift = 4;
				}

				if (number[i] != dateOfBirth[i + shift])
				{
					return false;
				}

			}

			
		}

		int main() {



			return 0;
		}