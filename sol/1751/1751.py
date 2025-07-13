import heapq as hq

class Solution:
    def maxValue(self, events: List[List[int]], k: int) -> int:
        events.sort(key=lambda itv: itv[1])
        n = len(events)
        prevAttendable = [-1] * n
        h = []
        for i in range(n):
            hq.heappush(h, (events[i][0], i))
        ptr = -1
        for _ in range(n):
            start, idx = hq.heappop(h)
            while ptr + 1 < n and events[ptr + 1][1] < start:
                ptr += 1
            prevAttendable[idx] = ptr
        memo = [[0] * (n + 1) for _ in range(2)]
        wptr = 1
        for allowance in range(1, k + 1):
            for eventLen in range(1, n + 1):
                memo[wptr][eventLen] = max(
                    memo[wptr][eventLen - 1],
                    events[eventLen - 1][2] + memo[1 - wptr][prevAttendable[eventLen - 1] + 1]
                )
            wptr = 1 - wptr
        return memo[1 - wptr][n]
