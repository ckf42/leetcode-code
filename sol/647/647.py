class Solution:
    def countSubstrings(self, s: str) -> int:
        n = len(s)
        res = 0
        for c in range(n):
            i, j = c, c
            while i >= 0 and j < n and s[i] == s[j]:
                res += 1
                i -= 1
                j += 1
            i, j = c, c + 1
            while i >= 0 and j < n and s[i] == s[j]:
                res += 1
                i -= 1
                j += 1
        return res
