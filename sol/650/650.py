class Solution:
    def minSteps(self, n: int) -> int:
        if n == 1:
            return 0
        count = 1
        buff = 0
        res = 0
        while count < n:
            buff = count
            count *= 2
            res += 2
            while n % count != 0:
                count += buff
                res += 1
        return res
