#include <iostream>
#include <cstdlib>
#include <ctime>	

void quicksort(int arr[], int low, int high) {
	if (low < high) {
		int pivot = arr[low];
		int i = high;

		for (int j = high; j > low; j--) {
			if (arr[j] > pivot) {
				int temp = arr[i];
				arr[i--] = arr[j];
				arr[j] = temp;
			}
		}
		int temp = arr[i];//low with i 
		arr[i] = arr[low];
		arr[low] = temp;

		quicksort(arr, low, i - 1);
		quicksort(arr, i + 1, high);
	}
}

int main() {
	time_t t0, t1;
	clock_t c0, c1;
	const int N = 2000;
	int arr[N],ar[N], i = 0;
	
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 10000;;
		ar[i] = arr[i];
	}

	t0 = time(NULL);
	c0 = clock();
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
	c1 = clock();
	t1 = time(NULL);

	std::cout << "elapsed selection sort wall clock time: " << ((long)(t1 - t0)) << std::endl;
	std::cout << "elapsed selection sort wall clock time:" << (float)(c1 - c0) / CLOCKS_PER_SEC << std::endl;
	
	t0 = time(NULL);
	c0 = clock();
	quicksort(ar, 0, N - 1);
	c1 = clock();
	t1 = time(NULL);

	std::cout << "elapsed quick sort wall clock time: " << ((long)(t1 - t0)) << std::endl;
	std::cout << "elapsed quick sort wall clock time:" << (float)(c1 - c0) / CLOCKS_PER_SEC << std::endl;
	return 0;
}