#include <iostream>
#include <vector>

#define INF INT_MAX
#define MAX 10000

using namespace std;

void floydWarshal(vector<vector<int>> adjMatrix) {
	const int n = adjMatrix.size();

	if (n == 0)
	{
		return;
	}

	vector<vector<int>> cost;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cost[i][j] = adjMatrix[i][j];
		}
	}

	// Find negative cycles
	for (int k = 0; k < n; k++)
	{
		for (int v = 0; v < n; v++)
		{
			for (int u = 0; u < n; u++)
			{
				if (cost[v][k] != INF && cost[k][u] != INF 
					&& cost[v][k] + cost[k][u] < cost[v][u])
				{
					cost[v][u] = cost[v][k] + cost[k][u];
				}
			}

			if (cost[v][v] < 0)
			{
				cout << "Negative weight cycle found!";
				return;
			}
		}
	}

}

int G[MAX][MAX], N;
int P[MAX][MAX];

void floyd() {
	int i, j, k;

	for (k = 1; k <= N; k++)
	{
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{
				if (G[i][k] + G[k][j] < G[i][j])
				{
					G[i][j] = G[i][k] + G[k][j];
					P[i][j] = k;
				}
			}
		}
	}
}



int main() {
	// Get data
	vector<vector<int>> adjMatrix = 
	{ 
		{0, INF, -2, INF}, 
		{4, 0, -3, INF}, 
		{INF, INF, 0, 2},
		{INF, -1, INF, 0}
	};

	floydWarshal(adjMatrix);
}