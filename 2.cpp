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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ptr1 = l1, *ptr2 = l2;
        bool carry = false;
        ptr1->val += ptr2->val;
        if (ptr1->val >= 10){
            ptr1->val -= 10;
            carry = true;
        }
        while (ptr1->next != nullptr && ptr2->next != nullptr){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            ptr1->val += ptr2->val + (carry ? 1 : 0);
            carry = false;
            if (ptr1->val >= 10){
                carry = true;
                ptr1->val -= 10;
            }
        }
        if (ptr1->next == nullptr){
            ptr1->next = ptr2->next;
        }
        while (carry){
            if (ptr1->next == nullptr){
                ptr1->next = new ListNode(0, nullptr);
            }
            ptr1 = ptr1->next;
            ++ptr1->val;
            carry = false;
            if (ptr1->val >= 10){
                carry = true;
                ptr1->val -= 10;
            }
        }
        return l1;
    }
};
