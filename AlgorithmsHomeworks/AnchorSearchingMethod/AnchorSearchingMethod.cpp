#include <iostream>
#include <string>

	int main() {
		/*const int size = 9;
		int arr[size]{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		int last = arr[size - 1];
		int searchFor = 0;
		arr[size - 1] = searchFor;*/
		int i = 0;

		char surname[] = { 'g', 'i', 'n', 'd', 'u', 'z', 'o', 'v' };
		char search[] = { 'a', 'b', 'c', 'd' };
		
		for (int i = 0; i < sizeof(search) / sizeof(search[0]); i++)
		{
			char last = surname[sizeof(surname) / sizeof(surname[0]) - 1];
			surname[sizeof(surname) / sizeof(surname[0]) - 1] = search[i];
			int k = 0;
			while (surname[i] != search[k])
			{
				k++;
				std::cout << k << "\n";
			}
			if (k < sizeof(search) / sizeof(search[0]) - 1 )
			{

			}
		}
		
		return 0;
	}