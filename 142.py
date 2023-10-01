class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return None
        tort = head
        rabb = head.next
        while True:
            if tort == rabb:
                break
            if rabb.next is None:
                return None
            rabb = rabb.next
            if rabb.next is None:
                return None
            rabb = rabb.next
            tort = tort.next
        tort = head
        rabb = rabb.next
        while tort != rabb:
            tort = tort.next
            rabb = rabb.next
        return tort

