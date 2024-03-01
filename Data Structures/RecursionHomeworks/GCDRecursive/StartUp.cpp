#include <iostream>

int c;
int gcd(int a, int b) {
	if (a % b != 0)
	{
		std::cout << "Potuvane:\na = " << a << std::endl;
		c = a % b;
		return gcd(b, c);
	}
	else
	{
		std::cout << "Izpluvane:\nb = " << b << std::endl;
		return b;
	}
}

int main() {
	int a, b;// fibonacci - 55, 34
	std::cin >> a;
	std::cin >> b;

	if (a > b)
	{
		std::cout << gcd(a, b);
	}
	else
	{
		std::cout << gcd(b, a);
	}	

	return 0;
}