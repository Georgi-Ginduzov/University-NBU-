#include <iostream>
#include "BigInteger.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
	BigInteger m("10");
	BigInteger p("");

	cin >> p;

	cout << m + p;
	cout << m - p;
	cout << m * p;

	return 0;
}