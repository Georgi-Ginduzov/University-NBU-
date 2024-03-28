#include <iostream>
#include <algorithm>

struct item {
	int itemNumber;
	int profit;
	int weight;
	float ppw;
};

bool compare(item a, item b) {
	return a.ppw > b.ppw;
}

float fractionalKnapsack(int capacity, item arr[], int n) {
	for (int i = 0; i < n; i++)
	{
		arr[i].ppw = ((float)arr[i].profit / arr[i].weight);
	}

	std::sort(arr, arr + n, compare);

	float max = 0.0;
	int i = 0;

	while (capacity > 0  && i <= n - 1)
	{
		if (capacity >= arr[i].weight)
		{
			max = max + (float)arr[i].profit;
			capacity -= arr[i].weight;
		}
		else
		{
			max += (capacity * arr[i].ppw);
		}

		i++;
	}

	return max;
}

int main() {
	int c = 25;
	item arr[] = { (1, 30, 10, 0), (2, 20, 5, 0), (3, 40, 15, 0), (4, 36, 8, 0) };

	std::cout << "Result: " << fractionalKnapsack(c, arr, 4);
	


	return 0;
}