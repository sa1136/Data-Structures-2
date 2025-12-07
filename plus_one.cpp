#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Add one to a number represented as an array of digits
    // Handles carry propagation from least significant to most significant digit
    // Time complexity: O(n), Space complexity: O(1) excluding output array
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Traverse from right to left (least significant to most significant digit)
        for (int i = n - 1; i >= 0; i--) {
            // If current digit is less than 9, just increment and return
            if (digits[i] < 9) {
                digits[i]++; 
                return digits;
            }
            // If digit is 9, set it to 0 and continue (carry over)
            digits[i] = 0;  // carry
        }
        
        // If all digits were 9, we need to add a new digit at the beginning
        // Example: [9, 9, 9] becomes [1, 0, 0, 0]
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    vector<int> digits = {9, 9, 9};
    Solution s;
    vector<int> result = s.plusOne(digits);
    cout << "Result: ";
    for (int x : result) cout << x << " ";
    cout << endl;
    return 0;
}

