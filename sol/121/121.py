class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        res = 0
        n = len(prices)
        b = prices[0]
        for i in range(1, n):
            b = min(b, prices[i])
            res = max(res, prices[i] - b)
        return res
