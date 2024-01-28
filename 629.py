class Solution:
    def kInversePairs(self, n: int, k: int) -> int:
        if k == 0 or k == n * (n - 1) // 2:
            return 1
        if k > n * (n - 1) // 2:
            return 0
        M: int = int(1e9) + 7
        memo = [[0] * (k + 1) for _ in (0, 1)]
        ptr = 0
        memo[0][0] = 1
        memo[1][0] = 1
        for i in range(2, n + 1):
            for j in range(1, k + 1):
                memo[1 - ptr][j] = (memo[1 - ptr][j - 1] + memo[ptr][j] - (memo[ptr][j - i] if j >= i else 0)) % M
            ptr = 1 - ptr
        return memo[ptr][-1]

