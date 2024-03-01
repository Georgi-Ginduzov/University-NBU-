#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

    using namespace std;

    int main()
    {
        

        int N;

        cin >> N;

        setlocale(LC_ALL, "Bulgarian");
        srand(time(NULL));
        
        int* sides = new int[N];
        
        for (int i = 0; i < N; i++)
        {
            sides[i] = rand() % 2;
        }

        for (int i = 0; i < N; i++)
        {
            bool isTura = true;

            if (sides[i] == 0)
            {
                isTura = false;
            }

            if (isTura == true)
            {
                cout << i + 1 << ". “ура\t";
            }
            else
            {
                cout << i + 1 << ". ≈зи\t";
            }
        }

    }
