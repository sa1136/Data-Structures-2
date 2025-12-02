#include <bits/stdc++.h>

using namespace std;

class Solution {



public:

    // Find the maximum difference between nums[j] and nums[i] where j > i and nums[j] > nums[i]
    // Returns -1 if no such pair exists
    int maximumDifference(vector<int>& nums) {

        // We use the "running minimum" or "single-pass greedy" technique.

        // Idea:

        //   - Track the minimum value seen so far (left side).

        //   - For each element nums[j], compute nums[j] - minSoFar.

        //   - Keep the maximum difference.

        //   - If no positive difference exists, return -1.

        int minVal = nums[0];   // smallest value seen so far on the left

        int maxDiff = -1;       // default: no valid difference found yet

        for (int j = 1; j < nums.size(); j++) {

            // If current number is greater than minVal, 

            // we can form a valid difference.

            if (nums[j] > minVal) {

                maxDiff = max(maxDiff, nums[j] - minVal);

            }

            // Update the minimum value seen so far

            // (so future j's can subtract from it)

            minVal = min(minVal, nums[j]);

        }

        return maxDiff;

    }

};

