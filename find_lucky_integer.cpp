#include <bits/stdc++.h>

using namespace std;

class Solution {



public:

    // Find the largest lucky number in the array
    // A lucky number is a number that appears in the array exactly as many times as its value
    // Example: If 3 appears 3 times, it's a lucky number
    int findLucky(vector<int>& arr) {

        // Map to store frequency of each number
        unordered_map<int, int> freq;

        

        // Count frequencies of each number in the array
        for (int num : arr) {

            freq[num]++;

        }

        

        int ans = -1;

        

        // Check for lucky numbers
        // A number is lucky if its frequency equals its value
        for (auto &p : freq) {

            int num = p.first;

            int count = p.second;

            // If frequency equals the number itself, it's a lucky number
            if (num == count) {

                // Keep track of the largest lucky number found
                ans = max(ans, num);

            }

        }

        

        // Return the largest lucky number, or -1 if no lucky number exists
        return ans;

    }

};

