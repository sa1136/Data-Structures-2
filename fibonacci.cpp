#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Computes nth Fibonacci number iteratively using DP
    int fib(int n) {
        if (n == 0 || n == 1) {
            return n;
        }

        vector<int> f(n + 1, 0);  // DP table to store Fibonacci numbers
        f[0] = 0;
        f[1] = 1;

        for (int i = 2; i <= n; i++) {
            f[i] = f[i - 1] + f[i - 2];
        }
        return f[n];
    }
};

int main() {
    Solution sol;
    int n = 10;  // Example input
    cout << "Fibonacci(" << n << ") = " << sol.fib(n) << endl;
    return 0;
}

