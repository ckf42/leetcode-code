#include <unordered_set>

struct Solution {
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> targets(nums.begin(), nums.end());
        ListNode foo(-1, head);
        ListNode *prev = &foo, *ptr = head;
        while (ptr != nullptr){
            if (targets.contains(ptr->val)){
                ptr = ptr->next;
                prev->next = ptr;
            } else {
                prev = ptr;
                ptr = ptr->next;
            }
        }
        return foo.next;
    }
};
