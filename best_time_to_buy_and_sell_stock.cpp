#include <bits/stdc++.h>

using namespace std;

class Solution {



public:

    // Find the maximum profit from buying and selling a stock
    // You can only buy once and sell once
    // Buy on day i, sell on day j where j > i
    // Time complexity: O(n) - single pass through prices array, constant work per element
    // Space complexity: O(1) - only uses two variables (mini and profit) regardless of input size
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        // Track the minimum price seen so far (best day to buy)
        int mini = prices[0];

        // Track the maximum profit achievable
        int profit = 0;

        // Traverse through all prices
        for(int i = 0; i < n; i++){

            // Calculate profit if we sell on day i (buying at minimum price seen so far)
            int cost = prices[i] - mini;

            // Update maximum profit if current profit is better
            profit = max(profit, cost);

            // Update minimum price to the lowest price seen so far
            // This ensures we always buy at the best (lowest) price
            mini = min(mini, prices[i]);

        }

        return profit;

        

    }

};

