#include <iostream>
#include <map>
#include <stack>

using namespace std;

int findTheHighestSum(int arr[], int arrSize, int n) {
	// Validation logic

	int x, y, z;
	stack<map<int, int>> stack;
	stack.push(0, arr[0]);

	for (int i = 1; i < n; i++)
	{
		
		/*if (arr[i] > stack.top())
		{
			stack.push(arr[i]);
		}*/
	}


}

int main() {
	int arr[5]{ 1, 8, 2, 9, 3 };
	int numbers = 3;

	// pair can be used
}