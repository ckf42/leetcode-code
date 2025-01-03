class Solution:
    def maxScore(self, s: str) -> int:
        n = len(s)
        res = -1
        z = 0
        for i in range(n - 1):
            z += s[i] == '0'
            res = max(res, z * 2 - i - 1)
        return res + n - z - (s[n - 1] == '0')
