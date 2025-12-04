#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:

    // Flatten a multilevel doubly linked list
    // When a node has a child, the child list should be inserted between the node and its next
    // Uses DFS approach to recursively flatten child lists
    // Returns the head of the flattened list

    // DFS helper: flattens from 'node', returns the tail of the flattened segment
    // This allows us to connect the flattened child list to the rest of the list
    Node* dfs(Node* node) {

        Node* curr = node;

        Node* last = node;  // Track the last visited node in this segment

        while (curr != nullptr) {

            Node* nextNode = curr->next;  // Save next pointer before modifying

            // CASE 1: Current node has a child: flatten the child list
            // We need to insert the child list between curr and nextNode

            if (curr->child != nullptr) {

                // Flatten the child list → childTail is the tail of child list
                // This recursively processes all nested child lists

                Node* childTail = dfs(curr->child);

                // Insert child list after current node
                // Connect curr -> child (head of child list)

                curr->next = curr->child;

                curr->child->prev = curr;

                curr->child = nullptr;   // Clear child pointer (no longer needed)

                // Connect tail of child list to the originally saved nextNode
                // This ensures the flattened child list is properly inserted

                if (nextNode != nullptr) {

                    childTail->next = nextNode;

                    nextNode->prev = childTail;

                }

                last = childTail;  // Update last pointer to the tail of child list

            } else {

                // No child → normal traversal, just move forward
                // Update last to current node

                last = curr;

            }

            curr = nextNode;  // Move forward to next node

        }

        return last;  // Return tail of this flattened segment

    }

    Node* flatten(Node* head) {

        if (head == nullptr) return head;

        // Start DFS from head to flatten the entire list
        dfs(head);

        return head;

    }

};

