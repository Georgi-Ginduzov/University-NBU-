#include <iostream>

	using namespace std;

		int main() {

			const int size = 10;

			int a[size];
			int b[size];

			for (int i = 0; i < size; i++)
			{
				cin >> a[i];
			}

			
			int max = a[0];

			for (int i = 1; i < size; i++)
			{
				if (a[i] > max)
				{
					max = a[i];
				}
			}
			int count = 0;
			for (int i = 0; i < size; i++)
			{
				
				// Namirane na min
				int indexMin = 0;
				int min = a[0];

				for (int k = 1; k < size; k++)
				{
					count++;
					if (a[k] < min)
					{						
						min = a[k];
						indexMin = k;
					}
				}
				// Prenasqne na min v b
				b[i] = min;
				//Uviistvo na min
				a[indexMin] = max;
			}
			for (int i = 0; i < size; i++)
			{
				cout << b[i] << ", ";
			}
			cout << "\n" ;
			for (int i = 0; i < size; i++)
			{
				cout << a[i] << ", ";
			}
			cout << "\nProverki: " << count;
		}