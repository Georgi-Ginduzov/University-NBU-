 #include <iostream>

int main() {
	int a, b, c;

	std::cin >> a >> b;

	if (b > a) {
		int temp = a;
		a = b;
		b = temp;
	}

	euclid:
	c = a % b;
	a = b;
	b = c;
	if (b != 0)
		goto euclid;

	std::cout << a;

	return 0;
}