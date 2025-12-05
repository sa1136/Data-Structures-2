#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {

public:

    // Perform vertical order traversal of a binary tree
    // Nodes in the same column should be grouped together
    // Within the same column and row, nodes should be sorted by value
    // Uses DFS to collect nodes by column, then sorts by row and value

    // DFS helper function to traverse the tree and collect nodes by column
    // row: current depth/level in the tree
    // col: current column (left decreases, right increases)
    // colMap: maps column number to list of (row, value) pairs
    void dfs(TreeNode* node, int row, int col, map<int, vector<pair<int,int>>>& colMap) {

        if (!node) return;

        // Store this node's value with its row and column information
        colMap[col].push_back({row, node->val});

        // Traverse left child: move down (row+1) and left (col-1)
        dfs(node->left, row+1, col-1, colMap);

        // Traverse right child: move down (row+1) and right (col+1)
        dfs(node->right, row+1, col+1, colMap);

    }

    // Main function to perform vertical order traversal
    // Returns a 2D vector where each inner vector contains nodes in one column
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        // Map to store nodes grouped by column
        // Key: column number, Value: list of (row, value) pairs
        map<int, vector<pair<int,int>>> colMap; // column -> (row, val) pairs

        // Start DFS from root at row 0, column 0
        dfs(root, 0, 0, colMap);

        vector<vector<int>> res;

        // Process each column in order (map is sorted by key)
        for(auto &[col, nodes] : colMap) {

            // Sort nodes in the same column by row first, then by value
            // This ensures proper ordering: top to bottom, left to right
            sort(nodes.begin(), nodes.end()); // sort by row, then val

            // Extract values from the sorted pairs
            vector<int> colVals;

            for(auto &[row, val] : nodes) colVals.push_back(val);

            // Add this column's values to the result
            res.push_back(colVals);

        }

        return res;

    }

};

