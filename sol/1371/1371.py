class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        idx = [-2] * 32
        mask = 0
        res = 0
        idx[0] = -1
        for i, c in enumerate(s):
            if c in 'aeiou':
                mask ^= 1 << 'aeiou'.index(c)
            if idx[mask] == -2:
                idx[mask] = i
            else:
                res = max(res, i - idx[mask])
        return res
