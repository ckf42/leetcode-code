# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        h = list()
        for l in lists:
            ptr = l
            while ptr is not None:
                h.append(ptr.val)
                ptr = ptr.next
        h.sort()
        head = ListNode()
        ptr = head
        for i in h:
            ptr.next = ListNode(i)
            ptr = ptr.next
        return head.next
