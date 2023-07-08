#include <iostream>

using std::cout;
using std::cin;

int main() {
	int a[10]{ 1, 5, 2, 8, 1, 23, 4, 12, -28, 2 };
	int n = sizeof(a) / sizeof(int);

	for (int i = 1; i < n; i++)
	{
		int buff = a[i];
		int j = i - 1;

		while (j >= 0 && a[j] > buff)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = buff;
	}

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ", ";
	}
}
