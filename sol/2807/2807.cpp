struct Solution {
    inline static int gcd(int x, int y) {
        while (y != 0){
            x %= y;
            swap(x, y);
        }
        return x;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *prev = head, *ptr = head->next;
        while (ptr != nullptr){
            prev->next = new ListNode(this->gcd(prev->val, ptr->val), ptr);
            prev = ptr;
            ptr = ptr->next;
        }
        return head;
    }
};
