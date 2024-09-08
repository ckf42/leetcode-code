class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        ptr = head
        l = 0
        while ptr is not None:
            ptr = ptr.next
            l += 1
        q, r = divmod(l, k)
        res = [None for _ in range(k)]
        for i in range(r):
            if head is None:
                continue
            res[i] = head
            ptr = head
            head = head.next
            for _ in range(q):
                ptr.next = head
                ptr = head
                head = head.next
            ptr.next = None
        for i in range(r, k):
            if head is None:
                continue
            res[i] = head
            ptr = head
            head = head.next
            for _ in range(q - 1):
                ptr.next = head
                ptr = head
                head = head.next
            ptr.next = None
        return res
