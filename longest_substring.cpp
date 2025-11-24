#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Function to find the length of the longest substring without repeating characters
    int lengthOfLongestSubstring(string s) {
        // Store last seen index of each ASCII character (256 possible ASCII characters)
        vector<int> lastIndex(256, -1);
        
        int left = 0;      // Left pointer of the sliding window
        int maxLen = 0;    // Maximum length found so far
        
        // Iterate through the string with right pointer
        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            
            // If character is already in the current window, move left pointer
            // to the position right after the last occurrence of this character
            if (lastIndex[c] >= left) {
                left = lastIndex[c] + 1;
            }
            
            // Update last seen index of current character
            lastIndex[c] = right;
            
            // Update maximum length if current window is longer
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};

int main() {
    Solution sol;
    string s = "abcabcbb";
    cout << sol.lengthOfLongestSubstring(s); // Output: 3
    return 0;
}

