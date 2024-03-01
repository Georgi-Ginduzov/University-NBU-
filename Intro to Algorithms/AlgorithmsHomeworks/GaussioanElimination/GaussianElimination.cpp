#include <iostream>

int main() {
	const int size = 3;	
	double matrix[size][size] = { {2, 0, 0}, 
								{1, -3, 7}, 
								{8, 4, 5} };

	for (int i = 0; i < size; ++i) {
		double diagonalElement = matrix[i][i];
		for (int j = i; j < size; j++) {
			matrix[i][j] /= diagonalElement;
		}

		for (int j = i + 1; j < size; j++) {
			double factor = matrix[j][i];
			for (int k = i; k < size; k++) {
				matrix[j][k] -= factor * matrix[i][k];
			}
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}