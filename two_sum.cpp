#include <bits/stdc++.h>

using namespace std;

class Solution {



public:

    // Find two numbers in the array that add up to target
    // Returns the indices of the two numbers
    // Uses hash map for O(1) lookup to achieve O(n) time complexity
    // Time complexity: O(n) - single pass through array, hash map lookup/insert is O(1) average case
    // Space complexity: O(n) - hash map stores at most n elements (one per array element)
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();

        // Hash map to store number -> index mapping
        // As we iterate, we check if the complement (target - current) exists
        unordered_map<int, int> mpp;

        for (int i = 0; i < n; i++) {

            int num = nums[i];

            // Calculate the number needed to reach target
            // If moreNeeded exists in the map, we found our pair

            int moreNeeded = target - num;

            // Check if the complement exists in the map
            // If found, return the indices of both numbers

            if (mpp.find(moreNeeded) != mpp.end()) {

                return {mpp[moreNeeded], i};

            }

            // Store current number and its index in the map
            // This allows future numbers to check if they can pair with this number

            mpp[num] = i;

        }

        // If no pair found, return {-1, -1}
        // (Note: problem guarantees a solution exists, so this may not be reached)

        return { -1, -1};

        }

};

