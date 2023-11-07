class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
        n = len(dist)
        arrivalTime = list(dist[i] / speed[i] for i in range(n))
        arrivalTime.sort()
        for i, t in enumerate(arrivalTime):
            if t <= i:
                return i
        return n
