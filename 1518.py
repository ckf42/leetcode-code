class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        res = 0
        buff = 0
        while numBottles > 0:
            res += numBottles
            numBottles, buff = divmod(numBottles + buff, numExchange)
        return res
