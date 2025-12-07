#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Convert string to integer (atoi implementation)
    // Handles leading spaces, signs, digits, and overflow cases
    // Time complexity: O(n) - single pass through string, process each character once
    // Space complexity: O(1) - only uses constant extra variables (sign, number, index)
    int myAtoi(string s) {
        int n = 1;         // sign decider 
        long long num = 0; // using long long to detect overflow of int
        int i = 0;
        int len = s.size();  // size of the string 
        
        // 1. Skip leading spaces as spaces are only allowed in beg not at in btw
        while (i < len && s[i] == ' ') {
            i++;
        }
        
        // 2. Check sign whether it is positve or negative
        if (i < len && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-')
                n = -1;
            i++;
        }
        
        // 3. Parse only digits not the char or space which come in btw if do so then break 
        while (i < len && isdigit(s[i])) {
            int val = s[i] - '0';
            num = num * 10 + val;
            
            // 4. Handle overflow — must clamp to INT_MAX/INT_MIN
            if (num * n > INT_MAX){
                return INT_MAX;
            }
            if (num * n < INT_MIN)
            {
                return INT_MIN;
            }
            i++;
        }
        
        // 5. Final result
        return (int)(num * n);
    }
};

int main() {
    Solution sol;
    
    // Test case 1: Basic conversion
    string s1 = "42";
    cout << "Input: \"" << s1 << "\"" << endl;
    cout << "Output: " << sol.myAtoi(s1) << endl;
    cout << "Expected: 42" << endl << endl;
    
    // Test case 2: With leading spaces and negative sign
    string s2 = "   -42";
    cout << "Input: \"" << s2 << "\"" << endl;
    cout << "Output: " << sol.myAtoi(s2) << endl;
    cout << "Expected: -42" << endl << endl;
    
    // Test case 3: With words after digits (should stop parsing)
    string s3 = "4193 with words";
    cout << "Input: \"" << s3 << "\"" << endl;
    cout << "Output: " << sol.myAtoi(s3) << endl;
    cout << "Expected: 4193" << endl << endl;
    
    // Test case 4: Overflow case
    string s4 = "2147483648";  // Greater than INT_MAX
    cout << "Input: \"" << s4 << "\"" << endl;
    cout << "Output: " << sol.myAtoi(s4) << endl;
    cout << "Expected: 2147483647 (INT_MAX)" << endl << endl;
    
    // Test case 5: Underflow case
    string s5 = "-2147483649";  // Less than INT_MIN
    cout << "Input: \"" << s5 << "\"" << endl;
    cout << "Output: " << sol.myAtoi(s5) << endl;
    cout << "Expected: -2147483648 (INT_MIN)" << endl;
    
    return 0;
}

