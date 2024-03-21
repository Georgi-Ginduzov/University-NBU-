#include <iostream>
#include <vector>

using namespace std;

int min_square(int N) {
	int DP[N + 1];
	for (int i = 0; i <= N; i++)
	{
		DP[i] = i;
	}


	DP[0] = 0;

	vector<int> a;
	for (int i = 0;; i++)
	{
		if (i * i <= N)
		{
			a.push_back(i * i);
		}
		else
		{
			break;
		}
	}
	int m = a.size();
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i >= a[j] && DP[i - a[j]] + 1 < DP[i])
			{
				DP[i] = DP[i - a[j]] + 1;
			}
		}
		return DP[N];
	}
}