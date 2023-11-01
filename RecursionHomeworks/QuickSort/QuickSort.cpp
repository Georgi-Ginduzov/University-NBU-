#include <iostream>
#include <vector>

void quicksort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];  // Choose the last element as the pivot
        int i = low - 1;       // Index of the smaller element

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }

        std::swap(arr[i + 1], arr[high]);
        int partition_index = i + 1;

        // Recursively sort the elements before and after the partition
        quicksort(arr, low, partition_index - 1);
        quicksort(arr, partition_index + 1, high);
    }
}

int main() {
    std::vector<int> arr = { 1, 0, 7, 0, 3, 4, 7 };
    int n = arr.size();

    std::cout << "Unsorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    quicksort(arr, 0, n - 1);

    std::cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
