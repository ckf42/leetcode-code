import heapq as hq
from collections import deque

class Solution:
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
        h = []
        lvl = deque((root,))
        while (n := len(lvl)) != 0:
            accum = 0
            for _ in range(n):
                ptr = lvl.popleft()
                accum += ptr.val
                if ptr.left is not None:
                    lvl.append(ptr.left)
                if ptr.right is not None:
                    lvl.append(ptr.right)
            if len(h) < k:
                hq.heappush(h, accum)
            else:
                hq.heappushpop(h, accum)
        return h[0] if len(h) >= k else -1
