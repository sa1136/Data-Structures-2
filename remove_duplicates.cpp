#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Remove duplicates from sorted array in-place and return new length
    // Uses two-pointer technique: slow pointer tracks unique elements
    // Time complexity: O(n), Space complexity: O(1)
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int i = 0;  // Slow pointer that tracks the position of last unique element
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];  // Place next unique value after the last unique
            }
        }
        return i + 1;  // Length is last unique index + 1
    }
};

int main() {
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    Solution s;
    int k = s.removeDuplicates(nums);

    cout << "k = " << k << endl;
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}

