from functools import cache

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        n = len(s)
        occurIdx = [[] for _ in range(26)]
        for i, c in enumerate(s):
            occurIdx[ord(c) - ord('a')].append(i)
        prevOccur = [-1] * n
        for i in range(26):
            for j in range(1, len(occurIdx[i])):
                prevOccur[occurIdx[i][j]] = occurIdx[i][j - 1]
        memo = [[] for _ in range(n)]
        memo[0] = [[s[0]]]

        @cache
        def isPal(i, j):
            if i >= j:
                return True
            else:
                return s[i] == s[j] and isPal(i + 1, j - 1)

        for i in range(1, n):
            ptr = i
            while ptr != -1:
                if isPal(ptr, i):
                    if ptr == 0:
                        memo[i].append([s[:i + 1]])
                    else:
                        for part in memo[ptr - 1]:
                            memo[i].append(part + [s[ptr:i + 1]])
                ptr = prevOccur[ptr]
        return memo[n - 1]
