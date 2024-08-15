struct Solution {
    ListNode* doubleIt(ListNode* head) {
        if (head->val >= 5){
            head = new ListNode(0, head);
        }
        head->val <<= 1;
        ListNode *prev = head, *ptr = head->next;
        while (ptr != nullptr){
            ptr->val <<= 1;
            if (ptr->val >= 10){
                ++(prev->val);
                ptr->val -= 10;
            }
            prev = ptr;
            ptr = ptr->next;
        }
        return head;
    }
};
