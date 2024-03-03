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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode foo(0, head);
        ListNode *p = &foo, *q = &foo;
        for (int i = 0; i <= n; ++i){
            q = q->next;
        }
        while (q != nullptr){
            p = p->next;
            q = q->next;
        }
        p->next = p->next->next;
        return foo.next;
    }
};
