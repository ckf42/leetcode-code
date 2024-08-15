class Solution:
    def partitionString(self, s: str) -> int:
        res = 1
        counter = 0
        for c in s:
            m = 1 << (ord(c) - ord('a'))
            if (counter & m) != 0:
                res += 1
                counter = 0
            counter |= m
        return res
