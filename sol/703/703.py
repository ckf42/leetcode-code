import heapq as hq

class KthLargest:
    def __init__(self, k: int, nums: List[int]):
        self.k = k
        self.q = nums
        hq.heapify(self.q)
        while len(self.q) > k:
            hq.heappop(self.q)

    def add(self, val: int) -> int:
        hq.heappush(self.q, val)
        while len(self.q) > self.k:
            hq.heappop(self.q)
        return self.q[0]


