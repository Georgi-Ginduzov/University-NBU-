#include <iostream>

int main()
{
	int arr[] = { 1, 0, 8, 4, 7 };
	int size = 5, i, buff, j;
	
	for (i = 1; i < size; i++) {
		buff = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > buff) {// 13 > 5; swap; 11 > 5; swap; 
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = buff;
	}

	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << ", ";
	}
	return 0;
}