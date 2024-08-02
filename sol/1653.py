class Solution:
    def minimumDeletions(self, s: str) -> int:
        res = 0
        b = 0
        for c in s:
            if c == 'b':
                b += 1
            elif b != 0:
                b -= 1
                res += 1
        return res
