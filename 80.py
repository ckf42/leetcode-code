class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        occCount = 0
        lastOcc = nums[0] - 1
        n = len(nums)
        w = 0
        for i, x in enumerate(nums):
            if x == lastOcc:
                occCount += 1
            else:
                occCount = 1
            lastOcc = x
            if occCount <= 2:
                nums[w] = x
                w += 1
        return w
