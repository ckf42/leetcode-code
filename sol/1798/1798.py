class Solution:
    def getMaximumConsecutive(self, coins: List[int]) -> int:
        coins.sort()
        reach = 1
        for x in coins:
            if x > reach:
                return reach
            reach += x
        return reach
