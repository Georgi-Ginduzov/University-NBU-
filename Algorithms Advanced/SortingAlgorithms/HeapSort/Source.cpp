#include <iostream>

void heapify(int arr[], int n, int i) {
	int largeest = i, l =  2 * i + 1, r =  2 * i + 2;

	if (l < n && arr[l] > arr[largeest])
	{
		largeest = l;
	}

	if (r < n &&  arr[r] > arr[largeest])
	{
		largeest = r;
	}

	if (largeest != i)
	{
		int buffer = arr[i];
		arr[i] = arr[largeest];
		arr[largeest] = buffer;

		heapify(arr, n, largeest);
	}
}

void heapSort(int arr[], int n) {
	for (int i = n/2 - 1; i >= 0; i--)
	{
		heapify(arr, n, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		int buff = arr[0];
		arr[0] = arr[i];
		arr[i] = buff;

		heapify(arr, n, 0);
	}
}

int main() {




	return 0;
}