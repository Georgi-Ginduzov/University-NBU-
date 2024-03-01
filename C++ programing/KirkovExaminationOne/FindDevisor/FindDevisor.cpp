#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int findDivisors(int number, int* divisors) {
	int k = 0;
	for (int i = 1; i <= number / 2; i++)
	{
		if (number % i == 0)
		{
			divisors[k++] = i;
		}
	}
	return *divisors;
}

int main() {
	int number;

	cout << "Enter a number: ";
	cin >> number;

	int size = floor(std::sqrt(number)) + 1;
	int* divisors = new int[size];
	*divisors = findDivisors(number, divisors);

	for (int i = 0; i < size; i++)
	{
		if (divisors[i] != 0 && divisors[i] != -842150451)
		{
			cout << divisors[i] << ", ";
		}
		
	}
}