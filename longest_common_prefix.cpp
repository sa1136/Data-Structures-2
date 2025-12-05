#include <bits/stdc++.h>

using namespace std;

class Solution {



public:

    // Find the longest common prefix string amongst an array of strings
    // Uses a horizontal scanning approach
    // Start with the first string as prefix and shrink it by comparing with other strings
    // Time complexity: O(S) where S is the sum of all characters, Space complexity: O(1)
    string longestCommonPrefix(vector<string>& strs) {

    if (strs.empty()) return "";

    // Assume first string is the common prefix
    // We'll shrink it by comparing with other strings

    string prefix = strs[0]; // assume first string is the prefix

    // compare with every other string

    for (int i = 1; i < strs.size(); i++) {

        // shrink prefix until it matches the start of strs[i]
        // find() returns 0 if prefix is found at the beginning of the string
        // If not found at position 0, remove the last character and try again

        while (strs[i].find(prefix) != 0) {

            prefix = prefix.substr(0, prefix.size() - 1);

            // If prefix becomes empty, no common prefix exists

            if (prefix.empty()) return "";

        }

    }

    return prefix;

}

};

