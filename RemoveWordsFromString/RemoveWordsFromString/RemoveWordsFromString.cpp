#include <iostream>
#include <string>
#include <regex>

int main() {

	setlocale(LC_ALL, "Bulgarian");

	std::string sentence = "Ќ€какво изречение с на на на, което е сложно на на на";
	/*
	int naPos = 0;
	std::regex wordRegex("\b на \b");
	
	std::string newSentence = std::regex_replace(sentence, wordRegex, "");

	std::cout << newSentence << "\n" << sentence;
	*/
	char
	int i = 0;
	while (i < sentence.size())
	{
		if (sentence[i] == 'н' && sentence[i + 1] == 'а')
		{

		}
		i++;
	}

	return 0;
}