import heapq as hq

class Solution:
    def maxFreeTime(self, eventTime: int, startTime: List[int], endTime: List[int]) -> int:
        n = len(startTime)
        gaps = []
        prev = 0
        h = []
        for i, a, b in zip(range(n), startTime, endTime):
            g = a - prev
            gaps.append(g)
            hq.heappush(h, (g, i))
            if len(h) > 3:
                hq.heappop(h)
            prev = b
        gaps.append(eventTime - prev)
        hq.heappush(h, (eventTime - prev, n))
        if len(h) > 3:
            hq.heappop(h)
        res = max(gaps[i] + gaps[i + 1] for i in range(n))
        h.sort()
        for i in range(n):
            blkLen = endTime[i] - startTime[i]
            if any(mg >= blkLen and i not in (idx, idx - 1) for mg, idx in h):
                res = max(res, gaps[i] + gaps[i + 1] + blkLen)
        return res
