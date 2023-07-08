#include <iostream>

    using namespace std;

        int main()
        {
            string words[10];
            
            int k = 0;

            setlocale(LC_ALL, "Bulgarian");

            string checkForComma;

            cin >> checkForComma;

            while (checkForComma != ".")
            {
                words[k++] = checkForComma;
            }

            cout << "Izrechenie -> ";

            for (int i = 0; i < k; i++)
            {
                cout << words[i] + " ";
            }
        }

