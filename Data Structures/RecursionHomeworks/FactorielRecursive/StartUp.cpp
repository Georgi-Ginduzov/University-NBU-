#include <iostream>

int factoriel(int number) {
	if (number > 1)
	{
		std::cout << "Potuvane: n=" << number << "\n";
		return number * factoriel(number - 1);
	}
	else
	{
		std::cout << "Izpluvane: n=" << number << std::endl;
		return 1;
	}
}

int main() {
	int number;
	std::cin >> number;
	std::cout << factoriel(number);

	return 0;
}