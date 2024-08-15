struct Solution {
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr){
            return nullptr;
        }
        ListNode *tort = head, *rabb = head->next;
        while (true){
            if (tort == rabb){
                break;
            }
            if (rabb->next == nullptr){
                return nullptr;
            }
            rabb = rabb->next;
            if (rabb->next == nullptr){
                return nullptr;
            }
            rabb = rabb->next;
            tort = tort->next;
        }
        tort = head;
        rabb = rabb->next;
        while (tort != rabb){
            tort = tort->next;
            rabb = rabb->next;
        }
        return tort;
    }
};
