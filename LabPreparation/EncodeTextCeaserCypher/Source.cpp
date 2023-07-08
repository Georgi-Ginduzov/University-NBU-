#include <iostream>

	using std::cout;
	using std::cin;
	using std::endl;
	using std::string;

		string encode(string str, int move)
		{
			for (int i = 0; i < 24; i++)
			{
				int change = (char)str[i] + move;

				if (str[i] >= (char)'a' && str[i] <= (char)'z')
				{
					if (change > 122)
					{
						change -= 26;
					}
					str[i] = change;
					
				}

				if (str[i] >= (char)'A' && str[i] <= (char)'Z')
				{
					if (change > 90)
					{
						change -= 26;
					}
					str[i] = change;
				}
			}

			return str;
		}
		
		int main()
		{

			string sentence = "This is one test string!";
			int shift = 2;

			cout << sentence << endl;
			cin >> shift;

			cout << (int)'a' << " - " << (int)'z' << '\t' << (int)'A' << " - " << (int)'Z' << endl;

			sentence = encode(sentence, shift);			
			
			for (int i = 0; i < 24; i++)
			{
				cout << (int)sentence[i] << endl;
			}

			cout << sentence;

			return 0;
		}