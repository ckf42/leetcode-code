class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        n = len(timePoints)
        tps = sorted(int(t[:2]) * 60 + int(t[3:]) for t in timePoints)
        res = tps[0] - tps[n - 1] + 1440
        for i in range(n - 1):
            res = min(res, tps[i + 1] - tps[i])
        return res
