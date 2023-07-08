#include <iostream>
#include <string>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
    int n;
    cout << "Enter sentence's words count: \n";
    cin >> n;

    std::vector<string> sentence;

    cin >> sentence;

    string word = "brat";
    /*
    int tmp, chk = 0;
    for (int i = 0; i < sentence.length(); i++)
    {
        tmp = i;
        for (int j = 0; j < word.length(); j++)
        {
            if (sentence[i] == word[j])
                i++;
        }
        chk = i - tmp;
        if (chk == word.length())
        {
            i = tmp;
            for (int j = i; j < (sentence.length() - word.length()); j++)
                sentence[j] = sentence[j + word.length()];
            sentence.length() = sentence.length() - word.length();
            sentence[j] = '\0';
        }
    }

    cout << sentence << endl;
    */




    return 0;
}
