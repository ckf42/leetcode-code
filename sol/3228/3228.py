class Solution:
    def maxOperations(self, s: str) -> int:
        res = 0
        count = 0
        total = 0
        prev = ' '
        for x in s:
            if x != prev:
                if prev == '1':
                    total += count
                    res += total
                count = 0
                prev = x
            if x == '1':
                count += 1
        return res
