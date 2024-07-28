class Solution:
    def maxDepth(self, s: str) -> int:
        d = 0
        res = 0
        for c in s:
            if c == '(':
                d += 1
                res = max(res, d)
            elif c == ')':
                d -= 1
        return res
