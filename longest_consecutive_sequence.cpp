#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    // Find the length of the longest consecutive sequence in the array
    // A consecutive sequence is a sequence of consecutive integers (e.g., 1, 2, 3, 4)
    // Uses hash set for O(1) lookup and only starts counting from sequence beginnings
    // Time complexity: O(n), Space complexity: O(n)
    int longestConsecutive(vector<int>& nums) {

        // Store numbers in a set for O(1) lookup
        // This allows us to quickly check if a number exists in the array
        unordered_set<int> numSet(nums.begin(), nums.end());

        int longestStreak = 0;

        // Iterate through each number in the set
        for (int num : numSet) {

            // Check if it's the start of a sequence
            // A number is the start if num-1 doesn't exist in the set
            // This ensures we only count each sequence once

            if (numSet.find(num - 1) == numSet.end()) {

                int currentNum = num;

                int currentStreak = 1;

                // Count consecutive numbers by incrementing and checking
                // Continue while the next number (currentNum + 1) exists in the set

                while (numSet.find(currentNum + 1) != numSet.end()) {

                    currentNum += 1;

                    currentStreak += 1;

                }

                // Update the longest streak found so far
                longestStreak = max(longestStreak, currentStreak);

            }

        }

        return longestStreak;

    }

};

