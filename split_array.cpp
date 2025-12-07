#include <bits/stdc++.h>

using namespace std;

class Solution {



public:

    // Check how many subarrays are needed if max allowed sum is 'mid'
    // Uses greedy approach: add elements until sum exceeds mid, then start new subarray
    // Time complexity: O(n) - single pass through array, constant work per element
    // Space complexity: O(1) - only uses constant extra variables (currSum, count)
    int countSubarrays(vector<int>& nums, long long mid) {

        long long currSum = 0;

        int count = 1; // at least one subarray

        

        for (int num : nums) {

            if (currSum + num > mid) {  

                // start a new subarray

                count++;

                currSum = num;

            } else {

                currSum += num;

            }

        }

        return count;

    }

    // Find the minimum possible largest sum when splitting array into k subarrays
    // Uses binary search on answer: search for minimum max sum
    // Time complexity: O(n * log(sum)) - binary search over sum range (log(sum) iterations), 
    //                   each iteration calls countSubarrays which is O(n)
    // Space complexity: O(1) - only uses constant extra variables for binary search
    int splitArray(vector<int>& nums, int k) {

        long long left = *max_element(nums.begin(), nums.end());

        long long right = accumulate(nums.begin(), nums.end(), 0LL);

        while (left < right) {

            long long mid = left + (right - left) / 2;

            // How many subarrays needed if max allowed sum = mid

            int subarrays = countSubarrays(nums, mid);

            if (subarrays > k) {

                // Too many splits → mid is too small

                left = mid + 1;

            } else {

                // mid is valid, try reducing

                right = mid;

            }

        }

        return left; // or right, both meet at answer

    }

};

