#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Divide array into groups of 3 where max difference in each group <= k
    // Returns empty array if it's not possible to form such groups
    // Uses greedy approach: sort and group consecutive elements
    // Time complexity: O(n log n) - sorting dominates, then O(n) to process groups
    // Space complexity: O(n) for output - stores n/3 groups, each with 3 elements
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        // Sort the array to make it easier to form groups
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        
        // Process array in groups of 3
        for (int i = 0; i < nums.size(); i += 3) {
            int a = nums[i];      // First element in group
            int b = nums[i + 1];  // Second element in group
            int c = nums[i + 2];  // Third element in group
            
            // Check if the difference between max and min in this group exceeds k
            // Since array is sorted, max is c and min is a
            if (c - a > k) { 
                // If condition fails, return empty array
                return {}; 
            }
            
            // Add valid group to result
            result.push_back({a, b, c});
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 4, 8, 7, 9, 3, 5, 1};
    int k = 2;
    vector<vector<int>> result = sol.divideArray(nums, k);
    
    cout << "Result:" << endl;
    for (auto& group : result) {
        cout << "[";
        for (int i = 0; i < group.size(); i++) {
            cout << group[i];
            if (i != group.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
}

