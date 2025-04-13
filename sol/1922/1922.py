class Solution:
    def countGoodNumbers(self, n: int) -> int:
        res = pow(20, n // 2, 10 ** 9 + 7)
        if n % 2 == 1:
            res = (res * 5) % (10 ** 9 + 7)
        return res
