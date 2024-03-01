#include <iostream>
#include <cmath>

	using std::cin;
	using std::cout;
	using std::endl;

		void newSet(int* set1, int size, int* set2, unsigned* set3) {


			for (int i = 0; i < size; i++)
			{
				set3[i] = set1[i] - set2[i];
			}

		}

		int main() {

			int set1[10] = { 6, 11, 8, 2, 5, 0, 0, 0, 0, 0 };
			int set2[10] = { 5, 2, 3, 8, 1, 6 ,4, 12, 9, 10 };

			int size = 10;
			unsigned set3[10]{ 0 };
			newSet(set1, size, set2, set3);

			for (int i = 0; i < 10; i++)
			{
				cout << set3[i] << '\t';

			}
			return 0;
		}