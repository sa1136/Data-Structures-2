#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Move all zeros to the end while maintaining relative order of non-zero elements
    // Uses two-pointer technique: left pointer tracks position for next non-zero element
    // Time complexity: O(n), Space complexity: O(1)
    void moveZeroes(vector<int>& nums) {
        int left = 0; // position to place next non-zero element
        
        // Traverse array with right pointer
        for (int right = 0; right < nums.size(); right++) {
            // If we find a non-zero element, swap it with left position
            if (nums[right] != 0) {
                swap(nums[left], nums[right]);
                left++; // Move left pointer forward
            }
            // If nums[right] is zero, just move right pointer forward
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 1, 0, 3, 12};
    
    cout << "Before: ";
    for (int x : nums) cout << x << " ";
    cout << endl;
    
    sol.moveZeroes(nums);
    
    cout << "After: ";
    for (int x : nums) cout << x << " ";
    cout << endl;
    // Expected output: 1 3 12 0 0
    
    return 0;
}

