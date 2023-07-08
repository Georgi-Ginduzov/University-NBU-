#include <iostream>
#include <cmath>

    using namespace std;

        int newSet(int* set1, int size, int* set2, int* set3) {
            for (int i = 0; i < size; i++) {
                set3[i] = abs(set1[i] - set2[i]);
            }

            return *set3;
        }

        bool repeatCheck(int* set, bool repeat, int i) {
            repeat = false;
            for (i; i < 10; i++)
            {
                for (int j = i + 1; j < 10; j++)
                {
                    if (set[i] == set[j])
                    {
                        repeat = true;
                        return repeat;
                    }
                    if (j == 9 && repeat == false)
                    {
                        return repeat;
                    }
                    
                }
            }
            return repeat;
        }

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
            int set1[10] = { 6, 11, 8, 2, 5, 0, 0, 0, 0, 0 };
            int set2[10] = { 5, 2, 3, 8, 1, 6 ,4, 12, 9, 10 };
            int size = 10;
            int set3[10];
            int k = 0;
               
            bool isRepeated = false;

            newSet(set1, size, set2, set3);

            cout << "Set3: [";
            for (int i = 0; i < size; i++) {


                isRepeated = repeatCheck(set3, isRepeated, k++);

                if (isRepeated == false){
                
                    cout << set3[i] << ", ";

                }
            }
            cout << "]" << endl << endl << endl;

            // Ex2

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
