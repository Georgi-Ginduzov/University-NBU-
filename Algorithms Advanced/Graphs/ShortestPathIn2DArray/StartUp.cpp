#include <iostream>
#include <queue>
using namespace std;

class Point {
	public:
		int row;
		int col;

		void mPoint(int m, int n) {
			row = m;
			col = n;
		}
};

class Node {
	public:
		Point point;
		int distance;

		void mNode(Point q, int distance) {
			point.row = q.row;
			point.col = q.col;

			distance = distance;
		}
};

int isValid(int nextX, int nextY, int m, int n) {
	if (nextX >= 0 && nextX<m && nextY >= 0 && nextY < n)
	{
		return 1;
	}
	return 0;
}

int shortest(int** a, int m, int n, int x1, int y1) {
	if (a[0][0] == 0)
	{
		return -1;
	}

	bool **visited = new bool*[m][n];

	memset(visited, false, sizeof((visited)));

	std::queue<Node> q;

	Point curr;
	curr.mPoint(0, 0);

	Node t;
	t.mNode(curr, 0);

	q.push(t);

	int arrX[] = { -1, 0, 1, 0 };
	int arrY[] = { 0, 1, 0, -1 };

	Point c;
	Node v;

	while (!q.empty())
	{
		v = q.front();
		c = v.point;

		if (x1 == c.row && y1 == c.col)
		{
			return v.distance;
		}

		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextX = c.row + arrX[i];
			int nextY = c.col + arrY[i];
		
			if (isValid(nextX, nextY, m, n) &&a[nextX][nextY] && !visited[nextX][nextY])
			{
				curr.mPoint(nextX, nextY);
				t.mNode(curr, (v.distance + 1));

				q.push(t);
				visited[nextX][nextY] = true;
			}
		}
		return -1;
	}

}



// __________________________ Bellman Ford algorithm __________________________

struct Edge
{
	int source, destination, weight;
};

void BellmanFord(vector<Edge>& edges, int numVertices, int source) {
	vector<int> distance(numVertices, numeric_limits<int>::max());
	distance[source] = 0;

	for (int i = 0; i < numVertices; i++)
	{
		for (auto& edge : edges)
		{
			if (distance[edge.source] != numeric_limits<int>::max() && distance[edge.source] + edge.weight < distance[edge.destination])
			{
				distance[edge.destination] = distance[edge.source] + edge.weight;
			}
		}
		
		for (auto& edge : edges)
		{
			if (distance[edge.source] != numeric_limits<int>::max() && distance[edge.source] + edge.weight < distance[edge.destination])
			{
				return;
			}
		}

		for (int i = 0; i < numVertices; i++)
		{
			std::cout << "Vertex " << i << ": " << distance[i] << std::endl;
		}
	}
}

int main() 
{
	int size;
	int wantedXCoordinates;
	int wantedYCoordinates;

	// make a 2d boolean matrix
	std::cout << "Enter the size of the matrix: ";
	std::cin >> size;
	std::cout << "Enter the desired x coordinates: ";
	std::cin >> wantedXCoordinates;
	std::cout << "Enter the desired y coordinates: ";
	std::cin >> wantedYCoordinates;
	
	bool** matrix = new bool*[size, size];
	// get input
	std::cout << "Enter the matrix elements: ";
	for (int i = 0; i < size; i++)
	{
		matrix[i] = new bool[size];

		for (int j = 0; j < size; j++)
		{
			bool input;
			std::cin >> input;

			matrix[i][j] = input;
		}
	}


	// find shortest path

	// print if there is a valid path and needed steps to reach it


	return 0;
}