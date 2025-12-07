#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Find the next lexicographically greater permutation
    // Modifies the array in-place to the next permutation
    // Algorithm: 1) Find pivot 2) Find successor 3) Swap 4) Reverse suffix
    // Time complexity: O(n), Space complexity: O(1)
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        
        // Step 1: Find pivot - the first element from right that is smaller than its next
        // This is the point where we can make a larger permutation
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        
        if (i >= 0) {
            // Step 2: Find successor - the smallest element in suffix that is greater than pivot
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            
            // Step 3: Swap pivot and successor
            swap(nums[i], nums[j]);
        }
        
        // Step 4: Reverse the suffix to get the smallest possible permutation
        // This ensures we get the next lexicographically greater permutation
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {1, 2, 3};
    cout << "Before: ";
    for (int x : nums1) cout << x << " ";
    cout << endl;
    sol.nextPermutation(nums1);
    cout << "After: ";
    for (int x : nums1) cout << x << " ";
    cout << endl; // Expected: 1 3 2
    cout << endl;
    
    // Test case 2
    vector<int> nums2 = {3, 2, 1};
    cout << "Before: ";
    for (int x : nums2) cout << x << " ";
    cout << endl;
    sol.nextPermutation(nums2);
    cout << "After: ";
    for (int x : nums2) cout << x << " ";
    cout << endl; // Expected: 1 2 3 (wraps around to first permutation)
    cout << endl;
    
    // Test case 3
    vector<int> nums3 = {1, 1, 5};
    cout << "Before: ";
    for (int x : nums3) cout << x << " ";
    cout << endl;
    sol.nextPermutation(nums3);
    cout << "After: ";
    for (int x : nums3) cout << x << " ";
    cout << endl; // Expected: 1 5 1
    
    return 0;
}

