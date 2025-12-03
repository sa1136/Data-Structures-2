#include <bits/stdc++.h>

using namespace std;

class Solution {

public:

    // DFS helper function to mark all connected land cells as visited
    // Marks the entire island by converting '1' to '0'
    void dfs(vector<vector<char>>& grid, int r, int c) {

        int rows = grid.size();

        int cols = grid[0].size();

        // Direction arrays for up, right, down, left (4-directional movement)

        vector<int> dr = {1, 0, -1, 0};

        vector<int> dc = {0, 1, 0, -1};

        // Mark the current cell as visited by converting '1' to '0'

        grid[r][c] = '0';

        // Explore all 4 directions

        for (int i = 0; i < 4; i++) {

            int nr = r + dr[i];

            int nc = c + dc[i];

            // Check boundary and if it's land (not visited yet)

            if (nr >= 0 && nc >= 0 && nr < rows && nc < cols && grid[nr][nc] == '1') {

                dfs(grid, nr, nc);

            }

        }

    }

    // Count the number of islands in the grid
    // An island is formed by connecting adjacent lands (horizontally or vertically)
    // Uses DFS to mark each island completely
    int numIslands(vector<vector<char>>& grid) {

        if (grid.empty()) return 0;

        int rows = grid.size();

        int cols = grid[0].size();

        int count = 0;

        // Traverse the entire grid

        for (int r = 0; r < rows; r++) {

            for (int c = 0; c < cols; c++) {

                // If we find a land cell, it's the start of a new island

                if (grid[r][c] == '1') {

                    count++;

                    dfs(grid, r, c);  // Mark this island completely using DFS

                }

            }

        }

        return count;

    }

};

