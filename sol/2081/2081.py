class Solution:
    def kMirror(self, k: int, n: int) -> int:
        def isKMirror(x: int) -> bool:
            if x < k:
                return True
            digits = []
            while x != 0:
                x, r = divmod(x, k)
                digits.append(r)
            l = len(digits)
            return all(digits[i] == digits[l - 1 - i] for i in range(l // 2))
        res = 0
        l = 1
        while n != 0:
            for part in range(10 ** (l - 1), 10 ** l):
                si = str(part)
                x = int(si + si[-2::-1])
                if isKMirror(x):
                    res += x
                    n -= 1
                if n == 0:
                    return res
            for part in range(10 ** (l - 1), 10 ** l):
                si = str(part)
                x = int(si + si[::-1])
                if isKMirror(x):
                    res += x
                    n -= 1
                if n == 0:
                    return res
            l += 1
        return res  # should not reach
