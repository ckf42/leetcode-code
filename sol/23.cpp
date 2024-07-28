#include <algorithm>

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
struct Solution {
    ListNode* mergeKLists(const vector<ListNode*>& lists) {
        vector<int> h;
        ListNode *ptr;
        for (ListNode* p : lists){
            ptr = p;
            while (ptr != nullptr){
                h.push_back(ptr->val);
                ptr = ptr->next;
            }
        }
        if (h.size() == 0){
            return nullptr;
        }
        sort(h.begin(), h.end());
        ListNode *head = new ListNode(h[0]);
        ptr = head;
        for (int i = 1; i < h.size(); ++i){
            ptr->next = new ListNode(h[i]);
            ptr = ptr->next;
        }
        return head;
    }
};
