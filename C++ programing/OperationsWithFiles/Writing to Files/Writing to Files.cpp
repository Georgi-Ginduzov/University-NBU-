#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

bool readFile(std::string& fileName, std::string& text) {
    std::ifstream file(fileName);
    if (!file) {
        std::cout << "Error opening file." << std::endl;
        exit(0);
    }
    std::cout << "\nText file opened. These are its contents:\n";
    std::getline(file, text); // Read the text value from the file into the variable
    std::cout << "The text from the file is: \n" << text << std::endl;

    file.close();

    return true;
}

void symbols(std::string text) {
    std::cout << "\nThe number of symbols in the file is: " << text.size() << std::endl;
}

void writeInFile(std::string& fileName) {
    std::ofstream file;
    std::cout << "\n\nWrite what you want to add to the file:\n";
    std::string inputForTextFile;
    std::getline(std::cin, inputForTextFile);

    file.open(fileName, std::ios::app); // Open the file in append mode
    file << inputForTextFile;
    
    file.close();
}

int wordsCount(std::string text) {
    int words = 0;
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    return words;
}
int linesCount(std::string& fileName) {
    std::ifstream file;
    std::string line;
    int number_of_lines = 0;

    while (std::getline(file, line))
    {
        ++number_of_lines;
    }
    return number_of_lines;
}

int main() {
    std::string fileName = "C:/Users/User/Desktop/Sample.txt", fileText;
    std::fstream file;
    
    readFile(fileName, fileText);

    symbols(fileText);

    std::cout << "The file contains " << wordsCount(fileText) << " words.\n";
    
    std::cout << "The file contains " << linesCount(fileName) << " lines.\n";

    writeInFile(fileName);

    readFile(fileName, fileText);
    
    return 0;
}
