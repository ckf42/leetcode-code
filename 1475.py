class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        res = list()
        firstSmallIdxAfter = [0] * len(prices)
        res.append(prices[-1])
        firstSmallIdxAfter[-1] = len(prices)
        for i in range(len(prices) - 2, -1, -1):
            ptr = i + 1
            while ptr < len(prices) and prices[i] < prices[ptr]:
                ptr = firstSmallIdxAfter[ptr]
            firstSmallIdxAfter[i] = ptr
            if ptr != len(prices):
                res.append(prices[i] - prices[firstSmallIdxAfter[i]])
            else:
                res.append(prices[i])
        return res[::-1]
