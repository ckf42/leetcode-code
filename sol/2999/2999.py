from functools import cache

class Solution:
    @cache
    def dp(self, upperBound: str, limit: int, idx: int, startIdx: int, withinBound: bool) -> int:
        if idx == len(upperBound):
            return 1
        res = 0
        if startIdx == -1:
            res += self.dp(upperBound, limit, idx + 1, -1, True)
        a = 1 if startIdx == -1 else 0
        if startIdx == -1:
            startIdx = idx
        ubDigit = int(upperBound[idx])
        b = limit if withinBound else min(limit, ubDigit)
        for digit in range(a, b + 1):
            res += self.dp(
                upperBound,
                limit,
                idx + 1,
                startIdx,
                withinBound or digit < ubDigit
            )
        return res

    def numberOfPowerfulInt(self, start: int, finish: int, limit: int, s: str) -> int:
        mask = 10 ** len(s)
        sint = int(s)
        if start % mask > sint:
            start += mask
        start //= mask
        if finish % mask < sint:
            finish -= mask
        finish //= mask
        if finish < start:
            return 0
        print(start, finish)
        return self.dp(str(finish), limit, 0, -1, False) - (0 if start == 0 else self.dp(str(start - 1), limit, 0, -1, False))
