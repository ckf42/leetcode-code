from math import gcd

class Solution:
    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = head
        ptr = head.next
        while ptr is not None:
            prev.next = ListNode(gcd(prev.val, ptr.val), ptr)
            prev = ptr
            ptr = ptr.next
        return head
