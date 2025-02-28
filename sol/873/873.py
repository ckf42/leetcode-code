class Solution:
    def lenLongestFibSubseq(self, arr: List[int]) -> int:
        n = len(arr)
        h = {x: i for i, x in enumerate(arr)}
        memo = [[2] * n for _ in range(n)]
        res = 2
        for k in range(2, n):
            for j in range(1, k):
                val = arr[k] - arr[j]
                if val < arr[j] and val in h:
                    memo[j][k] = memo[h[val]][j] + 1
                    res = max(res, memo[j][k])
        return res if res != 2 else 0

