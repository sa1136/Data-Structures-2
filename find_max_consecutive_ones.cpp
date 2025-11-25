#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Finds the maximum number of consecutive ones in a binary array
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;     // Tracks current streak of consecutive ones
        int maxCount = 0;  // Tracks longest streak seen so far

        for (int num : nums) {
            if (num == 1) {
                count++;
                maxCount = max(maxCount, count);  // Update longest streak
            } else {
                count = 0;  // Reset current streak when a zero is encountered
            }
        }
        return maxCount;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 0, 1, 1, 1};  // Sample input
    int result = sol.findMaxConsecutiveOnes(nums);

    cout << "Output: " << result << endl;
    return 0;
}

