#include <bits/stdc++.h>

using namespace std;

class Solution {



public:

    // Store all valid palindrome partitions
    vector<vector<string>> result;

    // Current partition path being built
    vector<string> path;

    // Find all possible palindrome partitions of the string
    // Each partition is a list of palindromic substrings
    // Uses backtracking with memoization
    // Time complexity: O(2^n * n) - exponential number of partitions (2^n), each requires O(n) to check palindrome
    // Space complexity: O(n) for recursion - depth at most n, plus O(n) for path storage
    vector<vector<string>> partition(string s) {

        backtrack(0, s);

        return result;

    }

    // Backtracking on index "start"
    // Tries all possible ways to partition the remaining substring starting from 'start'
    void backtrack(int start, string &s) {

        // If we reached end, record one valid partition
        // All substrings in the path are palindromes

        if (start == s.size()) {

            result.push_back(path);

            return;

        }

        // Try every possible cut from 'start' to 'end'
        // For each position, check if substring from start to end is a palindrome

        for (int end = start; end < s.size(); end++) {

            // Check if substring s[start...end] is a palindrome

            if (isPalindrome(s, start, end)) {

                // Choose: Add this palindrome substring to the path

                path.push_back(s.substr(start, end - start + 1));

                // Explore: Recursively partition the remaining string

                backtrack(end + 1, s);

                // Undo (backtrack): Remove the last added substring to try other possibilities

                path.pop_back();

            }

        }

    }

    // Helper to check if substring s[left...right] is a palindrome
    // Uses two pointers approach
    bool isPalindrome(string &s, int left, int right) {

        while (left < right) {

            if (s[left] != s[right]) return false;

            left++;

            right--;

        }

        return true;

    }

};

