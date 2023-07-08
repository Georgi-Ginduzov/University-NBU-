#include <iostream>

int main() {
	
	int a[]{ 2, 1, 4, 0, 6, 8, 1, 4, 7 };
	int size = 9, flag = 0;

	for (int i = 0; i < size; i++)
	{
		int min = a[i];
		int flag = i;
		std::cout << "Sustoqnie " << i << "\n";
		for (int j = 0; j < size; j++)
		{
			std::cout << a[j] << ", ";
		}
		int counter = 0;
		for (int k = i + 1; k < size; k++)
		{
			counter++;
			if (a[k] < min)
			{
				min = a[k];
				flag = k;
			}
		}
		std::cout << "\nObhojdane " << i << ": sravneniq " << counter << "\n";
		a[flag] = a[i];
		a[i] = min;
	}

	return 0;
}