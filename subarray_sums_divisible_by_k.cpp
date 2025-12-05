#include <bits/stdc++.h>

using namespace std;

class Solution {



public:

    // Count the number of subarrays whose sum is divisible by k
    // Uses prefix sum and modulo arithmetic
    // Key insight: If two prefix sums have the same remainder mod k,
    // then the subarray between them is divisible by k
    // Time complexity: O(n), Space complexity: O(k)
    int subarraysDivByK(vector<int>& nums, int k) {

        // Map to count occurrences of each remainder
        // remainder -> count of prefix sums with that remainder
        unordered_map<int,int> count;

        // Initialize with remainder 0 (empty prefix sum)
        // This handles subarrays starting from index 0
        count[0] = 1;

        int prefixSum = 0;  // Running prefix sum
        int result = 0;      // Total count of divisible subarrays

        for(int num : nums) {

            // Update prefix sum
            prefixSum += num;

            // Calculate remainder, handling negative numbers
            // ((prefixSum % k) + k) % k ensures remainder is always in range [0, k-1]
            // This is needed because in C++, negative numbers can give negative modulo
            int remainder = ((prefixSum % k) + k) % k; // handle negative numbers

            // If we've seen this remainder before, all subarrays between
            // those positions and current position are divisible by k
            // Add the count of previous occurrences to result
            result += count[remainder];

            // Increment count for this remainder
            count[remainder]++;

        }

        return result;

    }

};

