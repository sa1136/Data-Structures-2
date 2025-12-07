#include <bits/stdc++.h>

using namespace std;

class Solution {



public:

    // Find the minimum radius of heaters needed to warm all houses
    // Each house must be within the radius of at least one heater
    // Returns the minimum radius such that all houses can be warmed
    // Uses binary search to find nearest heater for each house
    // Time complexity: O(n log n + m log n) where n=heaters, m=houses, Space complexity: O(1)
    int findRadius(vector<int>& houses, vector<int>& heaters) {

        // Step 1: Sort both arrays to enable binary search
        // This allows us to efficiently find the nearest heater for each house

        sort(houses.begin(), houses.end());

        sort(heaters.begin(), heaters.end());

        int radius = 0;

        // Step 2: For each house, find the nearest heater
        // The required radius must cover the farthest house from any heater

        for (int house : houses) {

            // lower_bound gives the first heater position >= house
            // This finds the heater on the right side (or at the same position)

            auto it = lower_bound(heaters.begin(), heaters.end(), house);

            int rightDist = INT_MAX;  // distance to heater on the right

            int leftDist = INT_MAX;   // distance to heater on the left

            // If a right heater exists (heater at or after the house position)

            if (it != heaters.end()) {

                rightDist = abs(*it - house);

            }

            // If a left heater exists (heater before the house position)

            if (it != heaters.begin()) {

                it--;

                leftDist = abs(*it - house);

            }

            // Minimum distance to nearest heater (either left or right)

            int nearest = min(leftDist, rightDist);

            // Update the required radius to cover the farthest house
            // The radius must be at least as large as the distance to the farthest house

            radius = max(radius, nearest);

        }

        return radius;

    }

};

