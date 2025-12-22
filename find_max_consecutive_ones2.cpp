#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Find the maximum number of consecutive ones with at most one zero allowed
    // Uses sliding window technique to maintain a window with at most one zero
    // Time complexity: O(n) - each element is visited at most twice (once by right pointer, once by left)
    // Space complexity: O(1) - only uses a few variables regardless of input size
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0;           // Left pointer of the sliding window
        int zeroCount = 0;      // Count of zeros in the current window
        int maxLen = 0;         // Maximum length of consecutive ones found so far

        // Expand the window by moving the right pointer
        for (int right = 0; right < nums.size(); right++) {
            // If we encounter a zero, increment the zero count
            if (nums[right] == 0) {
                zeroCount++;
            }

            // Shrink the window from the left if we have more than one zero
            // This ensures we always have at most one zero in our window
            while (zeroCount > 1) {
                // If the left element is a zero, decrement zero count when we remove it
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;  // Move left pointer to shrink the window
            }

            // Update the maximum length found so far
            // right - left + 1 gives the current window size
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 0, 1, 1, 0, 1, 1, 1};  // Sample input
    int result = sol.findMaxConsecutiveOnes(nums);

    cout << "Output: " << result << endl;
    return 0;
}

