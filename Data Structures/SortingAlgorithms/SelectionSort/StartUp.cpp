#include <iostream>
#include <time.h>

int main() {
	srand(time(NULL));

	int arr[6], i = 0;
	std::cout << "Unsorted array: ";
	for (int i = 0; i < 6; i++)
	{
		arr[i] = rand() % 30;
		std::cout << arr[i] << ", ";
	}

	for (int i = 0; i < 6; i++)
	{
		int min = arr[i];
		int key = i;
		for (int j = i + 1; j < 6; j++)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				key = j;
			}
		}

		arr[key] = arr[i];
		arr[i] = min;

	}

	std::cout << "\nSorted array: ";
	for (int i = 0; i < 6; i++)
	{
		std::cout << arr[i] << ", ";
	}

	return 0;
}