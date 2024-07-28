class Solution:
    def alternateDigitSum(self, n: int) -> int:
        return sum(int(c) * (-1 if i & 1 else 1) for i, c in enumerate(str(n)))
