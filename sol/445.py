# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        stack1, stack2 = list(), list()
        ptr = l1
        while ptr is not None:
            stack1.append(ptr.val)
            ptr = ptr.next
        ptr = l2
        while ptr is not None:
            stack2.append(ptr.val)
            ptr = ptr.next
        ptr = None
        carry = False
        while len(stack1) != 0 and len(stack2) != 0:
            v = stack1.pop() + stack2.pop() + (1 if carry else 0)
            if v >= 10:
                carry = True
                v -= 10
            else:
                carry = False
            ptr = ListNode(v, ptr)
        if len(stack1) == 0:
            stack1, stack2 = stack2, stack1
        while len(stack1) != 0:
            v = stack1.pop() + (1 if carry else 0)
            if v >= 10:
                carry = True
                v -= 10
            else:
                carry = False
            ptr = ListNode(v, ptr)
        if carry:
            ptr = ListNode(1, ptr)
        return ptr
