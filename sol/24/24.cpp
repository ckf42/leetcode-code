struct Solution {
    inline ListNode* swapPairs(ListNode* head) {
        ListNode foo(0, head);
        ListNode *p0 = &foo, *p1, *p2, *p3;
        while (p0->next != nullptr){
            p1 = p0->next;
            if (p1->next == nullptr){
                break;
            }
            p2 = p1->next;
            p3 = p2->next;
            p0->next = p2;
            p2->next = p1;
            p1->next = p3;
            p0 = p1;
        }
        return foo.next;
    }
};
