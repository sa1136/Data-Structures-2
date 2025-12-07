#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
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
    // Perform level-order traversal (BFS) of a binary tree
    // Returns a 2D vector where each inner vector represents a level of the tree
    // Uses queue to process nodes level by level
    // Time complexity: O(n) - each node is visited exactly once
    // Space complexity: O(n) for queue and output - queue can hold at most all leaf nodes (n/2 in worst case),
    //                   output stores all n nodes organized by level
    vector<vector<int>> levelOrder(TreeNode* root) {
        // Create a 2D vector to store levels
        vector<vector<int>> ans; 
        if (root == nullptr) {
            // If the tree is empty, return an empty vector
            return ans; 
        }
        
        // Create a queue to store nodes for level-order traversal
        queue<TreeNode*> q; 
        // Push the root node to the queue
        q.push(root); 
        
        while (!q.empty()) {
            // Get the size of the current level
            int size = q.size(); 
            // Create a vector to store nodes at the current level
            vector<int> level; 
            
            for (int i = 0; i < size; i++) {
                // Get the front node in the queue
                TreeNode* node = q.front(); 
                // Remove the front node from the queue
                q.pop(); 
                // Store the node value in the current level vector
                level.push_back(node->val); 
                
                // Enqueue the child nodes if they exist
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            // Store the current level in the answer vector
            ans.push_back(level); 
        }
        // Return the level-order traversal of the tree
        return ans; 
    }
};

int main() {
    Solution sol;
    
    // Create a sample binary tree: [3,9,20,null,null,15,7]
    //       3
    //      / \
    //     9  20
    //       /  \
    //      15   7
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    vector<vector<int>> result = sol.levelOrder(root);
    
    cout << "Level Order Traversal:" << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << "Level " << i << ": ";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    // Expected output:
    // Level 0: 3
    // Level 1: 9 20
    // Level 2: 15 7
    
    return 0;
}

