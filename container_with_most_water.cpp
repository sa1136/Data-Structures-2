#include <bits/stdc++.h>

using namespace std;

class Solution {



public:

    // Find the maximum area of water that can be contained between two lines
    // Uses two-pointer approach: start from both ends and move inward
    // Area = width * min(height[left], height[right])
    // Time complexity: O(n), Space complexity: O(1)
    int maxArea(vector<int>& height) {

        int left = 0;                  // start pointer (leftmost line)

        int right = height.size() - 1; // end pointer (rightmost line)

        int max_area = 0;

        // Use two pointers to find the maximum area
        // Move the pointer with smaller height inward (greedy approach)

        while (left < right) {

            // Calculate current area
            // Width is the distance between the two lines
            // Height is limited by the shorter of the two lines

            int width = right - left;

            int curr_height = min(height[left], height[right]);

            int area = width * curr_height;

            // Update max_area if current area is bigger

            max_area = max(max_area, area);

            // Move the pointer with smaller height
            // This is optimal because:
            // - Moving the taller pointer can only decrease width
            // - Moving the shorter pointer might find a taller line
            // - The area is limited by the shorter line anyway

            if (height[left] < height[right]) {

                left++;

            } else {

                right--;

            }

        }

        return max_area;

    }

};

