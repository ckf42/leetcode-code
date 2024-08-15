import heapq as hq

class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        n = len(profits)
        indices = sorted(range(n), key=lambda i: capital[i])
        ptr = 0
        h = []
        for _ in range(k):
            while ptr < n and capital[indices[ptr]] <= w:
                hq.heappush(h, -profits[indices[ptr]])
                ptr += 1
            if len(h) == 0:
                break
            w -= hq.heappop(h)
        return w
