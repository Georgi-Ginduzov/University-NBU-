#include <iostream>
#include <string>
#include <regex>

int main() {

	setlocale(LC_ALL, "Bulgarian");

	std::string sentence = "������� ��������� � �� �� ��, ����� � ������ �� �� ��";
	/*
	int naPos = 0;
	std::regex wordRegex("\b �� \b");
	
	std::string newSentence = std::regex_replace(sentence, wordRegex, "");

	std::cout << newSentence << "\n" << sentence;
	*/
	char
	int i = 0;
	while (i < sentence.size())
	{
		if (sentence[i] == '�' && sentence[i + 1] == '�')
		{

		}
		i++;
	}

	return 0;
}