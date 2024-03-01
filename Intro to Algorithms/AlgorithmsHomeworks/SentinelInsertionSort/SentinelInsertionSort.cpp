#include <iostream>

int main() {
    const int n = 6;
    int arr[n]{ 1, 0, 8, 4, 7, 0 };

    int min_idx = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[min_idx]) {
            min_idx = i;
        }
    }
    int temp = arr[0];
    arr[0] = arr[min_idx];
    arr[min_idx] = temp;

    for (int i = 1; i < n; i++) {
        int j = i;
        while (arr[j] > arr[j - 1]) {
            j--;
        }
        int key = arr[i];
        for (int k = i; k > j; k--) {
            arr[k] = arr[k - 1];
        }
        arr[j] = key;
    }

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}