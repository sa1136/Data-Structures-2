#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Find the next greater element for each element in nums1
    // The next greater element is found in nums2
    // Uses monotonic stack to efficiently find next greater elements
    // Time complexity: O(n + m) where n=len(nums1), m=len(nums2), Space complexity: O(m)
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Map to store next greater element for each number in nums2
        unordered_map<int, int> nextGreater;
        // Stack to maintain elements in decreasing order
        stack<int> st;
        
        // Process nums2 to fill the next greater map
        // For each number, pop all smaller numbers from stack and set their next greater
        for (int num : nums2) {
            // While stack is not empty and top element is smaller than current number
            while (!st.empty() && st.top() < num) {
                // Current number is the next greater element for the top of stack
                nextGreater[st.top()] = num;
                st.pop();
            }
            // Push current number to stack
            st.push(num);
        }
        
        // Remaining items in stack have no next greater element
        while (!st.empty()) {
            nextGreater[st.top()] = -1;
            st.pop();
        }
        
        // Build answer for nums1 using the map
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(nextGreater[num]);
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    
    vector<int> result = sol.nextGreaterElement(nums1, nums2);
    
    cout << "Input nums1: ";
    for (int x : nums1) cout << x << " ";
    cout << endl;
    
    cout << "Input nums2: ";
    for (int x : nums2) cout << x << " ";
    cout << endl;
    
    cout << "Output: ";
    for (int x : result) cout << x << " ";
    cout << endl;
    // Expected: -1 3 -1
    // Explanation: 
    // - For 4 in nums1, there is no next greater in nums2, so -1
    // - For 1 in nums1, next greater is 3 in nums2
    // - For 2 in nums1, there is no next greater in nums2, so -1
    
    return 0;
}

