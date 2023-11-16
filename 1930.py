from bisect import bisect

class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        orda = ord('a')
        indices = list(list() for _ in range(26))
        for i, c in enumerate(s):
            indices[ord(c) - orda].append(i)
        res = 0
        for i in range(26):
            if len(indices[i]) < 2:
                continue
            if len(indices[i]) > 2:
                res += 1
            for j in range(26):
                if i == j:
                    continue
                if bisect(indices[j], indices[i][0]) < bisect(indices[j], indices[i][-1]):
                    res += 1
        return res
