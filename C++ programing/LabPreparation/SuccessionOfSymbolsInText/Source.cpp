#include <iostream>

	using std::cout;
	using std::cin;
	using std::endl;
	using std::string;

		int succession(string sentence, string symbol, int maxSuccession)
		{

			int succession = 0;

			for (int i = 0; i < 24; i++)
			{
				bool consistency = false;

				for (int j = 0; j < 4; j++)
				{
					if (sentence[i] == symbol[j])
					{
						succession++;
						consistency = true;
					}
				}
				if (consistency == false)
				{
					succession = 0;
				}
				if (maxSuccession < succession)
				{
					maxSuccession = succession;
				}
			}

			return maxSuccession;
		}

		int main() {

			string str = "This is one test string!";
			string symbols = "etis";

			int maxSuccession = 0;

			maxSuccession = succession(str, symbols, maxSuccession);

			cout << "The sentence is: " << str << endl;
			cout << "Symbols which are searched: " << symbols << endl;
			cout << "The max succession is: " << maxSuccession;

			return 0;
		}