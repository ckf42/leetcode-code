struct Solution {
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode *ptr = head;
        int l = 0;
        while (ptr != nullptr){
            ++l;
            ptr = ptr->next;
        }
        int q = l / k, r = l % k;
        vector<ListNode *> res(k, nullptr);
        for (int i = 0; i < r; ++i){
            res[i] = head;
            ptr = head;
            head = head->next;
            for (int j = 0; j < q; ++j){
                ptr->next = head;
                ptr = head;
                head = head->next;
            }
            ptr->next = nullptr;
        }
        for (int i = r; i < k; ++i){
            if (head == nullptr){
                continue;
            }
            res[i] = head;
            ptr = head;
            head = head->next;
            for (int j = 0; j < q - 1; ++j){
                ptr->next = head;
                ptr = head;
                head = head->next;
            }
            ptr->next = nullptr;
        }
        return res;
    }
};
