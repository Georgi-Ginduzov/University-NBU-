#include <iostream>

int matrixChainMultiplication(int matricesSizes[], const int n) {
    int j, max, q;
    int** m = new int*[n];
    int** s = new int*[n];

    for (int i = 0; i < n; i++) {
        m[i] = new int[n] {0};
        s[i] = new int[n] {0};
    }


    for (int d = 1; d < n - 1; d++)
    {
        for (int i = 1; i < n - d; i++)
        {
            j = i + d;
            max = INT_MIN;
            for (int k = i; k <= j - 1; k++)
            {
                q = m[i][k] + m[k+1][j] + matricesSizes[i-1] * matricesSizes[k] * matricesSizes[j];
                if (q > max)
                {
                    max = q;
                    s[i][j] = k;
                }
            }
            m[i][j] = max;
        }
    }

    return m[1][n-1];
}

int main() {
    int countOfMatrices;

    std::cout << "Enter number of matrices: ";
    std::cin >> countOfMatrices;

    int *matricesSizes = new int[countOfMatrices]; 
    std::cout << "Enter sizes of matrices: ";
    for (int i = 0; i <= countOfMatrices; i++)
    {
        int n;
        std::cin >> n;

        matricesSizes[i] = n;
    }

    std::cout << matrixChainMultiplication(matricesSizes, countOfMatrices);

	return 0;
}

/*
	Propose an algorithm that maximizes the number of scalar products of the matrix chain multiplication problem. Besides the implementation, prove the correctness and computational time of the algorithm.
	
*/