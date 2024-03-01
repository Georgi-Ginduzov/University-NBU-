#include <iostream>

	using std::cout;
	using std::cin;
	using std::endl;
	using std::string;

		//zad1
		void print_subset(char* universalSet, int* subset, int n, int m)
		{
			int count = 0;

			cout << "The first " << m
				<< " characters in A are: ";

			for (int i = 0; i < 20; i++) {
				if (subset[i] == 1 && (universalSet[i] >= 'a' && universalSet[i] <= 'k') || (universalSet[i] >= 'A' && universalSet[i] <= 'K')) {
					cout << universalSet[i];
					count++;
					if (count == m)
						break;
				}
			}
			cout << endl;
		}

		string encodeThisSymbols(string sentence, string symbols, char* encoded) {
			
			
			for (int i = 0; i < 32; i++)
			{
				int counter = 0;
				
				for (int j = 0; j < 5; j++)
				{
					if (sentence[i] != symbols[j])
					{
						counter++;						
					}
					
				}
				if (counter == 5 && sentence[i] != (char)32)
				{

					sentence[i] = (char)35;
				}
				cout << endl;
			}

			return sentence;
		}

		

		//zad3

		int setSum(int* set, int sum) {

			for (int i = 0; i <= 9; i++)
			{
				sum += set[i];
			}

			return sum;
		}

		int subsetSum(int* set, int sum) {

			for (int i = 0; i < 10; i++)
			{
				if (set[i] >= set[0] && set[i] <= set[9])
				{
					sum += set[i];
				}
			}

			return sum;
		}

		int gcd(int a, int b)
		{
			if (b == 0)
				return a;
			return gcd(b, a % b);
		}

		int main()
		{
			//zad1
			const int N = 20;

			char universalSet[N]{ 'w', 'b', 'U', 'c', 'A', 'K', 'X', 'a', 'e', 'Z' };
			int subset[N] = { 0, 1, 1, 0, 1, 1, 1, 0, 1, 1 };
			int m = 4;
			
			print_subset(universalSet, subset, N, m);
			
			//zad2
			string sentence = "Sherlock is a private detective.";
			string encodeThis = "etisp";
			char encoded[] {"################################"};			

			cout << encodeThisSymbols(sentence, encodeThis, encoded);
			



			//zad3
			
			int set1[]{ 5, 2, 3, 8, 1, 6, 4, 12, 9, 7 };
			int sum = 0;

			int a = setSum(set1, sum) - subsetSum(set1, sum);
			int b = subsetSum(set1, sum);

			cout << gcd(a, b);
			
			return 0;
		}