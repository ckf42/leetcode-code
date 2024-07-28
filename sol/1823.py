class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        res = 1
        for i in range(2, n + 1):
            res += k - 1
            res %= i
            res += 1
        return res
