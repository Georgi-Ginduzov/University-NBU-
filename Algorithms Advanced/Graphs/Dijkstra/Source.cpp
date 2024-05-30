#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

//void dijkstra(const std::vector<std::vector<std::pair<int, int>>>& graph, int start, std::vector<int>& distances) {
//    distances.assign(graph.size(), std::numeric_limits<int>::max());
//    distances[start] = 0;
//
//    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
//    pq.push({0, start});
//
//    while (!pq.empty()) {
//        int distance = pq.top().first;
//        int vertex = pq.top().second;
//        pq.pop();
//
//        
//    }
//}

int n, m, r;

int c[100][100], U[100], p[100], d[100], G[100][100];


void dijkstra(int r) {
    int v, w, min, i, j;

    for (int i = 0; i <= n; i++)
    {
        U[i] = 0;
        p[i] = r;
        d[i] = std::numeric_limits<int>::max();
    }

    d[r] = p[r] = 0;

    for (int i = 0; i <= n; i++)
    {
        v = 0;
        min = std::numeric_limits<int>::max();

        for (int j = 1; j <= n; j++)
        {
            if (U[j] == 0 && d[j] < min)
            {
                v = j;
                min = d[j];
            }
        }
        U[v] = 1;

        for (int j = 0; j <= G[v][0]; j++)
        {
            w = G[v][j];

            if (U[w] == 0 && d[v] + c[v][w] < d[w])
            {
                d[w] = d[v] + c[v][w];
                p[w] = v;
            }
        }
    }
}

int main() {
    /*std::vector<std::vector<std::pair<int, int>>> graph = {
        {{1, 2}, {2, 3}},  
        {{2, 2}},  
        {{3, 2}},  
        {}  
    };

    std::vector<int> distances;
    dijkstra(graph, 0, distances);

    for (int i = 0; i < distances.size(); ++i) {
        std::cout << "Shortest distance from 0 to " << i << " is " << distances[i] << "\n";
    }*/

    int size;
    cout << "Enter the graph size: ";
    cin >> size;

    int** g = new int* [size];

    cout << "In the following lines enter the graph's elements:\n";
    for (int i = 0; i < size; i++)
    {
        int childrenCount;
        cout << "Enter the " << i + 1 << "th element's children count: ";
        cin >> childrenCount;

        g[i] = new int[childrenCount+1];

        cout << "Enter each child one by one";
        g[i][0] = childrenCount;
        for (int j = 0; j < childrenCount; j++)
        {
            int weight;
            cin >> weight;

            g[i][j] = weight;
        }
    }

    int u, v, w, i, j;

    cin >> n >> m >> r;

    for (int i = 1; i <= n; i++)
    {
        G[i][0] = 0;

        for (int j = 1; j <= n; j++)
        {
            c[i][j] = std::numeric_limits<int>::max();
            if (i == j)
                c[i][j] = 0;
            
        }

        for (int j = 1; j <= n; j++)
        {
            cin >> u >> v >> w;

            G[u][++G[u][0]] = v;
            G[v][++G[v][0]] = u;

            c[u][v] = c[v][u] = w;
        }
    }

    dijkstra(r);

    return 0;
}
