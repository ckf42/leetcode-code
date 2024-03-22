/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct Solution {
    bool isPalindrome(ListNode* head) {
        ListNode *tort = head, *hare = head, *prev = nullptr, *temp;
        while (hare != nullptr && hare->next != nullptr){
            hare = hare->next->next;
            temp = tort;
            tort = temp->next;
            temp->next = prev;
            prev = temp;
        }
        if (hare != nullptr){
            tort = tort->next;
        }
        while (prev != nullptr && prev->val == tort->val){
            prev = prev->next;
            tort = tort->next;
        }
        return prev == nullptr;
    }
};
