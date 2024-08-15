import heapq as hq

class Solution:
    def minRefuelStops(self, target: int, startFuel: int, stations: List[List[int]]) -> int:
        n = len(stations)
        if startFuel >= target:
            return 0
        h = []
        maxReach = startFuel
        maxIdx = 0
        for k in range(1, n + 1):
            while maxIdx < n and stations[maxIdx][0] <= maxReach:
                hq.heappush(h, -stations[maxIdx][1])
                maxIdx += 1
            if len(h) == 0:
                return -1
            maxReach -= hq.heappop(h)
            if maxReach >= target:
                return k
        return -1

