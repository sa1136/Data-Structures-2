#include <bits/stdc++.h>

using namespace std;

class Solution {



public:

    // Calculate how much rainwater can be trapped between bars
    // Uses two-pointer approach with dynamic max tracking
    // Water trapped at position i = min(leftMax, rightMax) - height[i]
    // Time complexity: O(n) - single pass through array, each bar processed once
    // Space complexity: O(1) - only uses constant extra variables (left, right, leftMax, rightMax, water)
    int trap(vector<int>& height) {

        int l = 0;                      // Left pointer

        int r = height.size() - 1;      // Right pointer

        int leftMax = 0;                // Highest bar seen so far from the left

        int rightMax = 0;               // Highest bar seen so far from the right

        int water = 0;                  // Total trapped water

        // Move inward from both ends
        // Process the side with smaller height first (it determines the trapping limit)

        while (l < r) {

            // The side with the smaller height decides the trapping limit
            // We can safely calculate water on the smaller side because we know
            // there's a taller bar on the other side

            if (height[l] < height[r]) {

                // If the current bar is taller than or equal to leftMax,
                // update leftMax (no water can be trapped here)
                // This bar becomes the new boundary

                if (height[l] >= leftMax)

                    leftMax = height[l];

                else

                    // Otherwise, water can be trapped
                    // The water level is determined by leftMax (the highest bar to the left)
                    // (difference between leftMax and current height)

                    water += leftMax - height[l];

                l++; // Move left pointer inward

            } 

            else {

                // Process right side (similar logic)
                // If the current bar is taller than or equal to rightMax,
                // update rightMax (no water trapped)
                // This bar becomes the new boundary

                if (height[r] >= rightMax)

                    rightMax = height[r];

                else

                    // Otherwise, trap water on this side
                    // The water level is determined by rightMax (the highest bar to the right)

                    water += rightMax - height[r];

                r--; // Move right pointer inward

            }

        }

        return water; // Return total trapped water

    }

};

