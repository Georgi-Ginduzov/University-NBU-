#include <iostream>

using std::cout;
using std::cin;

int getCount(int X, int y, int Z) {
	int br = 0;
	for (int x = 1; x <= X; x++)
	{
		int z = (y / x) + 1;
		if (Z >= z)
		{
			br = (br + (Z - z) + 1);
		}
		if (X >= z && Z>= x)
		{
			br = (br + (Z - x + 1) * (X - z + 1));
		}
		if (X >= z)
		{
			X = z - 1;
		}
	}

	return br;
}

int countTriplets(int X, int Y, int Z) {
	int br = 0;
	for (int y = 1; y <= Y; y++)
	{
		br = (br + getCount(X, x * y, Z)); 
	}
	return br;
}

int main() {
	int X;
	int Y;
	int Z;
	int counter = 0;

	cin >> X;
	cin >> Y;
	cin >> Z;

	for (int i = 1; i <= X; i++)
	{
		for (int j = 1; j <= Z; j++)
		{
			for (int k = 1; k <= Y; k++)
			{
				if (i * j > k * k)
				{
					counter++;
				}
			}
		}
	}
	
	cout << counter;

	int versions = X * Y * Z;

	for (int x = X; x > 0; x--)
	{
		for (int z = Z; z > 0; z--) 
		{
			for (int y = 0; y > 0; y--)
			{
				if (true)
				{

				}
			}
		}
	}




}