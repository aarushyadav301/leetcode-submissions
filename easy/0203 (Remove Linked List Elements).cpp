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
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *newHead = head;
        while (newHead != nullptr) {
            if (newHead->val != val) {
                break;
            }
            newHead = newHead->next;
        }

        if (newHead == nullptr) {
            return newHead;
        }

        ListNode* left = newHead;
        ListNode* right = left->next;

        while (right != nullptr) {
            if (right->val == val) {
                if (right->next == nullptr) {
                    left->next = nullptr;
                    break;
                }
                else {
                    right = right->next;
                }
            }
            else {
                left->next = right;
                left = right;
                right = right->next;
            }
        }

        return (newHead);
    }
};