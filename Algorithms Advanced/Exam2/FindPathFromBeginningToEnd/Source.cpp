#include <iostream>
#include <vector>

void addEdge(std::vector<std::vector<int>>& adj, int u, int v) {
    adj[u][v] = 1;
}

void DFS(int v, std::vector<bool>& visited, std::vector<int>& path, std::vector<std::vector<int>>& adj) {
    visited[v] = true;
    path.push_back(v);

    if (v == adj.size() - 1) {
        for (int i = 0; i < path.size(); i++) {
            std::cout << path[i] << " ";
        }
        std::cout << std::endl;
    }
    else {
        for (int i = 0; i < adj[v].size(); ++i) {
            if (!visited[adj[v][i]]) {
                DFS(adj[v][i], visited, path, adj);
            }
        }
    }

    path.pop_back();
    visited[v] = false;
}

int main() {
    int n, m;
    std::cout << "Enter N and M: ";
    std::cin >> n >> m;

    std::vector<std::vector<int>> graph;

    int begin, end;
    std::cout << "Enter the beginning and the end: ";
    std::cin >> begin >> end;

    for (int i = 0; i < n; i++) {
        std::vector<int> temp;
        for (int j = 0; j < n; j++) {
            temp.push_back(0);
        }
        graph.push_back(temp);
    }

    std::vector<bool> visited(n, false);
    std::vector<int> path;
    DFS(0, visited, path, graph);

    return 0;
}