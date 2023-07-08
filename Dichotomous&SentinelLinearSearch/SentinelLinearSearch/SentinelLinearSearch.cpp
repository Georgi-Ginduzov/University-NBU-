#include <iostream>

int main() {
	int array[]{ 1, 2, 3, 4 };
	int searchFor[]{ 1, 0, 8, 4, 7, 0 };
	int proverki = 1;

	for (int i = 0; i < 4; i++)
	{
		for (int  k = 0; k < 6; k++)
		{
			std::cout << proverki++ << ". " << array[i] << " ti " << searchFor[k] << " li si?\n";
			if (array[i] == searchFor[k])
			{
				std::cout << "\nFound -> " << array[k] << " is equal to " << searchFor[i] << "\n";
				break;
			}
		}
		std::cout << std::endl;
	}
	return 0;
}