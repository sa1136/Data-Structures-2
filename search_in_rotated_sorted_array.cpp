#include <bits/stdc++.h>

using namespace std;

class Solution {



public:

    // Search for target in a rotated sorted array using binary search
    // The array is rotated at some pivot point, so it's not fully sorted
    // but we can still use binary search by determining which half is sorted
    // Time complexity: O(log n), Space complexity: O(1)
    int search(vector<int>& nums, int target) {

        int left = 0, right = nums.size() - 1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            // Found the target
            if (nums[mid] == target)

                return mid;

            // Check if left half is sorted
            if (nums[left] <= nums[mid]) {

                // Target is inside the left sorted part?
                // Check if target is between left boundary and mid
                if (nums[left] <= target && target < nums[mid]) {

                    // Search in the left half
                    right = mid - 1;

                } else {

                    // Target must be in the right half (which may be rotated)
                    left = mid + 1;

                }

            }

            else {

                // Right half must be sorted (since left half is not)
                // Target is inside the right sorted part?
                // Check if target is between mid and right boundary
                if (nums[mid] < target && target <= nums[right]) {

                    // Search in the right half
                    left = mid + 1;

                } else {

                    // Target must be in the left half (which may be rotated)
                    right = mid - 1;

                }

            }

        }

        // Target not found
        return -1;

    }

};

