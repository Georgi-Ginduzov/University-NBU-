#include <iostream>

int main() {
	int arr[] = { 5, 3, 8, 1, 6, 2, 7, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int left = 0, right = i - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] > key) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        for (int j = i - 1; j >= left; j--) {
            arr[j + 1] = arr[j];
        }
        arr[left] = key;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << ", ";
    }
	return 0;
}