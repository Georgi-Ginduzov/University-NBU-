#include <iostream>
#include <string>

int main() {
	char surname[] = { 'g', 'i', 'n', 'd', 'u', 'z', 'o', 'v' };
	char searchFrom[] = { 'a', 'b', 'c', 'd' };
	int checks = 1;
	int surnameSize = sizeof(surname) / sizeof(surname[0]);
	char last = searchFrom[3];
	int k = 0;
	
	for (int k = 0; k < surnameSize; k++)
	{
		searchFrom[3] = surname[k];
		int i = 0;

		std::cout << checks++ << ". " << searchFrom[i] << " ti " << surname[k] << " li si?\n";
		while (searchFrom[i] != surname[k])
		{
			i++;
			std::cout << checks++ << ". " << searchFrom[i] << " ti " << surname[k] << " li si?\n";
		}
		std::cout << std::endl;

		searchFrom[3] = last;

		if (i < 3 || last == surname[k])
		{
			std::cout << "\nFound -> " << searchFrom[i] << " is equal to " << surname[k] << "\n\n";
		}
	}
	return 0;
}