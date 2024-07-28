from functools import cache

class Solution:
    def checkPartitioning(self, s: str) -> bool:
        @cache
        def isPal(i, j):
            if i >= j:
                return True
            return s[i] == s[j] and isPal(i + 1, j - 1)
        n = len(s)
        b = tuple(i for i in range(n) if isPal(0, i))
        e = tuple(i for i in range(n) if isPal(i, n - 1))
        return any(isPal(i + 1, j - 1) for i in b for j in e if i <= j - 2)
