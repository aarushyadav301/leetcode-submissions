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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = nullptr;
        ListNode *cur = nullptr;

        while (list1 != nullptr || list2 != nullptr) {
            if (list1 == nullptr) {
                if (head == nullptr) {
                    head = list2;
                    cur = head;
                    list2 = list2 -> next;
                    continue;
                }

                cur -> next = list2;
                cur = list2;
                list2 = list2 -> next;
                continue;
            }
            if (list2 == nullptr) {
                if (head == nullptr) {
                    head = list1;
                    cur = head;
                    list1 = list1 -> next;
                    continue;
                }

                cur -> next = list1;
                cur = list1;
                list1 = list1 -> next;
                continue;
            }

            if (list1->val < list2->val) {
                if (head == nullptr) {
                    head = list1;
                    cur = head;
                    list1 = list1->next;
                    continue;
                }

                cur -> next = list1;
                cur = list1;
                list1 = list1 -> next;
            }
            else {
                if (head == nullptr) {
                    head = list2;
                    cur = head;
                    list2 = list2 -> next;
                    continue;
                }

                cur -> next = list2;
                cur = list2;
                list2 = list2 -> next;
            }
        }

        return (head);
    }
};