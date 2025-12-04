#include <bits/stdc++.h>

using namespace std;

class Solution {



public:

    // Find the maximum sum of a contiguous subarray (Kadane's Algorithm)
    // Uses dynamic programming approach: at each index, decide whether to
    // extend the previous subarray or start a new one
    // Time complexity: O(n), Space complexity: O(1)
    int maxSubArray(vector<int>& nums) {

        // currentSum: best sum ending at current index
        // maxSum: best sum found so far across all subarrays

        int currentSum = nums[0];  // best sum ending at current index

        int maxSum = nums[0];      // best sum found so far

        for (int i = 1; i < nums.size(); i++) {

            // At each index, we have two choices:
            // Option 1: extend the existing subarray (currentSum + nums[i])
            // Option 2: start a new subarray at nums[i]
            // Choose the option that gives maximum sum

            currentSum = max(nums[i], currentSum + nums[i]);

            // Update the global maximum sum if current sum is better

            maxSum = max(maxSum, currentSum);

        }

        return maxSum;

    }

};

