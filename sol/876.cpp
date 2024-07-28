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
    inline ListNode* middleNode(ListNode* head) {
        ListNode *tort = head, *hare = head;
        while (hare != nullptr && hare->next != nullptr){
            tort = tort->next;
            hare = hare->next->next;
        }
        return tort;
    }
};
