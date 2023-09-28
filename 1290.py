class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        val = 0
        while head is not None:
            val *= 2
            val += head.val
            head = head.next
        return val
