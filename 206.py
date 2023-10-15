# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head
        left = None
        right = head.next
        while right is not None:
            head.next = left
            left = head
            head = right
            right = right.next
        head.next = left
        return head
