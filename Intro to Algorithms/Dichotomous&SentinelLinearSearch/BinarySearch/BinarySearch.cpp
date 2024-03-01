#include <iostream>

using std::cout;

int main() {
    setlocale(LC_ALL, "Bulgarian");
    
    char symbols[]{ 'â', 'ã', 'ä', 'ç', 'è', 'í', 'î', 'ó', '0', '1', '4', '7', '8', 'f'}; 
    char searchThis[]{ 'î', 'ú', 'þ', 'ÿ', '7', '8', '9' };
    int searchSize = 7;
    int beginning = 0, end = 12;
    int middle;

    for (int i = 0; i < searchSize; i++) {
        char target = searchThis[i];
        beginning = 0;
        end = 12;

        while (beginning <= end) {
            middle = (beginning + end) / 2;

            cout << symbols[middle] << " ti " << target << " li si\n";
            if (symbols[middle] == target) {
                cout << "Target " << target << " found at index " << middle << "\n\n";
                break;
            }
            else if (symbols[middle] < target) {
                beginning = middle + 1;
            }
            else {
                end = middle - 1;
            }
        }

        if (beginning > end) {
            cout << "Target " << target << " not found in the array\n\n";
        }
    }

    return 0;
}
