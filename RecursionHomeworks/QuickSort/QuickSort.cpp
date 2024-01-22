#include <iostream>

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high]; 
        int i = low - 1;

        for (int j = low; j < high; j++){
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        int partition_index = i + 1;

        quicksort(arr, low, partition_index - 1);
        quicksort(arr, partition_index + 1, high);
    }
}

int main() {
    time_t t0, t1;
    clock_t c0, c1;
    const int N = 7;
    int arr[N]{ 1, 0, 8, 0, 3, 4, 2 };

    std::cout << "Unsorted array: ";
    for (int i = 0; i < N; i++) {
        std::cout << arr[i] << " ";
    }

    quicksort(arr, 0, N - 1);
    
    std::cout << "\nSorted array: ";
    for (int i = 0; i < N; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
