#include <iostream>

using namespace std;

int find_length(int* arr, int n) {
	int up[n];
	int down[n];

	for (int i = 0; i < n; i++)
	{
		up[i] = 1;
		down[i] = 1;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
				up[i] = max(up[i], down[j] + 1);
			else if (arr[i] < arr[j])
				down[i] = max(down[i], up[j] + 1);
		}
	}

	int m = 0; 
	for (int i = 0; i < n; i++)
	{
		m = max(m, max(up[i], down[i]));
	}
	return m;
}

int main() {

}