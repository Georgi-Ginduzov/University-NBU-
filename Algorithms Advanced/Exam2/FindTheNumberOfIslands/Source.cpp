#include <iostream>
#include <vector>

int findTheNumberOfIslands(std::vector<std::vector<int>>& grid) {
	int count = 0;

	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			if (grid[i][j] == 1) {
				count++;
				grid[i][j] = 0;
				std::vector<std::pair<int, int>> stack;
				stack.push_back(std::make_pair(i, j));
				while (!stack.empty()) {
					std::pair<int, int> p = stack.back();
					stack.pop_back();
					int x = p.first;
					int y = p.second;
					if (x - 1 >= 0 && grid[x - 1][y] == 1) {
						stack.push_back(std::make_pair(x - 1, y));
						grid[x - 1][y] = 0;
					}
					if (x + 1 < grid.size() && grid[x + 1][y] == 1) {
						stack.push_back(std::make_pair(x + 1, y));
						grid[x + 1][y] = 0;
					}
					if (y - 1 >= 0 && grid[x][y - 1] == 1) {
						stack.push_back(std::make_pair(x, y - 1));
						grid[x][y - 1] = 0;
					}
					if (y + 1 < grid[i].size() && grid[x][y + 1] == 1) {
						stack.push_back(std::make_pair(x, y + 1));
						grid[x][y + 1] = 0;
					}
				}
			}
		}
	}
	return count;
}

int main() {
	int size;
	std::cout << "Enter the size of the grid: ";
	std::cin >> size;

	std::vector<std::vector<int>> grid;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int n;
			std::cin >> n;

			grid[i].push_back(n);
		}
	}

	std::cout << findTheNumberOfIslands(grid) << std::endl;

	return 0;
}
