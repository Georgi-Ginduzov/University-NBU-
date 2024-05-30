#include <iostream>
#include <vector>
#include "Graph.cpp"

using std::cin;
using std::cout;



int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> A(n, vector<int>(n));
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    Graph g(A);

    cout << "Original graph:\n";
    g.print("graph");

    cout << "\nSquared graph:\n";
    g.print("square graph");

    return 0;
}
