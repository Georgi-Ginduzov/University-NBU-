#include <iostream>

void printMovement(int start, int end) {
	std::cout << start << " -> " << end << std::endl;
}

void hanoi(int n, int start, int end) {
	if (n == 1)
	{
		printMovement(start, end);
	}
	else
	{
		int other = 6 - (start + end);

		hanoi(n - 1, start, other);
		printMovement(start, end);
		hanoi(n - 1, other, end);
	}
}

int main() {
	time_t t0, t1;
	clock_t c0, c1;
	srand(time(NULL));
	int n = 3, start = 1, end = 3;

	t0 = time(NULL);
	c0 = clock();

	hanoi(n, start, end);

	c1 = clock();
	t1 = time(NULL);

	/*cout << "elapsed wall clock time: " << ((long)(t1 - t0)) << endl;
	cout << "elapsed wall clock time:" << (float)(c1 -
		c0) / CLOCKS_PER_SEC << endl;
	cout << "is sorted" << is_sorted(a, ARRAY_SIZE);*/

}