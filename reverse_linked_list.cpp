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

    // Reverse a linked list iteratively
    // Uses three pointers: prev, curr, and nextNode
    // Time complexity: O(n), Space complexity: O(1)
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = nullptr;      // Will become the new head

        ListNode* curr = head;         // Current node we process

        while (curr != nullptr) {

            ListNode* nextNode = curr->next; // Store next node before reversing

            

            curr->next = prev; // Reverse the pointer direction

            

            prev = curr;       // Move prev forward to current position

            curr = nextNode;   // Move curr forward to next node

        }

        return prev; // New head of reversed list

    }

};

