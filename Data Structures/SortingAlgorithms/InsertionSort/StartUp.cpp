#include <iostream>
#include <time.h>

int main() {
	srand(time(NULL));

	int arr[6];
	std::cout << "Unsorted array: ";
	for (int i = 0; i < 6; i++)
	{
		arr[i] = rand() % 30;
		std::cout << arr[i] << ", ";
	}

    int i, key, j;
    for (i = 1; i < 6; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

	std::cout << "\nSorted array: ";
	for (int i = 0; i < 6; i++)
	{
		std::cout << arr[i] << ", ";
	}

	return 0;
}