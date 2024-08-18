class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        res = 0
        n = len(prices)
        b = prices[0]
        for i in range(1, n):
            if prices[i] < b:
                b = prices[i]
            else:
                res = max(res, prices[i] - b)
        return res
