#include <iostream>

int main() {

	int a[]{ 2, 1, 4, 0, 6, 8, 1, 4, 7 };
	int size = 9, flag = 0, max = a[0];

	for (int i = 0; i < size; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
			flag = i;	
		}
	}

	for (int i = 0; i < size - 2; i++)
	{
		int min = a[i];
		int flag = i;
		for (int k = i + 1; k < size; k++)
		{
			if (a[k] < min)
			{
				min = a[k];
				flag = k;
			}
		}
		a[flag] = a[i];
		a[i] = min;
	}

	for (int i = 0; i < size; i++)
	{
		std::cout << a[i] << ", ";
	}
	return 0;
}