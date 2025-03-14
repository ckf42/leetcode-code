class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        indices = [-1] * 3
        res = 0
        for i, c in enumerate(s):
            indices[ord(c) - ord('a')] = i
            res += min(indices) + 1
        return res
