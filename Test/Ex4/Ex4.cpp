#include <iostream>

    using namespace std;
    
        int main()
        {
            int chislitel, znamenatel;

            double drob = 0;

            while (true)
            {
                cout << "Chislitel -> ";
                cin >> chislitel;
                cout << "Znamenatel -> ";
                cin >> znamenatel;
                
                drob = (chislitel * 1.0) / (znamenatel * 1.0);

                cout << "Drobno chislo -> " << drob << endl << endl;

            }

            return 0;
        }
