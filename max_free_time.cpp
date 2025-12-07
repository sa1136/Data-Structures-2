#include <bits/stdc++.h>

using namespace std;

class Solution {



public:

    // Find the maximum free time by potentially removing and relocating one meeting
    // If a meeting can be moved to fit in an existing gap, we can merge adjacent gaps
    // Returns the maximum continuous free time achievable
    // Time complexity: O(n log n) - O(n log n) to sort meetings, O(n) to compute gaps and process
    // Space complexity: O(n) - arrays to store gaps and largestRight, each of size n
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {

        int n = startTime.size();

        if (n == 0) return eventTime; // No meetings → full eventTime is free

        // Step 1: Compute all gaps between meetings, including start and end boundaries
        // A gap is the free time between consecutive meetings or at boundaries

        // gaps[0] = free time before first meeting

        // gaps[i] = free time between meeting i-1 and meeting i

        // gaps[n] = free time after last meeting

        vector<int> gaps(n + 1, 0);

        gaps[0] = startTime[0];

        for (int i = 1; i < n; ++i)

            gaps[i] = startTime[i] - endTime[i - 1];

        gaps[n] = eventTime - endTime[n - 1];

        // Step 2: Precompute the largest gap to the right of each meeting
        // This helps us quickly check if a meeting can fit in a right gap
        // largestRight[i] = maximum gap among gaps[i+1 .. n]

        vector<int> largestRight(n + 1, 0);

        for (int i = n - 1; i >= 0; --i)

            largestRight[i] = max(largestRight[i + 1], gaps[i + 1]);

        int maxFree = 0;       // Stores the maximum free time achievable

        int largestLeft = 0;   // Maximum gap to the left of current meeting

        // Step 3: Iterate through each meeting and consider removing it
        // For each meeting, check if removing it creates a larger free time block

        for (int i = 1; i <= n; ++i) {

            // Duration of the current meeting (meeting i-1)

            int duration = endTime[i - 1] - startTime[i - 1];

            // Check if the meeting can fit into some existing gap on left or right
            // If it can fit, we can relocate it and merge adjacent gaps

            bool canFitLeft = largestLeft >= duration;

            bool canFitRight = largestRight[i] >= duration;

            // If it can fit somewhere else, compute merged free interval
            // merged = gap before + gap after + duration of removed meeting
            // This represents the free time if we remove the meeting

            if (canFitLeft || canFitRight) {

                int merged = gaps[i - 1] + gaps[i] + duration;

                maxFree = max(maxFree, merged);

            }

            // Even if meeting cannot be relocated, the free time between gaps[i-1] and gaps[i] may be maximum
            // This handles the case where we don't remove any meeting

            maxFree = max(maxFree, gaps[i - 1] + gaps[i]);

            // Update largestLeft to include current gap for future iterations
            // This tracks the maximum gap we've seen so far on the left

            largestLeft = max(largestLeft, gaps[i - 1]);

        }

        return maxFree;

    }

};

