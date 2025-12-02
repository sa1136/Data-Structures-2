#include <bits/stdc++.h>

using namespace std;

class Solution {



public:

    // Find all indices i such that there exists at least one index j 
    // where nums[j] == key and |i - j| <= k
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {

        int n = nums.size();

        // Track which indices are valid (within k distance of any key element)
        vector<bool> valid(n, false);

        // Step 1: Mark valid ranges
        // For each occurrence of key, mark all indices within k distance as valid
        for (int j = 0; j < n; j++) {

            if (nums[j] == key) {

                // Calculate the range of indices within k distance from j
                int start = max(0, j - k);      // Ensure start doesn't go below 0
                int end = min(n - 1, j + k);    // Ensure end doesn't exceed array bounds

                // Mark all indices in the range [start, end] as valid
                for (int i = start; i <= end; i++) {

                    valid[i] = true;

                }

            }

        }

        // Step 2: Collect all valid indices in sorted order
        vector<int> result;

        for (int i = 0; i < n; i++) {

            if (valid[i]) {

                result.push_back(i);

            }

        }

        return result;

    }

};

