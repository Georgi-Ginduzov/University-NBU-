#include <iostream>
#include <time.h>

int main() {
	time_t t0, t1;
	clock_t c0, c1;
	const int N = 10000;
	int arr[N];
	srand(time(NULL));

	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 100000;
	}

	t0 = time(NULL);
	c0 = clock();
    int i, key, j;
    for (i = 1; i < N; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
	c1 = clock();
	t1 = time(NULL);

	std::cout << "elapsed wall clock time: " << ((long)(t1 - t0)) << std::endl;
	std::cout << "elapsed wall clock time:" << (float)(c1 - c0) / CLOCKS_PER_SEC << std::endl;
	return 0;
}