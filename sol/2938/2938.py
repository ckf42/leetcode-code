class Solution:
    def minimumSteps(self, s: str) -> int:
        bCount = 0
        res = 0
        for c in s:
            if c == '1':
                bCount += 1
            else:
                res += bCount
        return res
