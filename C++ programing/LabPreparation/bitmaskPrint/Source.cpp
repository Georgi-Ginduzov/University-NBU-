#include <iostream>
#include <cmath>

    using namespace std;

        int decimalToBinary(int* binaryNum, int decimalNum) {
            int counter = 9;
            while (decimalNum > 0)
            {
                binaryNum[counter--] = decimalNum % 2;
                decimalNum = decimalNum / 2;
            }

            return counter;
        }

        void printBitmask(char* bitmask, int* binary) {

            for (int i = 0; i <= 9; i++)
            {
                if (binary[i] == 1)
                {
                    cout << bitmask[i];
                }


            }

        }

        int main() {

            int number = 30;
            char bitmask[]{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i' };

            cout << "Number from 0 to " << pow(2, 10) << endl;
            cout << number << endl;

            int binary[10]{ 0 };
            int counter = decimalToBinary(binary, number);

            for (int i = 9; i >= 0; i--) 
            {
                cout << binary[i];
            }

            cout << endl;

            printBitmask(bitmask, binary);

            return 0;
        }
