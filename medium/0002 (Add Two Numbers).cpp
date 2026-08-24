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

using namespace std;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2) {
            ListNode *head;
            (!l1) ? head = l2 : head = l1;
            return (head);
        }

        int curSum = l1->val + l2->val;
        int carry = 1;
        (curSum >= 10) ? curSum -= 10 : carry--;
        ListNode *head = new ListNode(curSum);
        ListNode *prev = head;
        ListNode *ptr = head;
        l1 = l1->next;
        l2 = l2->next;

        while (l1 && l2) {
            curSum = l1->val + l2->val + carry;
            carry = 1;
            (curSum >= 10) ? curSum -= 10 : carry--;
            ptr = new ListNode(curSum);
            prev->next = ptr;
            prev = ptr;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 || l2) {
            (l1) ? curSum = l1->val + carry : curSum = l2->val + carry;
            carry = 1;
            (curSum >= 10) ? curSum -= 10 : carry--;
            ptr = new ListNode(curSum);
            prev->next = ptr;
            prev = ptr;
            (l1) ? l1 = l1->next : l2 = l2->next;
        }

        (carry > 0) ? ptr->next = new ListNode(carry) : ptr->next = nullptr;
        return (head);
    }
};