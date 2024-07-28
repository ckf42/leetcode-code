class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        res = 0
        for i in range(n - 1):
            res += max(0, prices[i + 1] - prices[i])
        return res
