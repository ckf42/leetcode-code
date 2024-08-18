class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        n = len(values)
        opt = values[0] - 1
        res = opt + values[1]
        for i in range(2, n):
            opt = max(opt, values[i - 1]) - 1
            res = max(res, opt + values[i])
        return res
