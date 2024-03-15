class Solution:
    def pivotInteger(self, n: int) -> int:
        s = n * (n + 1) // 2
        x = s
        y = 1
        while x > y:
            x += y
            x //= 2
            y = s // x
        if x * x == s:
            return x
        else:
            return -1
