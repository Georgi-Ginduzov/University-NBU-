#include <iostream>

int main() {

	int arr[]{ 1, 0, 8, 4, 7, 0 };
	int arrSize = 6;
	bool inversion = true;

	int i = 0;
	while (inversion == true)
	{
		inversion = false;
		std::cout << "i = " << i << "\n";
		for (int j = 0; j < arrSize - i - 1; j++)
		{
			std::cout << arr[j] << " > " << arr[j + 1] << "\n";
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				inversion = true;
			}
		}
		i++;
	}
	for (int k = 0; k < arrSize; k++)
	{
		std::cout << arr[k] << ", ";
	}
	return 0;
}