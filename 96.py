class Solution:
    rec = [1, 1]

    def numTrees(self, n: int) -> int:
        while n >= (k := len(self.rec)):
            res = 0
            for i in range(k // 2):
                res += self.rec[i] * self.rec[k - 1 - i]
            res *= 2
            if (k & 1) == 1:
                res += self.rec[(k - 1) // 2] ** 2
            self.rec.append(res)
        return self.rec[n]
