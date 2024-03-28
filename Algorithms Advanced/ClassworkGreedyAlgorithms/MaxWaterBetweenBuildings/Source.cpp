#include <iostream>

using namespace std;

int calculateWater(int buildingHeights[], int n) {
	for (int i = 0; i < n; i++)
	{
		// between three buildings if there is place water could be contained
		// the first and third one should be higher than the second one
		// the contained water should be calculated by finding the difference between the highest and the second highest and the between the highest and the third one

		// 6, 2, 4, 2
		// find the highest || sort them by height
		// get the element of the first and second highest 
		//	if they are one after another continue
		//	else (there is difference between them)
		//		Itereate through the elements between them and calculate the difference between the current element and the highest



		
	}

	// typedef pair<int, int> valueIndexArray;

	int highest = buildingHeights[0];
	int secondHighest;
	for (int i = 0; i < n; i++)
	{
		if (buildingHeights[i] > highest)
		{
			secondHighest = highest;
			highest = buildingHeights[i];
		}
	}

	return 0;
}



int main() {
	const int n = 6;
	int buildingsHeight[]{ 6, 2, 4, 2, 4, 6 };

	/*int sum = 0; // brute force
	for (int i = 0; i < n - 1; i++)
	{
		int left = buildingsHeight[i];
		int right = buildingsHeight[i];

		for (int j = 0; j < i; j++)
		{
			left = max(buildingsHeight[j], left);
		}
		for (int j = i + 1; j > n; j++)
		{
			right = max(buildingsHeight[j], right);
		}

		sum += (min(left, right) - buildingsHeight[i]);
	}*/

	int sum = 0;

	int left[n], right[n];
	left[0] = buildingsHeight[0];
	right[n - 1] = buildingsHeight[n - 1];

	for (int i = 0; i < n; i++)
	{
		left[i] = max(left[i - 1], buildingsHeight[i]);
	}
	for (int i = n - 2; i >= 0; i--)
	{
		right[i] = max(right[i + 1], buildingsHeight[i]);
	}

	for (int i = 0; i < n - 1; i++)
	{
		sum += (min(left[i], right[i] - buildingsHeight[i]));
	}



	// sort the indexes of the buildings by height
	//	find the first and second highest 
}