#include <iostream>
#include <stdlib.h> 
#include <time.h> 

int binarySearch(int a[], int item, int low, int high)
{
	if (high <= low)
		return (item > a[low]) ? (low + 1) : low;

	int mid = (low + high) / 2;
	if(item == a[mid])
		return mid + 1;
	if(item > a[mid])
		return binarySearch(a, item, mid + 1, high);
	return binarySearch(a, item, low, mid - 1);
}

int main()
{
    srand(time(NULL)); //initialize rand numbers generator

	const int size = 7;
    int arr[size];
	
	std::cout << "Random unsorted array:";
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
		std::cout << " " << arr[i];
	}

	int location, high, selected;

	for (int i = 1; i < size; i++) //Binary insertion
	{
		high = i - 1;
		selected = arr[i];

		location = binarySearch(arr, selected, 0, high);

		while (high >= location)
		{
			arr[high + 1] = arr[high];
			high--;
		}
		arr[high + 1] = selected;
	}

	std::cout << "\nSorted array:";
	for (int i = 0; i < size; i++)
	{
		std::cout << " " << arr[i];
	}
}	