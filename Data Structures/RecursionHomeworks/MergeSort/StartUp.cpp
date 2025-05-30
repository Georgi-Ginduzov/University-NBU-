﻿#include <iostream>
using namespace std;

void merge(int array[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int* left_array = new int[n1];
    int* right_array = new int[n2];

    cout << "Lqv podmasiv: ";
    for (int i = 0; i < n1; i++) {
        left_array[i] = array[left + i];
        cout << left_array[i] << " "; // corrected here
    }
    cout << "\nDesen podmasiv: ";
    for (int j = 0; j < n2; j++) {
        right_array[j] = array[middle + 1 + j];
        cout << right_array[j] << " "; // corrected here
    }

    int i = 0;
    int j = 0;
    int k = left;

    std::cout << "\nSlivam v C";
    while (i < n1 && j < n2) {
        if (left_array[i] <= right_array[j]) {
            array[k] = left_array[i];
            i++;
        }
        else {
            array[k] = right_array[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        std::cout << "\nPrehvurlqm v A";
        array[k] = left_array[i];
        i++;
        k++;
    }
    while (j < n2) {
        std::cout << "\nPrehvurlqm v B";
        array[k] = right_array[j];
        j++;
        k++;
    }
}

void merge_sort(int array[], int left, int right) {
    if (left < right) {

        int middle = left + (right - left) / 2;
        std::cout << "\nPotuvam nalqvo - granici lqv " << left << " i desen " << right;
        merge_sort(array, left, middle);
        std::cout << "\nPotuvam nadqsno - granici desen " << left << " i desen " << right;
        merge_sort(array, middle + 1, right);

        merge(array, left, middle, right);
        std::cout << "\nSlqh gi i sa naredeni ot index " << left << " do index " << right;
    }
}

int main() {
    int array[] = { 1, 2, 3, 4, 5, 6 };
    int size = sizeof(array) / sizeof(array[0]);

    merge_sort(array, 0, size - 1);

    return 0;
}
