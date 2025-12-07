#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Find all unique triplets in the array that sum to zero
    // Uses two-pointer technique after sorting
    // Time complexity: O(n^2) - O(n log n) for sorting + O(n^2) for nested loops (outer loop n times, 
    //                   inner two-pointer scan O(n) each iteration)
    // Space complexity: O(1) excluding output array - only uses constant extra space for pointers
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        // Sort array to enable two-pointer technique
        sort(nums.begin(), nums.end());
        int n = nums.size();

        // Fix first element and use two pointers for remaining two
        for (int i = 0; i < n - 2; i++) {
            // Skip duplicate values for first element
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            // Early termination: if first element is positive, sum can't be zero
            if (nums[i] > 0) {
                break;
            }

            // Two pointers for remaining two elements
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    // Found a valid triplet
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicate values for left pointer
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    // Skip duplicate values for right pointer
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    left++;
                    right--;
                } else if (sum < 0) {
                    // Sum is too small, move left pointer to increase sum
                    left++;
                } else {
                    // Sum is too large, move right pointer to decrease sum
                    right--;
                }
            }
        }
        return result;
    }
};

