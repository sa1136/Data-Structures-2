#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Generate all possible subsets of an array (power set)
    // Uses iterative approach: start with empty subset and build up
    // Time complexity: O(n * 2^n), Space complexity: O(n * 2^n) for output
    vector<vector<int>> subsets(vector<int>& nums) {
        // Initialize result with empty subset
        vector<vector<int>> result = {{}};
        
        // For each number in the input array
        for (int num : nums) {
            // Store current size of result (before adding new subsets)
            int n = result.size();
            
            // For each existing subset, create a new subset by adding current number
            for (int i = 0; i < n; i++) {
                // Copy existing subset
                vector<int> subset = result[i];
                // Add current number to create a new subset
                subset.push_back(num);
                // Add the new subset to result
                result.push_back(subset);
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = sol.subsets(nums);
    
    // Print all subsets
    cout << "Subsets:" << endl;
    for (auto &subset : res) {
        cout << "[";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i != subset.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }
    return 0;
}

