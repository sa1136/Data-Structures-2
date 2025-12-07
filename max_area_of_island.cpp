#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // DFS to compute the area of one island
    // Marks all connected land cells and counts them
    // Time complexity: O(m*n) for each island, Space complexity: O(m*n) for visited array
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int row, int col, int& area) {
        int m = grid.size(), n = grid[0].size();
        // Direction arrays: Up, Right, Down, Left
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        // Mark current cell visited
        vis[row][col] = 1;
        area++;  // Count this cell in area

        // Explore all 4 neighbors
        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            // Check bounds + unvisited + land cell
            if (nrow >= 0 && nrow < m &&
                ncol >= 0 && ncol < n &&
                vis[nrow][ncol] == 0 &&
                grid[nrow][ncol] == 1) {
                dfs(grid, vis, nrow, ncol, area);  // Recur for neighbor
            }
        }
    }

    // Find the maximum area of an island in the grid
    // Uses DFS to explore each island and track maximum area
    // Time complexity: O(m*n), Space complexity: O(m*n) for visited array
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // Visited array to track which cells we explored
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int maxArea = 0;

        // Traverse entire grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Start DFS only if it's unvisited land
                if (vis[i][j] == 0 && grid[i][j] == 1) {
                    int area = 0;  // Reset area for this island
                    // Compute area of the island using DFS
                    dfs(grid, vis, i, j, area);
                    // Update maximum area found
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};

