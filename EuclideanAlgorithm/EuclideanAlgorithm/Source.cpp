#include <iostream>

		int swap(int a,int b) {
			a = a ^ b;
			b = a ^ b;
			a = a ^ b;

			return a, b;
		}

		auto gcd(int a, int b) {
			a > b ? a > b : swap(a, b);

			if (b == 0)
			{
				return a;
			}
			
			int c = a % b;
			a = b;
			b = c;	

			return gcd(a, b);
		}

		int main() {
			int a, b;

			std::cin >> a >> b;
			
			a = gcd(a, b);

			std::cout << "Gcd: " << a;

			return 0;
		}