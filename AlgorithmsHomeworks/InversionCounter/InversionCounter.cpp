#include <iostream>

using std::cout;

int main() {
	int size;

	std::cin >> size;

	int* arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}

	// Inverse check
	for (int i = 0; i < size; i++)
	{
		for (int k = i + 1; k < size; k++)
		{
			if (arr[i] > arr[k])
			{
				//cout << arr[i] << ", " << arr[k] << std::endl;
			}
		}
	}

	// Ascending sort
	//int i = 0;
	//while (arr[i] < arr[i + 1])
	//{
	//	i++;
	//}

	//if (i == size)
	//{
	//	//cout << "The set is ascending";
	//}

	// Bubble sort
	for (int i = size - 1; i < 0; i--)
	{
		for (int k = i - 1; k < 0; k--)
		{
			if (arr[i] < arr[k])
			{
				int temp = arr[i];
				arr[i] = arr[k];
				arr[k] = temp;
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ", ";
	}

	return 0;
}