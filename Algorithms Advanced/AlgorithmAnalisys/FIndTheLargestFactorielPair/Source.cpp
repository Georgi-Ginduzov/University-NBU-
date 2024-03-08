#include <iostream>
#include <algorithm>

void findPair(int arr[], int n) {
	if (n < 2)
	{
		std::cout << "-1";
		return;
	}

	int x, y;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == x)
		{
			continue;
		}
		if (arr[i] > x)
		{
			y = x;
			x = arr[i];
		}
		else if (arr[i] > y)
		{
			y = arr[i];
		}
	}

	std::cout << "x, y --> " << x << y;
}

int main() {
	int n;
	std::cin >> n;

	int* arr = new int(n);

	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}

	// To do: add logic for constraints

	//std::sort(arr[0], arr[n-1]);

	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i];
	}


	// solution in class

}