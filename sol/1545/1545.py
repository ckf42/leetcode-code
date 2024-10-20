class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        flip = False
        res = ''
        l = (1 << n) - 1
        while True:
            if n == 1:
                res = '0'
                break
            m = (l >> 1) + 1
            if k == m:
                res = '1'
                break
            elif k > m:
                flip = not flip
                k = l - k + 1
            n -= 1
            l = m - 1
        if flip:
            return '0' if res == '1' else '1'
        else:
            return res
