#include <iostream>
#include <math.h>

	using namespace std;

	int sumAlg(int n, int sum) {

		for (int i = 1; i < n; i++)
		{
			sum = sum + pow(i, i) - (i * i);
		}
		return sum;
	}

	int quarterPi(int sum) {
		for (int i = 1; i < 100000; i++)
		{
			sum = sum + pow(-1, i % 2) * (1 / (2 * i - 1)); // How to make it multiply by 1 then -1 and vice versa without multiplying by 100 000
		}
		return sum;
	}

	int factoriel(int factoriel, int n) {

		for (int i = 1; i <= n; i++)
		{
			factoriel = factoriel * i;
		}
		return factoriel;
	}

	int main() {

		int sum = 0, n;

		cout << "Enter n: ";
		cin >> n;

		cout << "The sum is " << sum;

		sum = quarterPi(sum);

		cout << "A quarter of pi is equal to " << sum;

		return 0;
	}