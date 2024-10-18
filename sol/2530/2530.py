import heapq as hq

class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        h = [-x for x in nums]
        hq.heapify(h)
        score = 0
        for _ in range(k):
            v = hq.heappop(h)
            score -= v
            hq.heappush(h, -((-v + 2) // 3))
        return score
