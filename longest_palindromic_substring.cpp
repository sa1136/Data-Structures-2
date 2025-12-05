#include <bits/stdc++.h>

using namespace std;

class Solution {



public:

    // Find the longest palindromic substring in the given string
    // Uses dynamic programming approach
    // dp[i][j] = true if substring s[i...j] is a palindrome
    // Time complexity: O(n^2), Space complexity: O(n^2)
    string longestPalindrome(string s) {

        int n = s.size();

        if (n == 0) return "";

        // DP table: dp[i][j] indicates if substring s[i...j] is a palindrome
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int maxLen = 1;  // Length of longest palindrome found
        int start = 0;    // Starting index of longest palindrome

        // Fill the table
        // Process substrings by increasing length (bottom-up approach)

        for (int len = 1; len <= n; len++) {       // length of substring

            for (int i = 0; i <= n - len; i++) {   // start index

                int j = i + len - 1;               // end index

                // Base case 1: Single character is always a palindrome
                if (len == 1) {

                    dp[i][j] = true;

                } 
                // Base case 2: Two characters form a palindrome if they are equal
                else if (len == 2) {

                    dp[i][j] = (s[i] == s[j]);

                } 
                // General case: Substring is palindrome if:
                // 1. First and last characters match (s[i] == s[j])
                // 2. Inner substring is also a palindrome (dp[i+1][j-1])
                else {

                    dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];

                }

                // Update longest palindrome if current substring is longer
                if (dp[i][j] && len > maxLen) {

                    maxLen = len;

                    start = i;

                }

            }

        }

        // Return the longest palindromic substring
        return s.substr(start, maxLen);

    }

};

