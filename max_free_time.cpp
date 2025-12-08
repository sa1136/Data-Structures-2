#include <bits/stdc++.h>

using namespace std;

class Solution {



public:

    // Find the maximum free time by potentially removing and relocating one meeting
    // If a meeting can be moved to fit in an existing gap, we can merge adjacent gaps
    // Returns the maximum continuous free time achievable
    // 
    // Algorithm:
    // 1. Compute gaps between meetings (including boundaries)
    // 2. Precompute largest gap to the right of each meeting
    // 3. For each meeting, check if removing it (and relocating) creates larger free time
    //
    // Time complexity: O(n) - single pass to compute gaps (O(n)), 
    //                   single pass to compute largestRight (O(n)),
    //                   single pass to process meetings (O(n))
    //                   Note: Assumes meetings are already sorted by start time
    //                   If unsorted, add O(n log n) for sorting first
    // Space complexity: O(n) - gaps array of size n+1, largestRight array of size n+1
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {

        int n = startTime.size();

        // Base case: No meetings means entire eventTime is free
        if (n == 0) return eventTime;

        // Step 1: Compute all gaps between meetings, including start and end boundaries
        // A gap is the free time between consecutive meetings or at boundaries
        // gaps[0] = free time before first meeting (from time 0 to first meeting start)
        // gaps[i] = free time between meeting i-1 and meeting i (from endTime[i-1] to startTime[i])
        // gaps[n] = free time after last meeting (from last meeting end to eventTime)

        vector<int> gaps(n + 1, 0);

        // Gap before first meeting
        gaps[0] = startTime[0];

        // Gaps between consecutive meetings
        for (int i = 1; i < n; ++i)
            gaps[i] = startTime[i] - endTime[i - 1];

        // Gap after last meeting
        gaps[n] = eventTime - endTime[n - 1];

        // Step 2: Precompute the largest gap to the right of each meeting
        // This helps us quickly check if a meeting can fit in a right gap
        // largestRight[i] = maximum gap among gaps[i+1 .. n]
        // We compute this from right to left to efficiently track the maximum

        vector<int> largestRight(n + 1, 0);

        for (int i = n - 1; i >= 0; --i)
            largestRight[i] = max(largestRight[i + 1], gaps[i + 1]);

        // Step 3: Iterate through each meeting and consider removing it
        // For each meeting, check if removing it creates a larger free time block
        int maxFree = 0;       // Stores the maximum free time achievable
        int largestLeft = 0;   // Maximum gap to the left of current meeting

        for (int i = 1; i <= n; ++i) {

            // Duration of the current meeting (meeting at index i-1)
            int duration = endTime[i - 1] - startTime[i - 1];

            // Check if the meeting can fit into some existing gap on left or right
            // If it can fit, we can relocate it and merge adjacent gaps
            // This allows us to combine: gap before + meeting duration + gap after

            bool canFitLeft = largestLeft >= duration;   // Can fit in a left gap?
            bool canFitRight = largestRight[i] >= duration;  // Can fit in a right gap?

            // If it can fit somewhere else, compute merged free interval
            // merged = gap before + gap after + duration of removed meeting
            // This represents the free time if we remove the meeting and relocate it

            if (canFitLeft || canFitRight) {
                int merged = gaps[i - 1] + gaps[i] + duration;
                maxFree = max(maxFree, merged);
            }

            // Even if meeting cannot be relocated, the free time between gaps[i-1] and gaps[i] may be maximum
            // This handles the case where we don't remove any meeting
            // Just consider the sum of two adjacent gaps

            maxFree = max(maxFree, gaps[i - 1] + gaps[i]);

            // Update largestLeft to include current gap for future iterations
            // This tracks the maximum gap we've seen so far on the left
            // Used to check if future meetings can fit in left gaps

            largestLeft = max(largestLeft, gaps[i - 1]);

        }

        return maxFree;

    }

};

