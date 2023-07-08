#include <iostream>

int main() {
	int last, j;
	int arr[8]{ 5, 3, 8, 1, 6, 2, 7, 4 };
	int size = 8;

	for (int i = 0; i < size; i++)
	{
		last = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > last)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = last;
	}

	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << ", ";
	}

	return 0;
}