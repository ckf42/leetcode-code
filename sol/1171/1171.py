# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeZeroSumSublists(self, head: Optional[ListNode]) -> Optional[ListNode]:
        removed = True
        while removed:
            removed = False
            foobar = ListNode(0, head)
            d = {0: foobar}
            ptr = head
            s = 0
            while ptr is not None:
                s += ptr.val
                if s in d:
                    d[s].next = ptr.next
                    removed = True
                d[s] = ptr
                ptr = ptr.next
            head = foobar.next
        return head
