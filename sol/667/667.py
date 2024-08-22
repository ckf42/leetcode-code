class Solution:
    def constructArray(self, n: int, k: int) -> List[int]:
        if k == 1:
            return list(range(1, n + 1))
        res = [0] * n
        l = (k + 1) >> 1
        if k & 1:
            for i in range(l):
                res[i * 2] = k + 1 - i
                res[i * 2 + 1] = i + 1
        else:
            for i in range(l):
                res[i * 2] = i + 1
                res[k - i * 2 - 1] = i + l + 2
            res[k] = l + 1
        for i in range(k + 1, n):
            res[i] = i + 1
        return res

