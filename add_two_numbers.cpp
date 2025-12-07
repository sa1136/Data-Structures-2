#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    // Add two numbers represented as reversed linked lists
    // Returns the head of a new linked list representing the sum
    // Processes digits from least significant to most significant with carry handling
    // Time complexity: O(max(m, n)) where m, n are lengths of lists, Space complexity: O(max(m, n))
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();  // Dummy node to simplify result building
        ListNode* res = dummy;             // Pointer used to return the actual head
        int total = 0, carry = 0;          // total = digit sum, carry = carry-over

        // Continue while there are digits to process or carry remains
        while (l1 || l2 || carry) {
            total = carry;

            if (l1) {
                total += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                total += l2->val;
                l2 = l2->next;
            }

            int num = total % 10;   // Current digit
            carry = total / 10;     // Carry for next iteration

            dummy->next = new ListNode(num);
            dummy = dummy->next;
        }

        ListNode* result = res->next;
        delete res;  // Free dummy node
        return result;
    }
};

// Helper function to create a linked list from vector
ListNode* buildList(const vector<int>& vals) {
    ListNode* dummy = new ListNode();
    ListNode* current = dummy;
    for (int val : vals) {
        current->next = new ListNode(val);
        current = current->next;
    }
    ListNode* head = dummy->next;
    delete dummy;
    return head;
}

// Helper to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) {
            cout << " -> ";
        }
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Each list represents a number in reverse order (e.g., 342 = 2->4->3)
    vector<int> vals1 = {2, 4, 3};  // Represents 342
    vector<int> vals2 = {5, 6, 4};  // Represents 465

    ListNode* l1 = buildList(vals1);
    ListNode* l2 = buildList(vals2);

    ListNode* sum = sol.addTwoNumbers(l1, l2);  // Expected result represents 807 (7->0->8)

    cout << "List 1: ";
    printList(l1);
    cout << "List 2: ";
    printList(l2);
    cout << "Sum:    ";
    printList(sum);

    return 0;
}

