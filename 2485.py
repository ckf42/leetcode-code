class Solution:
    def pivotInteger(self, n: int) -> int:
        s = n * (n + 1) / 2
        t = int(s ** 0.5)
        if t ** 2 == s:
            return t
        else:
            return -1
