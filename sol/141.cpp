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
// half of Brent algorithm
// struct Solution {
//     bool hasCycle(ListNode *head) {
//         if (head == nullptr || head->next == nullptr){
//             return false;
//         }
//         int p = 1, lambda = 1;
//         ListNode *tort = head, *hare = head->next;
//         while (tort != hare){
//             if (p == lambda){
//                 tort = hare;
//                 p <<= 1;
//                 lambda = 0;
//             }
//             hare = hare->next;
//             if (hare == nullptr){
//                 return false;
//             }
//             ++lambda;
//         }
//         return true;
//     }
// };
