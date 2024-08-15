class Solution:
    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head.val >= 5:
            head = ListNode(0, head)
        head.val *= 2
        prev = head
        ptr = head.next
        while ptr is not None:
            ptr.val *= 2
            if ptr.val >= 10:
                prev.val += 1
                ptr.val -= 10
            prev, ptr = ptr, ptr.next
        return head
