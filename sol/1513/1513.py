class Solution:
    def numSub(self, s: str) -> int:
        m = 10 ** 9 + 7
        res = 0
        count = 0
        for c in s:
            if c == '1':
                count += 1
            else:
                res = (res + count * (count + 1) // 2) % m
                count = 0
        res = (res + count * (count + 1) // 2) % m
        return res
