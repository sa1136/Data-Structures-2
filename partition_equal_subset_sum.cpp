#include <bits/stdc++.h>

using namespace std;

class Solution {



public:

    // Check if the array can be partitioned into two subsets with equal sum
    // Uses dynamic programming approach
    // dp[index][target] = true if we can achieve 'target' sum using elements from index 0 to 'index'
    // Time complexity: O(n * sum), Space complexity: O(n * sum)
    bool canPartition(vector<int>& nums) {

            int n = nums.size();

        

        // Step 1: Calculate the total sum

        int totalSum = 0;

        for (int i = 0; i < n; i++) {

            totalSum += nums[i];

        }

        // Step 2: If total sum is odd, partition is impossible
        // Because we need two equal subsets, total must be even

        if (totalSum % 2 != 0) {

            return false;

        }

        // Step 3: Determine the target sum for each subset
        // Each subset should have sum = totalSum / 2

        int targetSum = totalSum / 2;

        // Step 4: Create DP table and initialize
        // dp[i][j] = true if sum 'j' can be achieved using first 'i+1' elements

        vector<vector<bool>> dp(n, vector<bool>(targetSum + 1, false));

        // Step 5: Base case: sum 0 is always possible (by taking no elements)

        for (int i = 0; i < n; i++) {

            dp[i][0] = true;

        }

        // Step 6: Initialize first row
        // With only first element, we can only achieve sum = nums[0]

        if (nums[0] <= targetSum) {

            dp[0][nums[0]] = true;

        }

        // Step 7: Fill DP table
        // For each element, decide whether to take it or not

        for (int index = 1; index < n; index++) {

            for (int target = 1; target <= targetSum; target++) {

                // Option 1: Don't take current element
                bool notTaken = dp[index - 1][target];

                // Option 2: Take current element (if it doesn't exceed target)
                bool taken = false;

                if (nums[index] <= target) {

                    taken = dp[index - 1][target - nums[index]];

                }

                // Current state is true if either option works
                dp[index][target] = notTaken || taken;

            }

        }

        // Step 8: Return result
        // Check if we can achieve targetSum using all elements

        return dp[n - 1][targetSum];

    }

        

    

};

