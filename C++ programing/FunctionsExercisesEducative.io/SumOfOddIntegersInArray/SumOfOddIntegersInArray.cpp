#include <iostream>

	using std::cout;

    int secondMinimum(int arr[], int size) {
        int minNumber = 214748364;
        int secondmin = 214748364;
        int leastSum = 214748364;
        int sum = 0;

        for (int i = 0; i < size; i++) {
            if (arr[i] < minNumber) {
                minNumber = arr[i];
            }
        }

        for (int i = 0; i < size; i++) {
            sum = arr[i] + minNumber;
            if (sum < leastSum && sum != minNumber * 2) {
                leastSum = sum;
            }
        }

        secondmin = leastSum - minNumber;

        return secondmin;
    }

	int main() {

        int arr[]{ 1, 3, 5, 7, 9 };
        int size = 5;
        int minNum = secondMinimum(arr, size);

        cout << minNum;
		

		return 0;
	}