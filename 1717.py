class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        z = max(x, y)
        zz = min(x, y)
        preChar = 'a' if x >= y else 'b'
        res = 0
        preCount = 0
        postCount = 0
        for c in s:
            if c != 'a' and c != 'b':
                res += min(preCount, postCount) * zz
                preCount = 0
                postCount = 0
            elif c == preChar:
                preCount += 1
            elif preCount != 0:
                preCount -= 1
                res += z
            else:
                postCount += 1
        res += min(preCount, postCount) * zz
        return res
