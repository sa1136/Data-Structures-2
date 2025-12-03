#include <bits/stdc++.h>

using namespace std;

class Solution {



public:

    // Compute the nth Fibonacci number using dynamic programming
    // F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2) for n > 1
    // Time complexity: O(n), Space complexity: O(n)
    int fib(int n) {

        // Create array to store Fibonacci numbers up to n
        int f[n+1];

        // Base cases: F(0) = 0, F(1) = 1
        if (n == 1 || n == 0) return n;

        // Initialize base values
        f[0] = 0;

        f[1] = 1; 

        // Fill the DP array from bottom up
        // Each Fibonacci number is the sum of the two previous ones
        for (int i=2; i<=n; i++) {

            f[i] = f[i-1] + f[i-2];

        }

        return f[n];

    }

};
