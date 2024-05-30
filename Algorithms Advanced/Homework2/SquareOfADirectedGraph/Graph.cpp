#include <iostream>
#include <vector>

using std::cout;
using std::vector;

class Graph {
private:
	vector<vector<int>> adjMatrix;
	vector<vector<int>> squareGraph;


	vector<vector<int>> squareLargeGraph() {
		int n = adjMatrix.size();
		vector<vector<int>> A2(n, vector<int>(n, 0));

		int cacheSize = 256 * 1024; // this is just example value
		int blockSize = sqrt(cacheSize / sizeof(int) / 4);

		for (int i = 0; i < n; i += blockSize) {
			for (int j = 0; j < n; j += blockSize) {
				for (int k = 0; k < n; k += blockSize) {
					for (int ii = i; ii < std::min(i + blockSize, n); ++ii) {
						for (int kk = k; kk < std::min(k + blockSize, n); ++kk) {
							if (adjMatrix[ii][kk]) {
								for (int jj = j; jj < std::min(j + blockSize, n); ++jj) {
									A2[ii][jj] |= adjMatrix[ii][kk] & adjMatrix[kk][jj];
								}
							}
						}
					}
				}
			}
		}

		return A2;
	}

	vector<vector<int>> squareSmallGraph() {
		int n = adjMatrix.size();
		vector<vector<int>> A2(n, vector<int>(n, 0));

		for (int i = 0; i < n; ++i) {
			for (int k = 0; k < n; ++k) {
				if (adjMatrix[i][k]) {
					for (int j = 0; j < n; ++j) {
						A2[i][j] |= adjMatrix[k][j];
					}
				}
			}
		}

		return A2;
	}

public:
	Graph(const vector<vector<int>>& A) : adjMatrix(A) {
		computeSquareGraph();
	}

	void computeSquareGraph() {
		if (adjMatrix.size() > 1000)
		{
			squareGraph = squareLargeGraph();
		}
		else {
			squareGraph = squareSmallGraph();
		}
	}

	void print(std::string object) const {
		const vector<vector<int>>* matrixToPrint;

		if (object == "graph") {
			matrixToPrint = &adjMatrix;
		}
		else if (object == "square graph") {
			matrixToPrint = &squareGraph;
		}
		else {
			cout << "Invalid matrix name. Please use 'graph' or 'square graph'.\n";
			return;
		}

		for (const auto& row : *matrixToPrint) {
			for (int val : row) {
				cout << val << " ";
			}
			cout << std::endl;
		}
	}
};