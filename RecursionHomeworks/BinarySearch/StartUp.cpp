#include <iostream>

int binarySearch(int a[], int item, int low, int high)
{
	if (high <= low)
		return (item > a[low]) ? (low + 1) : low;

	int mid = (low + high) / 2;
	if (item == a[mid]) {
		std::cout << "Found! " << item << " == " << a[mid];
		return mid + 1;
	}
	else if (item > a[mid]) {
		std::cout << item << " > " << a[mid] << "\n";
		return binarySearch(a, item, mid + 1, high);
	}
	return binarySearch(a, item, low, mid - 1);
}

int main() {
	int arr[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int n;
	std::cin >> n;

	binarySearch(arr, n, 0, 9);

	return 0;
}