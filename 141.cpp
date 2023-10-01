struct Solution {
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr){
            return false;
        }
        ListNode *tort = head, *rabb = head->next;
        while (true){
            if (tort == rabb){
                return true;
            }
            if (rabb->next == nullptr){
                return false;
            }
            rabb = rabb->next;
            if (rabb->next == nullptr){
                return false;
            }
            rabb = rabb->next;
            tort = tort->next;
        }
    }
};
