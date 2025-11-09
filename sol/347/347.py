import heapq as hq

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = dict()
        for x in nums:
            freq[x] = freq.get(x, 0) + 1
        h = []
        for x, f in freq.items():
            hq.heappush(h, (f, x))
            if len(h) > k:
                hq.heappop(h)
        return [x for f, x in h]

