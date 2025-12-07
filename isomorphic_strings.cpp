#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Check if two strings are isomorphic
    // Two strings are isomorphic if characters in s can be replaced to get t
    // and vice versa, with no two characters mapping to the same character
    // Uses bidirectional mapping to ensure consistency
    // Time complexity: O(n) - single pass through both strings, hash map operations are O(1)
    // Space complexity: O(1) - hash maps store at most 256 character mappings (ASCII charset size)
    bool isIsomorphic(string s, string t) {
        // Strings must have same length to be isomorphic
        if(s.length() != t.length()) return false;
        
        // Two maps to ensure bidirectional mapping is consistent
        unordered_map<char, char> mapST;  // map s -> t
        unordered_map<char, char> mapTS;  // map t -> s
        
        for(int i = 0; i < s.length(); i++) {
            char c1 = s[i];
            char c2 = t[i];
            
            // If mapping from s to t exists, it must match c2
            if(mapST.count(c1)) {
                if(mapST[c1] != c2) return false;
            } else {
                mapST[c1] = c2;
            }
            
            // If mapping from t to s exists, it must match c1
            if(mapTS.count(c2)) {
                if(mapTS[c2] != c1) return false;
            } else {
                mapTS[c2] = c1;
            }
        }
        
        return true;
    }
};

int main() {
    Solution sol;
    
    // Test case 1: isomorphic strings
    string s1 = "egg";
    string t1 = "add";
    cout << "Is \"" << s1 << "\" and \"" << t1 << "\" isomorphic? " 
         << (sol.isIsomorphic(s1, t1) ? "Yes" : "No") << endl;
    
    // Test case 2: non-isomorphic strings
    string s2 = "foo";
    string t2 = "bar";
    cout << "Is \"" << s2 << "\" and \"" << t2 << "\" isomorphic? " 
         << (sol.isIsomorphic(s2, t2) ? "Yes" : "No") << endl;
    
    return 0;
}

