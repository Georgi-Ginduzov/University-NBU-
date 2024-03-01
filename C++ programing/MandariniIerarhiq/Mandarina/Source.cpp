#include <iostream>
#include "Tangerine.h"
using std::cin;
using std::cout;
using std::endl;

int main() {

	Tangerine tan(3.33, true, false, 11.0);

	tan.getRadius();
	tan.eat();

	return 0;
}