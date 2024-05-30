#include <iostream>
#include <algorithm>
#include <vector>

void addEdge(std::vector<std::vector<std::pair<int, int>>>& adj, int u, int v, int wt) {
	adj[u].push_back(std::make_pair(v, wt));
	adj[v].push_back(std::make_pair(u, wt));
}

int find(std::vector<int>& parent, int i) {
	if (parent[i] == -1)
		return i;
	return find(parent, parent[i]);
}

void union1(std::vector<int>& parent, int x, int y) {
	int xset = find(parent, x);
	int yset = find(parent, y);
	parent[xset] = yset;
}

int kruskalMST(std::vector<std::vector<std::pair<int, int>>>& adj) {
	int minCost = 0;
	std::vector<int> parent(adj.size(), -1);

	for (int i = 0; i < adj.size(); i++) {
		for (auto& edge : adj[i]) {
			int u = i;
			int v = edge.first;
			int w = edge.second;

			int x = find(parent, u);
			int y = find(parent, v);

			if (x != y) {
				minCost += w;
				union1(parent, x, y);
			}
		}
	}

	return minCost;
}

int main() {
	int n, m;
	std::cout << "Enter N and M: ";
	std::cin >> n;
	std::cin >> m;
	int sum = 0;
	
	std::cout << "Enter the edges and their weights: \n";

	std::vector<std::vector<std::pair<int, int>>> graph;
	
	for (int i = 0; i < m; i++) {
		int u, v, wt;
		std::cin >> u;
		std::cin >> v;
		std::cin >> wt;

		addEdge(graph, u, v, wt);
		sum += wt;
	}

	for (int i = 0; i < n; i++) {
		std::sort(graph[i].begin(), graph[i].end());
	}

	int minCost = kruskalMST(graph);
	std::cout << "Minimum cost of the spanning tree: " << minCost << std::endl;

	
	return 0;
}



