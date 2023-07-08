#include <iostream>

	int main() {
		const int size = 6;
		int arr[size]{ 1, 0, 8, 4, 7, 0 };
		int searchFor[]{ 1, 2, 3, 4 };

		for (int i = 0; i < size; i++)
		{
			for (int k = 0; k < 4; k++)
			{
				std::cout << arr[i]<<" ti " << searchFor[k] << " li si?" << std::endl;
				if (arr[i] == searchFor[k])
				{
					std::cout << "Da" << std::endl;
				}
			}
		}

		return 0;
	}