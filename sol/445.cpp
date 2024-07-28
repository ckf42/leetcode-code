#include <stack>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> *stack1 = new stack<int>(), *stack2 = new stack<int>();
        ListNode *ptr = l1;
        while (ptr != nullptr){
            stack1->push(ptr->val);
            ptr = ptr->next;
        }
        ptr = l2;
        while (ptr != nullptr){
            stack2->push(ptr->val);
            ptr = ptr->next;
        }
        ptr = nullptr;
        bool carry = false;
        int v;
        while (!stack1->empty() && !stack2->empty()){
            v = stack1->top() + stack2->top() + (carry ? 1 : 0);
            stack1->pop(); stack2->pop();
            if (v >= 10){
                carry = true;
                v -= 10;
            } else {
                carry = false;
            }
            ptr = new ListNode(v, ptr);
        }
        if (stack1->empty()){
            swap(stack1, stack2);
        }
        while (!stack1->empty()){
            v = stack1->top() + (carry ? 1 : 0);
            stack1->pop();
            if (v >= 10){
                carry = true;
                v -= 10;
            } else {
                carry = false;
            }
            ptr = new ListNode(v, ptr);
        }
        if (carry){
            ptr = new ListNode(1, ptr);
        }
        return ptr;
    }
};
