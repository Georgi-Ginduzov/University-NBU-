#include <iostream>
#include <cstdlib>
#include <ctime>	

void hanoi(int n, int from, int to, int help) {
	if (n > 1)
	{
		hanoi(n - 1, from, help, to);
		std::cout << "Premesti edin disk ot " << from << " pri " << to << std::endl;
		hanoi(n - 1, help, to, from);
	}
	else
	{
		std::cout << "Premesti edin disk ot " << from << " pri " << to << std::endl;
	}
}

int main() {
	time_t t0, t1;
	clock_t c0, c1;
	srand(time(NULL));
	int n =3, from = 1, to = 3, help = 2;

	t0 = time(NULL);
	c0 = clock();

	hanoi(n, from, to, help);

	c1 = clock();
	t1 = time(NULL);

	std::cout << "elapsed wall clock time: " << ((long)(t1 - t0)) << std::endl;
	std::cout << "elapsed wall clock time:" << (float)(c1 -
		c0) / CLOCKS_PER_SEC << std::endl;
}