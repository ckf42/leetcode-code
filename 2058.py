class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        firstCrit = None
        lastCrit = None
        minDist = int(10 ** 5) + 1
        ptr = head.next
        prevVal = head.val
        i = 1
        while ptr.next is not None:
            if (ptr.val > prevVal and ptr.val > ptr.next.val) or (ptr.val < prevVal and ptr.val < ptr.next.val):
                if firstCrit is None:
                    firstCrit = i
                if lastCrit is not None:
                    minDist = min(minDist, i - lastCrit)
                lastCrit = i
            prevVal = ptr.val
            i += 1
            ptr = ptr.next
        if firstCrit is None or firstCrit == lastCrit:
            return [-1, -1]
        else:
            return [minDist, lastCrit - firstCrit]
