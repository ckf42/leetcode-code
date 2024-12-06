class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        res = 0
        currSum = 0
        banned = frozenset(banned)
        for i in range(1, n + 1):
            if i in banned:
                continue
            if currSum + i > maxSum:
                break
            currSum += i
            res += 1
        return res
