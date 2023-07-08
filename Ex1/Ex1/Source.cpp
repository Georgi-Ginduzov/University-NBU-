#include <iostream>

	using std::cout;
	using std::cin;
	using std::endl;
	using std::string;

		double averageArithmetic(int set1[], int set2[], int set3[], double average)
		{
			int sum1 = 0;
			int sum2 = 0;
			int k = 0;

			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 5; j++)
				{

					if (set2[i] == set1[j])
					{
						set3[k++] = set2[i];
					}
				}
			}

			for (int i = 0; i < 10; i++)
			{
				sum1 += set2[i];
			}
			for (int i = 0; i < 4; i++)
			{
				sum2 += set3[i];
			}

			average = (1.0 * (sum1 - sum2)) / 6;

			return average;
		}

		string set(string set1, string set2, char set3[10])
		{

			int k = 0;
			int l = 5;

			for (int i = 0; i < 10; i++)
			{
				if (i % 2 == 0)
				{
					set3[k++] = set1[i];
				}
			}

			for (int i = 0; i < 8; i++) // eDwBN
			{
				for (int j = 0; j < 5; j++)
				{
					if (tolower(set2[i]) == tolower(set3[j]))
					{
						break;
					}
				}
				for (int j = 0; j < 10; j++)
				{

					if (i % 2 != 0 && set3[j] != (char)-52)
					{
						set3[l++] = set2[i];
					}

				}

			}

			for (size_t i = 0; i < 10; i++)
			{

				cout << set3[i];
			}

			return set3;
		}

		int main() {

			int set1 [] = { 6, 11, 8, 2, 5 };
			int set2 [] = { 5, 2, 3, 8, 1, 6, 4, 12, 9, 10 };
			//int set2[] = { 6, 11, 8, 3, 4 };
			int set3[4];			
			double average = 0;			

			average = averageArithmetic(set1, set2, set3, average);

			cout << average;


			string set1 = "erDUwmBxNz";
			string set2 = "mdrDUwaW";
			char set3[10];

			return 0;
		}