# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        tort, hare = head, head
        prev = None
        while hare is not None and hare.next is not None:
            hare = hare.next.next
            prev, tort.next, tort = tort, prev, tort.next
        if hare is not None:
            tort = tort.next
        while prev is not None and prev.val == tort.val:
            prev = prev.next
            tort = tort.next
        return prev is None
