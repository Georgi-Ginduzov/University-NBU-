#include <iostream>

int main() {
	int array[]{-1, 2, 8, -10, 4, 7, -15, 13, 8, 0};
	int flag = 0;
	int max = array[0];

	for (int i = 1; i < 10; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
			flag = i;
		}
	}
	std::cout << "Max element is number: " << flag << " with value: " << max;
}