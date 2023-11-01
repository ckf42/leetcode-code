class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        opCount = 0
        while (a | b) != c:
            if c & 1:
                opCount += 1 - ((a | b) & 1)
            else:
                opCount += (a & 1) + (b & 1)
            a >>= 1
            b >>= 1
            c >>= 1
        return opCount
