class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        n = len(nums)
        nums.sort()
        chainLen = [1] * n
        prevIdx = [-1] * n
        maxLen = 0
        maxIdx = 0
        for i in range(n):
            for j in range(i + 1, n):
                if nums[j] % nums[i] != 0:
                    continue
                if chainLen[j] < chainLen[i] + 1:
                    chainLen[j] = chainLen[i] + 1
                    prevIdx[j] = i
                    if chainLen[j] > maxLen:
                        maxLen = chainLen[j]
                        maxIdx = j
        res = []
        while maxIdx != -1:
            res.append(nums[maxIdx])
            maxIdx = prevIdx[maxIdx]
        return res
