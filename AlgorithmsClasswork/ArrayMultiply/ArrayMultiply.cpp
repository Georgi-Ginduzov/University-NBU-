#include <iostream>

int main() {
    const int rowsA = 3, colsA = 4, rowsB = 4, colsB = 2;
    int A[rowsA][colsA] = { {4, 8, 9, 4}, {3, 7, 1, 7}, {6, 4, 0, 2} };
    int B[rowsB][colsB] = { {3, 3}, {8, 4}, {9, 1}, {4, 7} };
    int C[rowsA][colsB] = { 0 };

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    for (int i = colsB - 1; i >= 0; --i) {
        for (int j = rowsA - 1; j >= 0; --j) {
            std::cout << C[j][i] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
