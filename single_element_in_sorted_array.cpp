#include <bits/stdc++.h>

using namespace std;

class Solution {



public:

    // Find the single element that appears only once in a sorted array
    // All other elements appear exactly twice
    // Uses binary search with a clever index manipulation
    // Time complexity: O(log n), Space complexity: O(1)
    int singleNonDuplicate(vector<int>& nums) {

        int low = 0, high = nums.size() - 1;

        // Binary search to find the single element
        // Before the single element: pairs are at (even, odd) indices
        // After the single element: pairs are at (odd, even) indices

        while (low < high) {

            int mid = low + (high - low) / 2;

            // Ensure mid is always even
            // This allows us to check pairs consistently
            // If mid is odd, move it one position left to make it even
            if (mid % 2 == 1) mid--; // make mid even

            // Check if nums[mid] and nums[mid+1] form a pair
            // If they match, the single element is to the right
            // If they don't match, the single element is to the left (or at mid)

            if (nums[mid] == nums[mid + 1]) {

                // Pair found, single element is to the right
                // Skip both elements of the pair
                low = mid + 2;

            } else {

                // Pair not found, single element is to the left or at mid
                // Search in the left half (including mid)
                high = mid;

            }

        }

        // When low == high, we've found the single element
        return nums[low];

    }

};

