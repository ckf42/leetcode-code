import heapq as hq

class MedianFinder:
    def __init__(self):
        self.n = 0
        self.small = []
        self.large = []

    def addNum(self, num: int) -> None:
        self.n += 1
        if self.n & 1:
            hq.heappush(self.large, -hq.heappushpop(self.small, -num))
        else:
            hq.heappush(self.small, -hq.heappushpop(self.large, num))

    def findMedian(self) -> float:
        if self.n & 1:
            return self.large[0]
        else:
            return (-self.small[0] + self.large[0]) / 2

