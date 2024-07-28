class Solution:
    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return None
        head.next = self.removeNodes(head.next)
        if head.next is not None and head.val < head.next.val:
            return head.next
        else:
            return head
