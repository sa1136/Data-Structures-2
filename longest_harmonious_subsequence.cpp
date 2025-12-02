#include <bits/stdc++.h>

using namespace std;

class Solution {



public:

    // Find the length of the longest harmonious subsequence
    // A harmonious subsequence is one where the difference between 
    // the maximum and minimum element is exactly 1
    int findLHS(vector<int>& nums) {

        // Count frequency of each number in the array
        unordered_map<int,int> freq;

        for(int num:nums){

            freq[num]++;

        }

        int longest=0;

        // For each number, check if num+1 exists in the map
        // If it does, the harmonious subsequence length is freq[num] + freq[num+1]
        for(auto&p : freq){

            int num = p.first;

            // Check if the next consecutive number exists
            if( freq.count(num+1)){

                // Update longest with the sum of frequencies of num and num+1
                longest= max(longest, p.second+ freq[num+1]);

            }

        }

        return longest;

        

    }

};

