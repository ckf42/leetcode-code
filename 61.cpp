struct Solution {
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr){
            return head;
        }
        vector<ListNode*> l;
        ListNode* ptr = head;
        while (ptr != nullptr){
            l.push_back(ptr);
            ptr = ptr->next;
        }
        size_t ls = l.size();
        k %= ls;
        if (k == 0){
            return head;
        }
        l.back()->next = l.front();
        l[ls - k - 1]->next = nullptr;
        return l[ls - k];
    }
};
