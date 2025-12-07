#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Decode a string with pattern k[encoded_string]
    // Example: "3[a]2[bc]" decodes to "aaabcbc"
    // Uses two stacks to handle nested brackets
    // Time complexity: O(n * k) where n is string length and k is max repeat count, Space complexity: O(n)
    string decodeString(string s) {
        stack<int> numStack;      // Stack to store numbers (repeat counts)
        stack<string> strStack;    // Stack to store strings (previous strings)
        string currStr = "";       // Current string being built
        int currNum = 0;           // Current number being parsed
        
        for (char c : s) {
            if (isdigit(c)) {
                // Build multi-digit numbers
                currNum = currNum * 10 + (c - '0');
            } 
            else if (c == '[') {
                // Push current number and string to stacks
                // Reset for new nested level
                numStack.push(currNum);
                strStack.push(currStr);
                currNum = 0;
                currStr = "";
            } 
            else if (c == ']') {
                // Pop from stacks and repeat current string
                int repeatCount = numStack.top(); numStack.pop();
                string prevStr = strStack.top(); strStack.pop();
                
                // Repeat current string 'repeatCount' times
                string repeated = "";
                for (int i = 0; i < repeatCount; i++)
                    repeated += currStr;
                
                // Combine previous string with repeated string
                currStr = prevStr + repeated;
            } 
            else {
                // Regular character, append to current string
                currStr += c;
            }
        }
        
        return currStr;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    string s1 = "3[a]2[bc]";
    cout << "Input: " << s1 << endl;
    cout << "Output: " << sol.decodeString(s1) << endl;
    cout << "Expected: aaabcbc" << endl << endl;
    
    // Test case 2
    string s2 = "2[abc]3[cd]ef";
    cout << "Input: " << s2 << endl;
    cout << "Output: " << sol.decodeString(s2) << endl;
    cout << "Expected: abcabccdcdcdef" << endl << endl;
    
    // Test case 3: nested brackets
    string s3 = "3[a2[c]]";
    cout << "Input: " << s3 << endl;
    cout << "Output: " << sol.decodeString(s3) << endl;
    cout << "Expected: accaccacc" << endl;
    
    return 0;
}

