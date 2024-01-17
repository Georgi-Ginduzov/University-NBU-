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

	bool swapped = true;
	while (swapped == true)
	{
		swapped = false;

		for (int j = 0; j < 6 - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = true;
			}
		}
		i++;
	}

	std::cout << "\nSorted array: ";
	for (int i = 0; i < 6; i++)
	{
		std::cout << arr[i] << ", ";
	}

	return 0;
}