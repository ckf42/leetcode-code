import heapq as hq

class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        events.sort(key=lambda itv: itv[0])
        h = []
        res = 0
        currDay = 1
        ptr = 0
        n = len(events)
        while True:
            if len(h) == 0 and ptr < n:
                currDay = events[ptr][0]
            while ptr < n and events[ptr][0] <= currDay:
                hq.heappush(h, events[ptr][1])
                ptr += 1
            while len(h) != 0 and h[0] < currDay:
                hq.heappop(h)
            if len(h) != 0 and h[0] >= currDay:
                hq.heappop(h)
                res += 1
                currDay += 1
            if ptr == n and len(h) == 0:
                break
        return res
