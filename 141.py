class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if head is None or head.next is None:
            return False
        tort = head
        rabb = head.next
        while True:
            if tort == rabb:
                return True
            if rabb.next is None:
                return False
            rabb = rabb.next
            if rabb.next is None:
                return False
            rabb = rabb.next
            tort = tort.next
