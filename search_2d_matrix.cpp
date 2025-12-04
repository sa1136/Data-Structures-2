#include <bits/stdc++.h>

using namespace std;

class Solution {



public:

    // Search for target in a 2D matrix
    // Matrix is sorted row-wise and each row is sorted in ascending order
    // Treats the 2D matrix as a 1D sorted array for binary search
    // Time complexity: O(log(m*n)), Space complexity: O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();        // number of rows

        int n = matrix[0].size();     // number of columns

        int left = 0;

        int right = m * n - 1;        // treat matrix as a 1D sorted array
        // Total elements = m * n, so last index is m*n - 1

        // Standard binary search on the flattened matrix

        while (left <= right) {

            int mid = left + (right - left) / 2;

            // Convert mid index into row & column in the 2D matrix
            // Formula: row = index / n, col = index % n

            int row = mid / n;        // integer division gives row

            int col = mid % n;        // modulo gives column

            int value = matrix[row][col];

            // Check if we found the target

            if (value == target) {

                return true;

            }

            // If target is larger, discard the left half
            // Search in the right half

            else if (value < target) {

                left = mid + 1;

            }

            // If target is smaller, discard the right half
            // Search in the left half

            else {

                right = mid - 1;

            }

        }

        // Target not found after searching entire matrix

        return false;

    }

};

