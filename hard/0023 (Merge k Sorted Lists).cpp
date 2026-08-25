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

#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return (nullptr);
        }

        map <int, int> ordering_map;
        unordered_map <int, vector<ListNode*>> valuePointers;

        
        for (int i = 0; i < lists.size(); i++) {

            if (lists.at(i) == nullptr) {
                continue;
            }

            modify_ordered_map (lists[i]->val, ordering_map, 1);
            modify_unordered (lists[i], valuePointers, 1);
        }

        ListNode *head = nullptr;
        ListNode *prev = nullptr;
        ListNode *ptr = nullptr;

        while (ordering_map.size() > 0) {
            auto first = ordering_map.begin();
            int firstVal = first->first;

            ptr = valuePointers[firstVal][valuePointers[firstVal].size() - 1];
            if (head == nullptr) {
                head = ptr;
                prev = head;
            }
            else {
                prev->next = ptr;
                prev = ptr;
            }

            modify_ordered_map(firstVal, ordering_map, 0);
            modify_unordered (ptr, valuePointers, 0);

            if (ptr->next != nullptr) {
                modify_ordered_map(ptr->next->val, ordering_map, 1);
                modify_unordered(ptr->next, valuePointers, 1);
            }
        }
        

        return (head);
    }

    void modify_ordered_map (int val, map <int, int> &arranged_int_counts, bool adding) {
        if (adding) {
            if (arranged_int_counts.count(val) == 0) {
                arranged_int_counts[val] = 0;
            }
            arranged_int_counts[val]++;
        }
        else {
            arranged_int_counts[val]--;

            if (arranged_int_counts[val] == 0) {
                arranged_int_counts.erase(val);
            }
        }
    }

    void modify_unordered (ListNode *next, unordered_map <int, vector<ListNode*>> &valuePointers, bool adding) {
        if (adding) {
            if (valuePointers.count(next->val) == 0) {
                vector <ListNode*> listing;
                listing.push_back(next);
                valuePointers[next->val] = listing;
            }
            else {
                valuePointers[next->val].push_back(next);
            }
        }
        else {
            if (valuePointers[next->val].size() == 1) {
                valuePointers.erase(next->val);
            }
            else {
                valuePointers[next->val].pop_back();
            }
        }
    }
};