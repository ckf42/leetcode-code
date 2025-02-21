class Solution:
    CHARS = 'abc'
    def getHappyString(self, n: int, k: int) -> str:
        l = 1 << (n - 1)
        if 3 * l < k:
            return ''
        res = ''
        q, k = divmod(k - 1, l)
        res += self.CHARS[q]
        l >>= 1
        for i in range(n - 1):
            if k & l:
                q = 1 if q == 2 else 2
            else:
                q = 1 if q == 0 else 0
            res += self.CHARS[q]
            l >>= 1
        return res
