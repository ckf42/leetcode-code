class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        z = max(x, y)
        zz = min(x, y)
        preChar = 'a' if x >= y else 'b'
        def segVal(i, j):
            if i == j:
                return 0
            val = 0
            postCount = 0
            preCount = 0
            for k in range(i, j):
                if s[k] == preChar:
                    preCount += 1
                elif preCount != 0:
                    preCount -= 1
                    val += z
                else:
                    postCount += 1
            return val + min(preCount, postCount) * zz
        res = 0
        i = 0
        for j, c in enumerate(s):
            if c not in 'ab':
                res += segVal(i, j)
                i = j + 1
        if i != len(s):
            res += segVal(i, len(s))
        return res
