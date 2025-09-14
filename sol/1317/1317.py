class Solution:
    IS_NO_ZERO = dict()

    def is_no_zero(self, x):
        if x not in self.IS_NO_ZERO:
            res = True
            y = x
            while y != 0:
                y, r = divmod(y, 10)
                if r == 0:
                    res = False
                    break
            self.IS_NO_ZERO[x] = res
        return self.IS_NO_ZERO[x]

    def getNoZeroIntegers(self, n: int) -> List[int]:
        for a in range(1, n // 2 + 1):
            b = n - a
            if self.is_no_zero(a) and self.is_no_zero(b):
                return [a, b]
        return []
