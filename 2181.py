class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        foo = ListNode(0, head)
        s = foo
        ptr = foo.next
        accum = 0
        while ptr is not None:
            if ptr.val != 0:
                accum += ptr.val
            else:
                ptr.val = accum
                s.next = ptr
                s = ptr
                accum = 0
            ptr = ptr.next
        return foo.next.next
