#include <iostream>

int main() {
	const int N = 2000;
	int arr[N], i = 0;
	
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 10000;;
	}

	for (int i = 0; i < N; i++)
	{
		int min = arr[i];
		int key = i;
		for (int j = i + 1; j < N; j++)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				key = j;
			}
		}
		arr[key] = arr[i];
		arr[i] = min;
	}



	return 0;
}