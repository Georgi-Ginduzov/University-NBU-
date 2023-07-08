#include <iostream>

	using std::cout;
	using std::cin;
	using std::endl;

		int findMaxIndex(int* arr, int n) {
			int index = 0;
			int max = arr[0];

			for (int i = 0; i < n; i++)
			{
				if (arr[i] > max)
				{
					max = arr[i];
					index = i;
				}
			}
			return max;
		}

		int findMinIndex(int* arr, int n) {
			int index = 0;
			int min = arr[0];

			for (int i = 0; i < n; i++)
			{
				if (arr[i] < min)
				{
					min = arr[i];
					index = i;
				}
			}
			return min;
		}

		int main() {
			
			// Find min value
			int arr[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

			int min = arr[0];
			int index;

			for (int i = 0; i < 9; i++)
			{
				if (arr[i] < min)
				{
					min = arr[i];
					index = i;
				}
			}

			cout << "Min number: " << min << "\nPosition in array: " << index;

			// 
			int minIndex = 0;
			int maxIndex = 0;
			const int size = 5;
			int arr2[]{ 1, 2, -3, 4, 5 };
			int newArr2[size]{};

			for (int i = 0; i < size; i++)
			{
				minIndex = findMinIndex(arr, size);
				newArr2[i] = arr2[minIndex];
				arr2[minIndex] = arr[maxIndex];
			}

			return 0;
		}