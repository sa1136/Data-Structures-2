#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Function to count the number of trapezoids that can be formed from given points
    // A trapezoid is formed by selecting 4 points where two pairs share the same y-coordinate
    // Uses combinatorics: count pairs of points with same y-coordinate, then count ways to select 2 pairs
    static int countTrapezoids(vector<vector<int>>& points) {
        const long long mod = 1e9 + 7;
        const int n = points.size();
        
        // Extract y-coordinates from points
        int* y = (int*)alloca(n * sizeof(int));
        int i = 0;
        for (auto& p : points) {
            y[i++] = p[1];
        }
        
        // Sort y-coordinates to group same y-values together
        sort(y, y + n);
        
        long long sum = 0;  // Sum of all C(f,2) values
        long long c2 = 0;    // Sum of squares of C(f,2) values
        long long c = 0;     // Current C(f,2) value
        int f = 1;           // Frequency of current y-coordinate
        int prev = y[0];      // Previous y-coordinate value
        
        // Count frequency of each y-coordinate and calculate combinations
        for (int i = 1; i < n; i++) {
            if (prev == y[i]) {
                // Same y-coordinate, increment frequency
                f++;
            } else {
                // Different y-coordinate, process previous group
                // C(f,2) = f*(f-1)/2 (number of ways to choose 2 points from f points)
                c = f * (f - 1LL) / 2LL;
                sum += c;
                c2 += c * c;
                f = 1;
                prev = y[i];
            }
        }
        
        // Process the last group
        c = f * (f - 1LL) / 2LL;
        sum += c;
        c2 += c * c;
        
        // Formula: (sum^2 - c2) / 2
        // This counts ways to select 2 pairs of points with same y-coordinate
        // while avoiding double counting (dividing by 2)
        return (sum * sum - c2) / 2 % mod;
    }
};

int main() {
    // Test case: points with various y-coordinates
    vector<vector<int>> points = {
        {1, 2}, {2, 2}, {3, 2},  // 3 points with y=2
        {4, 3}, {5, 3},           // 2 points with y=3
        {6, 4}, {7, 4}, {8, 4}, {9, 4}  // 4 points with y=4
    };
    
    int result = Solution::countTrapezoids(points);
    cout << "Number of trapezoids: " << result << endl;
    // Explanation:
    // Points with y=2: C(3,2) = 3 pairs
    // Points with y=3: C(2,2) = 1 pair
    // Points with y=4: C(4,2) = 6 pairs
    // Total pairs: sum = 3 + 1 + 6 = 10
    // Ways to select 2 pairs: (10^2 - (3^2 + 1^2 + 6^2)) / 2 = (100 - 46) / 2 = 27
    
    return 0;
}

