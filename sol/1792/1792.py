import heapq as hq

class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        n = len(classes)
        h = [(a / b - (a + 1) / (b + 1), a, b) for a, b in classes]
        hq.heapify(h)
        for _ in range(extraStudents):
            _, a, b = hq.heappop(h)
            a += 1
            b += 1
            hq.heappush(h, (a / b - (a + 1) / (b + 1), a, b))
        return sum(a / b for _, a, b in h) / n
