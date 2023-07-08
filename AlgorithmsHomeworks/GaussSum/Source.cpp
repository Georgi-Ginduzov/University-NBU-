#include <iostream>

	using std::cout;

	int gaussSum(int n, int sum) {
		return sum = ((n + 1) * n) / 2;
	}

	int main() {
		cout << "Faculty number: F108470" << std::endl << "n = 6\n";

		int n = 6, sum = 0;

		sum = gaussSum(n, sum);

		cout << "Using Gauss's method sum = " << sum << std::endl;

		sum = 0;

		cout << "Check:" << std::endl;

		for (int i = 1; i <= n; i++)
		{
			cout << "Sum = " << sum << " + " << i << " = " << sum + i << '\n';
			sum = sum + i;
		}
		return 0;
	}