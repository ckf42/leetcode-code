class Solution:
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        window = sum(nums[:k])
        windowSums = [window]
        for e in range(k, n):
            window += nums[e] - nums[e - k]
            windowSums.append(window)
        m = len(windowSums)
        leftIdx = [0] * m  # [0:i]
        rightIdx = [m - 1] * m  # [i:m - 1]
        for i in range(1, m):
            leftIdx[i] = i if windowSums[i] > windowSums[leftIdx[i - 1]] else leftIdx[i - 1]
            rightIdx[m - 1 - i] = m - 1 - i if windowSums[m - 1 - i] >= windowSums[rightIdx[m - i]] else rightIdx[m - i]
        optSum = -1
        optIndices = []
        for midIdx in range(k, m - k):
            s = windowSums[leftIdx[midIdx - k]] + windowSums[midIdx] + windowSums[rightIdx[midIdx + k]]
            if s > optSum:
                optSum = s
                optIndices = [leftIdx[midIdx - k], midIdx, rightIdx[midIdx + k]]
        return optIndices
