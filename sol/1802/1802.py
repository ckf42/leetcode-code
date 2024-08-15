class Solution:
    @staticmethod
    def partSum(m, l):
        k = min(m, l)
        return (m * 2 - k + 1) * k // 2 + l - k

    def maxValue(self, n: int, index: int, maxSum: int) -> int:
        l = 1
        r = maxSum + 1
        while l < r:
            m = (l + r) // 2
            if self.partSum(m, index + 1) + self.partSum(m, n - index) - m <= maxSum:
                l = m + 1
            else:
                r = m
        return r - 1
