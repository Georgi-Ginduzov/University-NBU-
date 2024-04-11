#include <iostream>
#include <map>

int findMax(int arr[], int n) {
	int max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

int* CountingSort(int arr[], int n) {
	/*std::map<int, int> numbers;

	for (int i = 0; i < n; i++)
	{
		if (numbers.find(arr[i]) == numbers.end())
		{
			numbers[arr[i]] = 1;
		}
		else
		{
			numbers[arr[i]]++;
		}
	}*/

	int max = findMax(arr, n);
	int* numberCountingArr = new int[n+1] {0};

	for (int i = 0; i < n; i++)
	{
		numberCountingArr[arr[i]]++;
	}

	return arr;
}

int main() {

	CountingSort(new int[6]{ 1, 4, 1, 2, 7, 4 }, 6);

	return 0;
}