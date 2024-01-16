#include <iostream>

int factoriel(int number) {
	if (number > 1)
	{
		return number * factoriel(number - 1);
	}
	else
	{
		return 1;
	}
}

int main() {
	int number;
	std::cin >> number;
	std::cout << factoriel(number);

	return 0;
}