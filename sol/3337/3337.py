class Solution:
    M = 10 ** 9 + 7
    @classmethod
    def matmul(cls, x, y):
        return [
            [
                sum(x[i][k] * y[k][j] for k in range(26)) % cls.M
                for j in range(26)
            ]
            for i in range(26)
        ]
    @classmethod
    def power(cls, x, n):
        y = [[1 if i == j else 0 for j in range(26)] for i in range(26)]
        while n != 1:
            if n & 1:
                y = cls.matmul(x, y)
            x = cls.matmul(x, x)
            n >>= 1
        return cls.matmul(x, y)
    def lengthAfterTransformations(self, s: str, t: int, nums: List[int]) -> int:
        b = [[0] * 26 for _ in range(26)]
        for i, c in enumerate(nums):
            for j in range(c):
                b[i][(i + j + 1) % 26] = 1
        b = self.power(b, t)
        freq = [0] * 26
        for c in s:
            freq[ord(c) - ord('a')] += 1
        return sum(freq[i] * b[i][j] for i in range(26) for j in range(26)) % self.M
