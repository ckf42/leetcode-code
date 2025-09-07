class Solution:
    POWERS = [4 ** i for i in range(16)]
    def minOperations(self, queries: List[List[int]]) -> int:
        res = 0
        for l, r in queries:
            count = 0
            for i in range(15):
                a, b = self.POWERS[i], self.POWERS[i + 1]
                if b <= l:
                    continue
                if a > r:
                    break
                x = max(a, l)
                y = min(b - 1, r)
                count += (y - x + 1) * (i + 1)
            res += (count + 1) // 2
        return res
