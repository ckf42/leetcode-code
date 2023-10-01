class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if head is None:
            return None
        lst = list() # fine with only <=500 nodes
        ptr = head
        while ptr is not None:
            lst.append(ptr)
            ptr = ptr.next
        k %= len(lst)
        if k == 0:
            return head
        lst[-1].next = lst[0]
        lst[-k - 1].next = None
        return lst[-k]

