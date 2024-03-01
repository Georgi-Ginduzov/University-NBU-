#include <iostream>

int main() {
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	int size = 6;

	for (int i = 0; i < size; i++)
	{
		for (int k = i + 1; k < size; k++)
		{
			if (arr[i] > arr[k])
			{
				std::cout << arr[i] << ", " << arr[k] << std::endl;
			}
		}
	}

}