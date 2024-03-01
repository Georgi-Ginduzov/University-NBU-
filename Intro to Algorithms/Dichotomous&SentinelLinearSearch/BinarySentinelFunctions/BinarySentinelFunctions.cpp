#include <iostream>

int linearSearch(const int* array, int arraySize, const int* target, int targetSize) {
    for (int i = 0; i < arraySize; i++) {
        bool found = true;
        for (int j = 0; j < targetSize; j++) {
            if (array[i + j] != target[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            return i; // Return the starting index if found
        }
    }
    return -1; // Return -1 if not found
}

int anchorSearch(int* array, int arraySize, const int* target, int targetSize) {
    int anchor = array[arraySize - 1]; // Set the anchor to the last element
    array[arraySize - 1] = target[0]; // Replace the last element with the first element of the target array

    int i = 0;
    while (true) {
        bool found = true;
        for (int j = 0; j < targetSize; j++) {
            if (array[i + j] != target[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            break;
        }
        i++;
    }

    array[arraySize - 1] = anchor; // Restore the last element to its original value

    if (i < arraySize - 1 || targetSize == 1) {
        return i; // Return the starting index if found
    }
    else {
        return -1; // Return -1 if not found
    }
}

int dichotomousSearch(const int* array, int arraySize, const int* target, int targetSize) {
    int beginning = 0;
    int end = arraySize - targetSize;

    while (beginning <= end) {
        int middle = (beginning + end) / 2;

        bool found = true;
        for (int i = 0; i < targetSize; i++) {
            if (array[middle + i] != target[i]) {
                found = false;
                break;
            }
        }

        if (found) {
            return middle; // Return the starting index if found
        }
        else if (array[middle] < target[0]) {
            beginning = middle + 1;
        }
        else {
            end = middle - 1;
        }
    }

    return -1; // Return -1 if not found
}


int main() {
    int array[] = { 1, 2, 3, 4, 5, 6, 7 };
    int arraySize = sizeof(array) / sizeof(array[0]);
    int target[] = { 3, 4, 5 };
    int targetSize = sizeof(target) / sizeof(target[0]);

    int index = linearSearch(array, arraySize, target, targetSize);
    if (index != -1) {
        std::cout << "Target found at index: " << index << std::endl;
    }
    else {
        std::cout << "Target not found in the array" << std::endl;
    }

    return 0;
}
