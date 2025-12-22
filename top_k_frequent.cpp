#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Find the k most frequent elements in the array
    // Uses bucket sort approach: group elements by their frequency
    // Time complexity: O(n) - iterate through array once, then through buckets once
    // Space complexity: O(n) - hash map and buckets can store up to n elements
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Map to store frequency of each number
        unordered_map<int, int> freq;
        
        // Count the frequency of each number in the array
        for (int num : nums) {
            freq[num]++;
        }
        
        // Bucket array: index represents frequency, value is list of numbers with that frequency
        // Size is nums.size() + 1 because maximum frequency can be at most nums.size()
        vector<vector<int>> buckets(nums.size() + 1);
        
        // Group numbers by their frequency into buckets
        for (auto &p : freq) {
            buckets[p.second].push_back(p.first);
        }
        
        // Collect top k frequent elements by iterating from highest frequency to lowest
        vector<int> result;
        for (int i = nums.size(); i >= 0 && result.size() < k; i--) {
            // Add all numbers in the current frequency bucket
            for (int num : buckets[i]) {
                result.push_back(num);
                // Stop if we've collected k elements
                if (result.size() == k) break;
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    int k1 = 2;
    vector<int> result1 = sol.topKFrequent(nums1, k1);
    cout << "Input: [1,1,1,2,2,3], k = 2" << endl;
    cout << "Output: [";
    for (int i = 0; i < result1.size(); i++) {
        cout << result1[i];
        if (i < result1.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    // Test case 2
    vector<int> nums2 = {1};
    int k2 = 1;
    vector<int> result2 = sol.topKFrequent(nums2, k2);
    cout << "\nInput: [1], k = 1" << endl;
    cout << "Output: [";
    for (int i = 0; i < result2.size(); i++) {
        cout << result2[i];
        if (i < result2.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    // Test case 3
    vector<int> nums3 = {4, 1, -1, 2, -1, 2, 3};
    int k3 = 2;
    vector<int> result3 = sol.topKFrequent(nums3, k3);
    cout << "\nInput: [4,1,-1,2,-1,2,3], k = 2" << endl;
    cout << "Output: [";
    for (int i = 0; i < result3.size(); i++) {
        cout << result3[i];
        if (i < result3.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    return 0;
}

