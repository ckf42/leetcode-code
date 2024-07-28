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
    inline ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *ptr = list1, *pre, *post;
        for (int i = 1; i < a; ++i){
            ptr = ptr->next;
        }
        pre = ptr;
        for (int i = a - 2; i < b; ++i){
            ptr = ptr->next;
        }
        post = ptr;
        ptr = list2;
        while (ptr->next != nullptr){
            ptr = ptr->next;
        }
        pre->next = list2;
        ptr->next = post;
        return list1;
    }
};
