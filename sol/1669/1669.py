# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        ptr = list1
        for _ in range(a - 1):
            ptr = ptr.next
        pre = ptr
        for _ in range(b - a + 2):
            ptr = ptr.next
        post = ptr
        pre.next = list2
        ptr = list2
        while ptr.next is not None:
            ptr = ptr.next
        ptr.next = post
        return list1
