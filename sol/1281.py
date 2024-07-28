from functools import reduce

class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        digits = tuple(int(x) for x in str(n))
        return reduce(lambda x, y: x * y, digits) - sum(digits)

