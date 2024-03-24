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
    void reorderList(ListNode* head) {
        ListNode *tort = head, *hare = head, *left = nullptr, *right = nullptr;
        while (hare != nullptr && hare->next != nullptr){
            hare = hare->next->next;
            left = tort;
            tort = tort->next;
        }
        if (hare != nullptr){
            left = tort;
            tort = tort->next;
        }
        left->next = nullptr;
        left = nullptr;
        while (tort != nullptr){
            right = tort->next;
            tort->next = left;
            left = tort;
            tort = right;
        }
        tort = head;
        while (left != nullptr){
            right = tort->next;
            hare = left->next;
            tort->next = left;
            left->next = right;
            tort = right;
            left = hare;
        }
    }
};
