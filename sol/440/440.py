class Solution:
    def findKthNumber(self, n: int, k: int) -> int:
        val = 1
        k -= 1
        while k != 0:
            subSize = 0
            a = val
            b = val + 1
            while a <= n:
                subSize += min(n + 1, b) - a
                a *= 10
                b *= 10
            if k >= subSize:
                val += 1
                k -= subSize
            else:
                val *= 10
                k -= 1
        return val
