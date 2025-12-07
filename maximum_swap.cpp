#include <bits/stdc++.h>

using namespace std;

class Solution {



public:

    // Find the maximum number by swapping at most one pair of digits
    // Uses greedy approach: swap the leftmost digit with the largest digit that appears later
    // Time complexity: O(n) where n is number of digits, Space complexity: O(n)
    int maximumSwap(int num) {

        

        // Convert number to string so we can easily swap digits

        string s = to_string(num);

        int n = s.size();

        // Step 1: Track the last occurrence of every digit (0–9)
        // This helps us find the rightmost position of each digit

        vector<int> last(10, -1);

        for (int i = 0; i < n; i++) {

            last[s[i] - '0'] = i;  // record the index of each digit

        }

        // Step 2: Traverse from left to right
        // Find the first position where we can improve by swapping

        for (int i = 0; i < n; i++) {

            int currentDigit = s[i] - '0';

            // Look for a larger digit from 9 → (currentDigit + 1)
            // We want the largest possible digit to swap with

            for (int d = 9; d > currentDigit; d--) {

                // If a larger digit exists later in the number

                if (last[d] > i) {

                    // Greedy swap: bring the largest possible digit forward
                    // Swap with the rightmost occurrence to maximize the result

                    swap(s[i], s[last[d]]);

                    return stoi(s);  // Only one swap allowed

                }

            }

        }

        // If no swap improves the number, return original

        return num;

    }

};

