#include <iostream>

std::string reverseSentence(std::string sentence) {
	
	std::string reversed;

	for (int i = 0; i < sentence.length(); i++)
	{
		std::cout << "for ";
		std::string word;
		if (sentence[i] == ' ')
		{
			
			for (int j = 0; j < i; j++)
			{
				sentence[j] = word[j];
			}
			std::reverse(word.begin() + 0, word.end() + i);
			reversed = word + " ";
		}
	}
	return reversed;
}

int main() {
	int size;
	std::cin >> size;

	char* randomSymbols = new char[size];
	std::cin >> randomSymbols;

	for (int i = 0; i < size; i++)
	{
		std::cout << randomSymbols[i];
	}

	std::string consonants = "aeiou";
	int countConsonants = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < consonants.length(); j++)
		{
			if (randomSymbols[i] == consonants[j])
			{
				countConsonants++;
			}
		}

	}

	char* randomArrayConsonants = new char[countConsonants];
	int k = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < consonants.length(); j++)
		{
			if (randomSymbols[i] == consonants[j])
			{
				randomArrayConsonants[k++] = randomSymbols[i];
			}
		}
	}

	std::cout << "\nThe array with only consonants from the input is: \n";
	for (int i = 0; i < countConsonants; i++)
	{
		std::cout << randomArrayConsonants[i] << " ";
	}

	std::string inputSentence;
	std::cout << "\nEnter sentence to be reversed: \n";
	std::cin >> inputSentence;
	std::string reversedSentence = reverseSentence(inputSentence);
	std::cout << reversedSentence;
}