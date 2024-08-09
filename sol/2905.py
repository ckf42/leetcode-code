class Solution:
    def findIndices(self, nums: List[int], indexDifference: int, valueDifference: int) -> List[int]:
        n = len(nums)
        maxIdx = 0
        minIdx = 0
        for i in range(n - indexDifference):
            if nums[i] > nums[maxIdx]:
                maxIdx = i
            elif nums[i] < nums[minIdx]:
                minIdx = i
            j = i + indexDifference
            if abs(nums[j] - nums[maxIdx]) >= valueDifference:
                return [maxIdx, j]
            if abs(nums[j] - nums[minIdx]) >= valueDifference:
                return [minIdx, j]
        return [-1, -1]

