#include <iostream>

	using std::cout;

		int main() {
			int i = 1;
			
		start:
			if (i > 0)
			{
				i++;
				goto start;
			}			
			cout << "Prepulnih i = " << i << "\n\n\n\n";
			return 0;
		}