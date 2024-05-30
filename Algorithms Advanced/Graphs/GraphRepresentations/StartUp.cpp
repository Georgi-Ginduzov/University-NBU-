#include <iostream>
#include <vector>

// Add an edge in an adjacency list
void addEdgeInAdjacencyList(std::vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Add an edge in an adjacency matrix
void addEdgeInAdjacencyMatrix(std::vector<std::vector<int>>& adj, int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}


// Print the adjacency list representation of a graph
void printAdjacencyListGraph(std::vector<int> adj[], int V) {
    for (int v = 0; v < V; ++v) {
        std::cout << "\n Adjacency list of vertex " << v << "\n head ";
        for (auto x : adj[v])
            std::cout << "-> " << x;
        std::cout << std::endl;
    }
}

// Print the adjacency matrix representation of a graph
void printAdjacencyMatrixGraph(const std::vector<std::vector<int>>& adj) {
    for (const auto& row : adj) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << "\n";
    }
}


int main() {

    const int V = 5;
    std::vector<int> adj[V];  // Create a vector of size V to represent adjacency list

    // Adding edges
    addEdgeInAdjacencyList(adj, 0, 1);
    addEdgeInAdjacencyList(adj, 0, 4);
    addEdgeInAdjacencyList(adj, 1, 2);
    addEdgeInAdjacencyList(adj, 1, 3);
    addEdgeInAdjacencyList(adj, 1, 4);
    addEdgeInAdjacencyList(adj, 2, 3);
    addEdgeInAdjacencyList(adj, 3, 4);

    printAdjacencyListGraph(adj, V);

    return 0;
    


}