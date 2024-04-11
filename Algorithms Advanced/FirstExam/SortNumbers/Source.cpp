#include <iostream>
#include <vector>
#include <algorithm>

bool compare(int a, int b, int m) {
    int remainderA = a % m;
    int remainderB = b % m;
    if (remainderA == remainderB) {
        return a < b; 
    }
    return remainderA < remainderB; 
}

void sortNumbers(int m, std::vector<int>& arr, int N) {
    if (N < 1)
    {
        return;
    }
    std::sort(arr.begin(), arr.end(), [m](int a, int b) { return compare(a, b, m); });

}

int compareFunction(int a, int b, int m)
{
	int remainderA = a % m;
	int remainderB = b % m;
    if (remainderA == remainderB) {
		return a < b;
	}
	return remainderA < remainderB ? a : b;
}


int main() {
    int m, N;
    std::cin >> m >> N;

    std::vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }

    for (int i = 1; i < N; i++)
    {
        compareFunction(arr[i], arr[i+1], m);
        
    }

    for (int i = 0; i < N; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
