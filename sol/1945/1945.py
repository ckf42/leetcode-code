class Solution:
    def getLucky(self, s: str, k: int) -> int:
        res = 0
        for c in s:
            cn = ord(c) - 96
            q, r = divmod(cn, 10)
            res += q + r
        for _ in range(k - 1):
            temp = 0
            while res != 0:
                res, r = divmod(res, 10)
                temp += r
            res = temp
        return res
