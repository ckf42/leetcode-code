# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        foo = ListNode(0, head)
        p, q = foo, foo
        for _ in range(n + 1):
            q = q.next
        while q is not None:
            p = p.next
            q = q.next
        p.next = p.next.next
        return foo.next
