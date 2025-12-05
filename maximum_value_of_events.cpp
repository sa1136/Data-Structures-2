#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    // Memoization table: memo[i][k] = max value from event i onwards with k events remaining
    vector<vector<int>> memo;

    // Events array: each event is [startDay, endDay, value]
    vector<vector<int>> events;

    // Array of start days for binary search
    vector<int> starts;

    int n; // Total number of events

    // Dynamic programming function
    // Returns maximum value achievable from event i onwards with k_remaining events left
    // Time complexity: O(n * k * log n), Space complexity: O(n * k)
    int dp(int i, int k_remaining) {

        // Base cases:
        // 1. No more events to consider (i == n)
        // 2. No more events can be selected (k_remaining == 0)

        if(i == n || k_remaining == 0) return 0;

        // Return memoized result if already computed

        if(memo[i][k_remaining] != -1) return memo[i][k_remaining];

        // Option 1: skip this event
        // Move to next event without using any of the k_remaining events

        int ans = dp(i + 1, k_remaining);

        // Option 2: take this event
        // Find the next event that starts after current event ends
        // This ensures events don't overlap

        int next_i = upper_bound(starts.begin(), starts.end(), events[i][1]) - starts.begin();

        // Take current event's value + max value from next available event
        // Use one of the k_remaining events

        ans = max(ans, events[i][2] + dp(next_i, k_remaining - 1));

        // Memoize and return the result

        return memo[i][k_remaining] = ans;

    }

    // Find maximum value by attending at most k events
    // Events cannot overlap (next event must start after current event ends)
    int maxValue(vector<vector<int>>& _events, int k) {

        events = _events;

        n = events.size();

        // Sort events by start day
        // This allows us to use binary search to find non-overlapping events

        sort(events.begin(), events.end());

        // Extract start days for binary search
        // Used to quickly find the next event that doesn't overlap

        starts.resize(n);

        for(int i = 0; i < n; i++)

            starts[i] = events[i][0];

        // Initialize memo table with -1 (uncomputed state)

        memo.assign(n, vector<int>(k + 1, -1));

        // Start DP from event 0 with k events available

        return dp(0, k);

    }

};

