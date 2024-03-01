#include <iostream>

	int main() {
		int n;
		std::cin >> n;
		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			sum = sum + ((i * i * i) - (2 * i));
		}
		std::cout << sum;
		return 0;
	}