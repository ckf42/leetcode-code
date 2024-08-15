class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        maxi, maxj = 0, 0
        for c in range(n):
            i, j = c, c
            while i >= 0 and j < n and s[i] == s[j]:
                i -= 1
                j += 1
            if maxj - maxi < j - i - 2:
                maxi, maxj = i + 1, j - 1
            i, j = c, c + 1
            while i >= 0 and j < n and s[i] == s[j]:
                i -= 1
                j += 1
            if maxj - maxi < j - i - 2:
                maxi, maxj = i + 1, j - 1
        return s[maxi:maxj + 1]

