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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        vector<int> vals;
        while (cur != nullptr) {
            vals.push_back(cur->val);
            cur = cur->next;
        }

        cur = head;

        for (int i = 0; i < vals.size(); i += k) {
            if (i + k - 1 >= vals.size()) {
                break;
            }

            for (int j = i + k - 1; j >= i; j--) {
                cur->val = vals[j];
                cur = cur->next;
            }
        }

        return (head);
    }
};