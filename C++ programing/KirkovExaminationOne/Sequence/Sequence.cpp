#include <iostream>

int sequence(int n, int k, int sum) {
	for (int i = 1; i <= n; i++)
	{
		std::cout << ((i + 1) + (k * i)) << '\t';
		sum += ((i + 1) + (k * i));
	}
	return sum;
}

int main() {
	int k, n, sum = 0;

	std::cout << "Enter k: ";
	std::cin >> k;
	std::cout << "Enter n: ";
	std::cin >> n;

	sum = sequence(n, k, sum);
	std::cout << "\nThe sum is: " << sum;

}