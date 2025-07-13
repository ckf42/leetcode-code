class Solution:
    def maxFreeTime(self, eventTime: int, k: int, startTime: List[int], endTime: List[int]) -> int:
        intervals = []
        prev = 0
        for a, b in zip(startTime, endTime):
            intervals.append(a - prev)
            prev = b
        intervals.append(eventTime - prev)
        m = len(intervals)
        winSum = sum(intervals[:k + 1])
        res = winSum
        for i in range(k + 1, m):
            winSum += intervals[i] - intervals[i - k - 1]
            res = max(res, winSum)
        return res
