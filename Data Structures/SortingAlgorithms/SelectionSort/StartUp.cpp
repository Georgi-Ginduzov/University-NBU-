#include <iostream>
#include <cstdlib>
#include <ctime>	

int main() {
	time_t t0, t1;
	clock_t c0, c1;
	const int N = 100000;
	int arr[N], i = 0;
	srand(time(NULL));

	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 100000;
	}

	t0 = time(NULL);
	c0 = clock();
	for (int i = 0; i < N; i++)
	{
		int min = arr[i];
		int key = i;
		for (int j = i + 1; j < N; j++)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				key = j;
			}
		}
		arr[key] = arr[i];
		arr[i] = min;
	}
	c1 = clock();
	t1 = time(NULL);

	std::cout << "elapsed wall clock time: " << ((long)(t1 - t0)) << std::endl;
	std::cout << "elapsed wall clock time:" << (float)(c1 - c0) / CLOCKS_PER_SEC << std::endl;
	return 0;
}