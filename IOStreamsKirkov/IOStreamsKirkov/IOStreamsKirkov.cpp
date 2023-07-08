#include <iostream>
#include <fstream>

using std::cout;

int main() {

	setlocale(LC_ALL, "Bulgarian");

	std::ifstream file;

	file.open("C:/Users/User/Documents/University/OOP/test.txt");

	std::string fileData;

	file >> fileData;

	cout << fileData;


	/*for (int i = 0; i < fileData.length(); i++)
	{
		fileData[i] = (char)fileData[i] + 2;
		if ((char)fileData[i] > 26) {
		char)fileData[i] %= char)fileData[i];
		}
	}*/

	return 0;
}