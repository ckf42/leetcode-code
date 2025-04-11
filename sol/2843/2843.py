from functools import cache

class Solution:
    @cache
    def dp(
            self,
            upperBound: str,
            idx: int,
            startIdx: int,
            mustBeWithinBound: bool,
            diff: int
            ) -> int:
        if idx == len(upperBound):
            # is zero or has nonzero diff, does not count
            return 0 if startIdx == -1 or diff != 0 else 1
        res = 0
        if startIdx == -1:
            # only has leading zero, more leading zero
            res += self.dp(upperBound, idx + 1, -1, True, 0)
            if ((len(upperBound) ^ idx) & 1) == 1:
                # starting at idx yields an odd len number
                return res
        a = 1 if startIdx == -1 else 0
        if startIdx == -1:
            startIdx = idx
        isInFirstHalf = idx < startIdx + (len(upperBound) - startIdx) // 2
        ubDigit = int(upperBound[idx])
        b = 9 if mustBeWithinBound else ubDigit
        for digit in range(a, b + 1):
            res += self.dp(
                upperBound,
                idx + 1,
                startIdx,
                mustBeWithinBound or digit < ubDigit,
                diff + (digit if isInFirstHalf else -digit)
            )
        return res
    def countSymmetricIntegers(self, low: int, high: int) -> int:
        return self.dp(str(high), 0, -1, False, 0) - self.dp(str(low - 1), 0, -1, False, 0)
