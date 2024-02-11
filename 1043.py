class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        memo = [0] * (len(arr) + 1)
        memo[0] = arr[0]
        for i in range(1, len(arr)):
            maxEle = 0
            for s in range(i, max(i - k + 1, 0) - 1, -1):
                maxEle = max(maxEle, arr[s])
                memo[i] = max(memo[i], memo[s - 1] + (i - s + 1) * maxEle)
        return memo[-2]
