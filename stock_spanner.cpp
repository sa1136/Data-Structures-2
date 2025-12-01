#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class StockSpanner {
public:
    // Stack to store pairs of {price, span}
    // span represents consecutive days (including current day) where price <= current price
    stack<pair<int, int>> st;
    
    StockSpanner() {
        // Constructor - initialize empty stack
    }
    
    // Function to calculate span for the current price
    // Returns the number of consecutive days (including today) where price <= today's price
    int next(int price) {
        int span = 1;  // Start with span of 1 (current day)
        
        // Pop all prices that are smaller or equal to current price
        // and accumulate their spans since they contribute to current span
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;  // Add the span of popped price
            st.pop();
        }
        
        // Push current price with its accumulated span
        st.push({price, span});
        
        return span;
    }
};

int main() {
    StockSpanner* obj = new StockSpanner();
    
    // Test case: prices in sequence
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    
    cout << "Stock Spanner Test:" << endl;
    cout << "Price\tSpan" << endl;
    cout << "-----\t----" << endl;
    
    for (int price : prices) {
        int span = obj->next(price);
        cout << price << "\t" << span << endl;
    }
    
    // Expected output:
    // 100 -> 1 (only itself)
    // 80  -> 1 (only itself, 100 > 80)
    // 60  -> 1 (only itself, 80 > 60)
    // 70  -> 2 (60 and 70, 80 > 70)
    // 60  -> 1 (only itself, 70 > 60)
    // 75  -> 4 (60, 70, 60, 75, 80 > 75)
    // 85  -> 6 (60, 70, 60, 75, 80, 85, 100 > 85)
    
    delete obj;
    return 0;
}

