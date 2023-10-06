class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        collected = [False] * k
        collectedCount = 0
        for i, n in enumerate(nums[::-1]):
            if 1 <= n <= k and not collected[n - 1]:
                collected[n - 1] = True
                collectedCount += 1
                if collectedCount == k:
                    return i + 1
