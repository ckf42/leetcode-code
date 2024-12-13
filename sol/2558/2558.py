import heapq as hq

class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        h = [-x for x in gifts]
        hq.heapify(h)
        while len(h) != 0 and k > 0:
            k -= 1
            x = -hq.heappop(h)
            hq.heappush(h, -int(x ** 0.5))
        return -sum(h)
