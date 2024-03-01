#include "Money.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

	int main() {
		Money m;
		Money p;
		float n;
		
		cout << "Object m: \n";
		cin >> m;

		cout << "p: \n";
		cin >> p;

		Money o = p + m;

		cout << o;
		return 0;
	}