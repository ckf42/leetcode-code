class Solution:
    def maxScore(self, s: str) -> int:
        zeroCount = 0
        maxRate = -len(s)
        for i in range(len(s) - 1):
            if s[i] == '0':
                zeroCount += 1
            maxRate = max(maxRate, zeroCount * 2 - i)
        return maxRate + len(s) - 1 - zeroCount - (1 if s[-1] == '0' else 0)
