#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // Check if all elements in the array have unique occurrence counts
    // Returns true if no two different values have the same frequency
    // Uses hash map to count frequencies and hash set to check for duplicates
    // Time complexity: O(n) - iterate through array once, then through frequency map once
    // Space complexity: O(n) - hash map and hash set can store up to n elements
    bool uniqueOccurrences(vector<int>& arr) {
        // Map to store frequency of each number
        unordered_map<int, int> freq;
        
        // Count the frequency of each number in the array
        for (int num : arr) {
            freq[num]++;
        }
        
        // Set to track which occurrence counts we've seen
        unordered_set<int> seen;
        
        // Check if any two numbers have the same occurrence count
        for (auto& p : freq) {
            // If we've already seen this occurrence count, frequencies are not unique
            if (seen.count(p.second)) {
                return false;
            }
            // Mark this occurrence count as seen
            seen.insert(p.second);
        }
        
        // All occurrence counts are unique
        return true;
    }
};

int main() {
    Solution sol;
    
    // Test case 1: unique occurrences
    vector<int> arr1 = {1, 2, 2, 1, 1, 3};
    cout << "Array: [1, 2, 2, 1, 1, 3]" << endl;
    cout << "Unique occurrences? " << (sol.uniqueOccurrences(arr1) ? "Yes" : "No") << endl;
    
    // Test case 2: non-unique occurrences
    vector<int> arr2 = {1, 2};
    cout << "\nArray: [1, 2]" << endl;
    cout << "Unique occurrences? " << (sol.uniqueOccurrences(arr2) ? "Yes" : "No") << endl;
    
    // Test case 3: unique occurrences
    vector<int> arr3 = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
    cout << "\nArray: [-3, 0, 1, -3, 1, 1, 1, -3, 10, 0]" << endl;
    cout << "Unique occurrences? " << (sol.uniqueOccurrences(arr3) ? "Yes" : "No") << endl;
    
    return 0;
}

