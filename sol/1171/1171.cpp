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

#include <unordered_map>

struct Solution {
    ListNode* removeZeroSumSublists(ListNode* head) {
        bool removed = true;
        unordered_map<int, ListNode*> d;
        while (removed){
            removed = false;
            ListNode foobar(0, head);
            d.clear();
            d.insert({0, &foobar});
            int s = 0;
            ListNode *ptr = head;
            while (ptr != nullptr){
                s += ptr->val;
                if (d.contains(s)){
                    d[s]->next = ptr->next;
                    removed = true;
                }
                d[s] = ptr;
                ptr = ptr->next;
            }
            head = foobar.next;
        }
        return head;
    }
};
