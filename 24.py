class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        foo = ListNode(0, head)
        p0 = foo
        while p0.next is not None:
            p1 = p0.next
            if p1.next is None:
                break
            p2 = p1.next
            p3 = p2.next
            p0.next = p2
            p2.next = p1
            p1.next = p3
            p0 = p1
        return foo.next
