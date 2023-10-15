# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        ptr1 = l1
        ptr2 = l2
        carry = False
        ptr1.val += ptr2.val
        if ptr1.val >= 10:
            carry = True
            ptr1.val -= 10
        while ptr1.next is not None and ptr2.next is not None:
            ptr1 = ptr1.next
            ptr2 = ptr2.next
            ptr1.val += ptr2.val + (1 if carry else 0)
            carry = False
            if ptr1.val >= 10:
                carry = True
                ptr1.val -= 10
        if ptr1.next is None:
            ptr1.next = ptr2.next
        while carry:
            if ptr1.next is None:
                ptr1.next = ListNode(0, None)
            ptr1 = ptr1.next
            ptr1.val += 1
            carry = False
            if ptr1.val >= 10:
                carry = True
                ptr1.val -= 10
        return l1
