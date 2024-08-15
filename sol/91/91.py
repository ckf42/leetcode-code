class Solution:
    def numDecodings(self, s: str) -> int:
        if s[0] == '0':
            return 0
        memo = [0] * (len(s) + 1)  # [0, e)
        memo[0] = 1
        memo[1] = 1
        for i in range(2, len(s) + 1):
            if s[i - 1] != '0':
                memo[i] += memo[i - 1]
            if s[i - 2] == '1' or (s[i - 2] == '2' and s[i - 1] in '0123456'):
                memo[i] += memo[i - 2]
        return memo[-1]
