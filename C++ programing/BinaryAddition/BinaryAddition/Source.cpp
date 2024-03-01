#include <iostream>

	using std::cout;
	using std::cin;
	using std::endl;
	using std::string;

		int stringToInteger(string number, int* binaryNum) {

			for (size_t i = 0; i < number.size(); i++)
			{
				binaryNum[i] = (char)number[i] - 48;
			}
			return*binaryNum;
		}

		int addBinary(int* firstNumber, int* secondNumber, int* sum) {
			
			int remainder = 0;

			for (int i = 7; i > -1; i--)
			{				
				sum[i] = ((firstNumber[i] + secondNumber[i]) % 2 + remainder) % 2;


				firstNumber[i] + secondNumber[i] + remainder >= 2 ? remainder = 1 : remainder = 0;
			}
			return *sum;
		}

		int main() {

			string binaryNumber;

			int firstBinaryNumber[8];
			int secondBinaryNumber[8];

			cout << "Enter binary number(1): ";
			cin >> binaryNumber;

			stringToInteger(binaryNumber, firstBinaryNumber);

			cout << "Enter binary number(2): ";
			cin >> binaryNumber;

			stringToInteger(binaryNumber, secondBinaryNumber);

			int sum[8];

			addBinary(firstBinaryNumber, secondBinaryNumber, sum);

			cout << "            The sum is: ";

			for (size_t i = 0; i < 8; i++)
			{
				cout << sum[i];
			}

			return 0;
		}