struct Solution {
    ListNode* mergeNodes(ListNode* head) {
        ListNode foo(0, head);
        ListNode *s = &foo, *ptr = head;
        int accum = 0;
        while (ptr != nullptr){
            if (ptr->val != 0){
                accum += ptr->val;
            } else {
                ptr->val = accum;
                accum = 0;
                s->next = ptr;
                s = ptr;
            }
            ptr = ptr->next;
        }
        return foo.next->next;
    }
};
