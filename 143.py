# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        tort, hare, left = head, head, None
        while hare is not None and hare.next is not None:
            hare = hare.next.next
            left = tort
            tort = tort.next
        if hare is not None:
            left = tort
            tort = tort.next
        left.next = None
        left = None
        right = None
        while tort is not None:
            right = tort.next
            tort.next = left
            left = tort
            tort = right
        tort = head
        while left is not None:
            right = tort.next
            hare = left.next
            tort.next = left
            left.next = right
            tort = right
            left = hare

