class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        n = len(events)
        events.sort(key=lambda e: e[0])
        maxVal = [(events[n - 1][0], events[n - 1][2])]
        for i in range(n - 2, -1, -1):
            if events[i][2] > maxVal[-1][1]:
                maxVal.append((events[i][0], events[i][2]))
        events.sort(key=lambda e: e[1])
        ptr = len(maxVal) - 1
        res = 0
        for e in events:
            res = max(res, e[2])
            while ptr >= 0 and maxVal[ptr][0] <= e[1]:
                ptr -= 1
            if ptr >= 0:
                res = max(res, e[2] + maxVal[ptr][1])
        return res
