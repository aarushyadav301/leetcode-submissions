/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <stack>
#include <iostream>

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack <ListNode*> values;
        ListNode *ptr = head;
        while (ptr != nullptr) {
            values.push(ptr);
            ptr = ptr->next;
        }

        ListNode *removal;

        for (int i = 0; i < n; i++) {
            removal = values.top();
            values.pop();
        }

        // Case 1: Removing the first node
        if (values.size() == 0) {
            return (head->next);
        }

        // Case 2: Removing any other node
        ListNode *prev = values.top();
        prev->next = removal->next;
        return (head);
    }
};